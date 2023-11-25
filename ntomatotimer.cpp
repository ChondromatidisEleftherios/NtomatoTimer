#include "ntomatotimer.h" //HeaderFile//
#include <iostream>  //Βιβλιοθήκη για cin, cout//
#include <windows.h> //Bιβλιοθήκη που χρησιμοποιήθηκε για Sleep(), cls, system("pause")//
#include <conio.h> //Bιβλιοθήκη που χρησιμοποιήθηκε για το για getch()//
#include <string> //Βιβλιοθήκη για αλφαριθμητικά στη C++//
#include <string.h> //Βιβλιοθήκη για αλφαριθμητικά (πίνακες char)  στη C//
#include <cctype> //Βιβλιοθήκη που χρησιμοποιήθηκε για το isdigit()//
#include <fstream> //Βιβλιοθήκη για δημιουργία και επεξεργασία αρχείων .txt//
#include <math.h>  //Βιβλιοθήκη για μαθηματικούς υπολογισμούς//
#include <iomanip> //Βιβλιοθήκη που χρησιμοποιήθηκε για την αλλαγή χρωμάτων της κονσόλας//
#include <mmsystem.h> //Bιβλιοθήκη που χρησιμοποιήθηκε για αναπαραγωγή του αρχείου ήχου dwd.wav//

#pragma comment (lib, "winmm.lib")

using namespace std;

int ch=0;
int menu ();
void pomodoro::setworkduration(int wd)
{
   workDuration=wd;
}


 void pomodoro::setbreakduration (int bd)
 {
    breakDuration=bd;
 }


 int pomodoro::getworkduration ()
 {
     return workDuration;
 }


  int pomodoro::getbreakduration ()
 {
     return breakDuration;
 }


 //ΜΕΝΟΥ//

 int menu()
{
    HANDLE col= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(col,7);  //Aλλαγή χρώματος κονσόλας//
    char op;
        system("cls");
    cout << "                              ***********************************************************" << endl;
    cout << "                                                    POMODORO TIMER" << endl << endl << endl <<endl;
    cout << "1. Start Timer" << endl << endl;
    cout << "2. Settings" << endl << endl;
    cout << "3. Statistics" << endl << endl;
    cout << "4. Exit Program" << endl << endl;
    cout << "5. Credits" << endl << endl;
    cout << "                              ***********************************************************" << endl;

    op=getch(); //Tο getch() είναι μια συνάρτηση για διάβασμα ΕΝΟΣ ΜΟΝΟ χαρακτήρα//
    switch (op)
    {
    case '1':  //Αν πατήθηκε το "1"//
        return 1; //Η συνάτησει να επιστρέψει τιμή 1//
        break;
    case '2':  //Αν πατήθηκε το "2"//
        return 2; //Η συνάτησει να επιστρέψει τιμή 2//
        break;
    case '3': //Αν πατήθηκε το "3"//
        return 3; //Η συνάτησει να επιστρέψει τιμή 3//
        break;
    case '4': //Αν πατήθηκε το "4"//
        return 0; //Η συνάτησει να επιστρέψει τιμή 4//
        break;
    case '5': //Αν πατήθηκε το "5"//
        return 5; //Η συνάτησει να επιστρέψει τιμή 5//
        break;
    default: //Αν δε πατήθηκε κανένα από τα παραπάνω//
        cout << " "<<endl;
        return 69;   //Η συνάτησει να επιστρέψει τιμή 69//
    }
}

//ΡΥΘΜΙΣΕΙΣ//

   void pomodoro::settings()
    {
        HANDLE col= GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(col,7);
        int key=1, x=0, sizew=0, sizeb=0, correctw, correctb;
        char w[5];     //αρχικοποίηση ενός αλφαριθμητικού w//
        char b[5];   //αρχικοποίηση ενός αλφαριθμητικού b//
        int wd=0, bd=0;
        bool checkw, checkb;  //Λογικές μεταβλητές ελέγχου//
        do{
        x=0;
        checkw=false;
        checkb=false;
        sizew=0;
        sizeb=0;
        wd=0;
        bd=0;
            if (key==0) //αν ο χρήστης εισήγαγε λάθος δεδομένα//
            {
                cout << "Wrong Values, Please Try Again!" << endl << endl;
            }
        cout << "Adjust Work Duration (Default 25)" << endl;
        cin >> w;  //διάβασμα αλφαριθμητικού w//
        sizew=strlen(w);  //Έλεγχος μήκους αλφαριθμητικού w (πόσους χαρακτήρες έχει)//

        cout <<  "Adjust Break Duration (Default 5)" <<endl;
        cin >> b;  //διάβασμα αλφαριθμητικού b//
        sizeb=strlen(b);  //Έλεγχος μήκους αλφαριθμητικού b (πόσους χαρακτήρες έχει)//
        if ((sizew<4)&&(sizeb<4))  //Aν και τα δύο αλφαριθμητικά έχουν λιγότερο απο 4 χαρακτήρες//
        {
            while(x<sizew)
            {
                correctw=isdigit(w[x]);  // Έλεγχος πως όλοι οι χαρακτήρες του αλφαριθμητικου w είναι αριθμοί//
                if (correctw==0)
                {
                    break; //Αν έστω ένας χαρακτήρας δεν είναι  αριθμός, βγές από την επανάληψη//
                }
                x=x+1;
            }
            x=0;
            while(x<sizeb)
            {
                correctb=isdigit(b[x]);
                if (correctb==0)
                {
                    break;
                }
                x=x+1;
            }
            if ((correctw!=0)&&(correctb!=0)) //Αν όλοι οι χαρακτήρες και των 2 αλφαριθμητικών είναι νούμερα//
            {
                x=0;
                while(x<sizew)
                {
                    if (((w[0]!='-')&&(w[1]!='-'))&&(w[0]!='0')) //Αν ο πρώτος ή ο δεύτερος χαρακτήρας του αλφαριθμητικού δεν είναι "-" ή το αλφαριθμητικό δεν έχει ως πρώτο χαρακτήρα το 0//
                    {
                        checkw=true; //Το check να πάρει τη τιμή true//
                        wd=10*wd+(w[x]-'0'); //Τύπος μετατροπής για char -> int και εκχώρηση στο wd//
                        x=x+1;
                    }
                    else
                    {
                       checkw=false;
                       break;
                    }
                }
                x=0;
                while (x<sizeb)
                {
                    if(((b[0]!='-')&&(b[1]!='-'))&&(b[0]!='0'))
                    {
                        checkb=true;
                        bd=10*bd+(b[x]-'0');
                        x=x+1;
                    }
                    else
                    {
                        checkb=false;
                        break;
                    }
                }
            }
            else
            {
                checkw=false;
                checkb=false;
            }
        }
        else
        {
            checkw=false;
            checkb=false;
        }
        key=0;
    }while((checkw==false)||(checkb==false));
      setworkduration(wd);  //Oι setters παίρνουν ως όρισμα το αποτέλεσμα από τη μετατροπή //
      setbreakduration(bd);
    }


    //ΕΝΑΡΞΗ ΣΥΝΕΔΡΙΑΣ POMODΟRO//




    int pomodoro::startSession()
    {
        HANDLE col= GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(col,14); //Aλλαγή χρώματος κονσόλας//
        char op;
        int telos=0;
        while (true)
        {
            telos=wtimer(&ch);
            if (telos==7) //Aν το χρονόμετρο της εργασίας επιστρέψει τιμή 7//
            {
                return 69; //Έξοδος από το χρονόμετρο και πίσω στο μενού//
            }
            SetConsoleTextAttribute(col,9); //Aλλαγή χρώματος//
            cout << "Start Break ?" << endl << endl;
            cout << "1.yes" << endl << "2.Exit" << endl;
            do
            {
                op=getch();
            }while((op!='1')&&(op!='2'));
            telos=0;
            switch(op)
            {
            case '1':                         //Aν πατήθηκε το 1//
                        telos=btimer(&ch);    //Συννέχισε στο διάλειμμα//
                        if(telos==69)
                        {
                            break;
                        }
            case '2':                          //Αν πατήθηκε το 2//
                return 70;                     //Επέστρεψε 70, δηλαδή βγές από τη συνάρτηση//
            default:
                cout << " " <<endl;
                break;
            }
            break;
         }
         return 69;
    }



    //ΕΡΓΑΣΙΑ//


    int pomodoro::wtimer(int *ch)
    {
        HANDLE col= GetStdHandle(STD_OUTPUT_HANDLE);
        int sec=0, k=0, wd, telos=0, integercounter=0, intwt=0;
        double deccounter=0.000, olddata, decwt=0;
        const string filename1 = "twt.txt"; //Το όνομα του αρχείου μπήκε σε const μιας και δε πρέπει ποτε να τροποποιηθεί//
        const string pause= "Press Space to pause"; //Tο μήνυμα αυτό μπήκε επίσης σε const για να μη μπορεί να τροποποιηθεί//
        const string esc= "Press escape to exit"; //Tο μήνυμα αυτό μπήκε επίσης σε const για να μη μπορεί να τροποποιηθεί//
        wd=getworkduration();
         fstream editFile(filename1, ios::in | ios::out);
                 if (editFile.is_open()) {
        editFile >> totalWorkTime;  //Διαβάζουμε τη τιμή του αρχείου και την εκχωρούμε σε totalWorkTime//

        editFile.close();
            }
            olddata= totalWorkTime; //Η παρούσα τιμή του totalWorkTime θα εκχωρηθεί στη μεταβλητη olddata//
            intwt=(int) totalWorkTime;  //H παρούσα ΑΚΕΡΑΙΑ τιμή του totalWorkTime θα εκχωρηθεί στη μεταβλητη intwt//
            decwt= totalWorkTime - intwt; //Στην decwt εκχωρείται το δεκαδικό μέρος του totalWorkTime που το πήραμε μέσω της αφαίρεσης του με το ακέραιο μέρος του//
            deccounter= 0.0;
            integercounter=0;
            Sleep(300); //Για αποφυγή σφαλμάτων//
        while(k==0)
    {
        *ch=0;
        Sleep(1000);  //Το sleep χρησιμοποιεί ms για να "παγώνει" το πρόγραμμα, άρα 1000ms=1s αφού έχουμε χρονόμετρο//
        system("cls");  // Για να "σβήνει" κάθε επόμενη τιμή//
        SetConsoleTextAttribute(col,14); //Aλλαγή χρώματος κονσόλας//
        cout  << "                                                      FOCUS! "<< endl << "                                                      " << wd<<" :: "<<sec << endl << endl << endl<<endl;
        if((wd>0)||(sec>0)) //Αν το χρονόμετρο δεν έχει μηδενιστεί//
        {
        if (sec==0) //Αν το τμήμα των δευτερολέπτων έχει γίνει 0//
        {
            sec=59; //Θέσε τα δευτερόλεπτα ξανά στα 59//
            wd=wd-1; //Μείωσε το τμήμα των λεπτών κατά 1//
            if ((deccounter >= 0.59)||(((totalWorkTime-intwt)+deccounter)>= 0.59)) //Αν μόνο ο δεκαδικός μετρητής ή το άθροισμα του δεκαδικού μέρους του totalWorkTime που πήραμε από το αρχείο .txt με τον δεκαδικό μετρητή είναι μεγαλύτερο ή ίσο του 59//
            {
                deccounter=0.000;  //Μηδένισε τον δεκαδικό μετρητή//
                integercounter=integercounter+1; //Αυξησε τον ακέραιο μετρητή κατά 1//
                totalWorkTime=0;  // Μηδένισε τη μεταβλητή totalWorkTime (η οποία περιειχε τα δεδομένα από το αρχείο .txt)//
                totalWorkTime=integercounter; //H τιμή του ακέραιου μετρητή εκχωρείται στο totalWorkTime//
                intwt=(int) totalWorkTime;  //Το intwt δέχεται τη τιμή του totalWorkTime//
                olddata=(olddata-decwt);
                decwt=0.0; //Μηδένισε το δεκαδικό μέρος του totalWorkTime//
            }
            else
            {
                deccounter=deccounter+0.01; //Άυξηση του δεκαδικού μετρητή κατά 0.01//
            }
        }
        else
        {
            sec=sec-1;
                 if ((deccounter >= 0.59)||(((totalWorkTime-intwt)+deccounter)>= 0.59))
            {
                deccounter=0.000;
                integercounter=integercounter+1;
                totalWorkTime=0;
                totalWorkTime=integercounter;
                 intwt=(int) totalWorkTime;
                 olddata=(olddata-decwt);
                 decwt=0.0;
            }
            else
            {
                deccounter=deccounter+0.01;
            }

        }

        if (GetAsyncKeyState(0x20)) //Αν ο χρήστης πατήσει το spacebar//
            {
                system("pause"); //Να σταματήσει το πρόγραμμα να τρέχει μέχρι ο χρήστης να πατήσει κάποιο άλλο κουμπί//
           }
           if (GetAsyncKeyState(0x1B)) // Αν ο χρήστης πατήσει το escape//
            {
                telos=endSession(); //Να κληθεί η συνάρτηση μέλος endSession//
                if (telos==5) //Εαν ο χρήστης επίλεξε να πάει στο κυρίως μενού//
                {

              fstream editFile(filename1, ios::in | ios::out);
                 if (editFile.is_open()) {
        totalWorkTime=olddata+deccounter+integercounter; //Το totalworktime θα γίνει το άθροισμα του ακέραιου και του δεκαδικού μετρητή + τα παλιά δεδομένα //
        editFile.seekg(0);

        editFile << totalWorkTime; //Εισαγωγή νέας τιμής μέσω του totalWorkTime στο αρχείο .txt//

        editFile.close();
            }

                    return 7;
                }
            }
            cout << pause << endl;
            cout << esc << endl;
        }
        else
        {
            cout << "END"<<endl;
            PlaySound(TEXT("dwd.wav"), NULL, SND_ASYNC); //Αναπαραγωγή αρχείου ήχου//
            Sleep(750);
             PlaySound(TEXT("dwd.wav"), NULL, SND_ASYNC);
            Sleep(750);
             PlaySound(TEXT("dwd.wav"), NULL, SND_ASYNC);
            *ch=0;
             fstream editFile(filename1, ios::in | ios::out);
                 if (editFile.is_open()) {
                        setprecision(2);
        totalWorkTime= olddata+deccounter+integercounter;
        editFile.seekg(0);

        editFile << totalWorkTime;

        editFile.close();
            }

             return 0;
        }
    }
    }




      //ΔΙΑΛΛΕΙΜΑ//

 int pomodoro::btimer(int *ch)
    {
        HANDLE col= GetStdHandle(STD_OUTPUT_HANDLE);
        int sec=0, bd, telos=0;
        const string filename = "cs.txt";
        const string pause= "Press Space to pause";
        const string esc= "Press escape to exit";
        bd=getbreakduration();
        Sleep(500);
        while(true)
    {
        Sleep(1000);
        system("cls");
        SetConsoleTextAttribute(col,5); //Aλλαγή χρώματος κονσόλας//
        cout  << "                                                      Relax :D "<< endl << "                                                      " << bd<<" :: "<<sec << endl << endl << endl<<endl;
        if((bd>0)||(sec>0))
        {
        if (sec==0)
        {
            sec=59;
            bd=bd-1;
        }
        else
        {
            sec=sec-1;

        }
        if (GetAsyncKeyState(0x20))
            {
                system("pause");
            }
             if (GetAsyncKeyState(0x1B))
            {
                telos=endSession();
                if (telos==5)
                {
                    return 69;
                }
            }
            cout << pause << endl;
            cout << esc << endl;
        }
        else
        {
            cout << "END"<<endl;
            PlaySound(TEXT("dwd.wav"), NULL, SND_ASYNC);
            Sleep(750);
             PlaySound(TEXT("dwd.wav"), NULL, SND_ASYNC);
            Sleep(750);
             PlaySound(TEXT("dwd.wav"), NULL, SND_ASYNC);
            *ch=1;
            fstream editFile(filename, ios::in | ios::out);
                 if (editFile.is_open()) {
        editFile >> sessionsCompleted;   //Διάβασμα τιμής από αρχείο κειμένου cs.txt//

       sessionsCompleted=sessionsCompleted+1;  //'Αυξηση της τιμής του αρχείου κατά 1//

        editFile.seekg(0);

        editFile << sessionsCompleted;  //Πέρασμα νέας τιμής στο αρχείο//

        editFile.close();
            }
            return 0;
    }
    }
    }
               //ΛΗΞΗ ΣΥΝΕΔΡΙΑΣ//

    int pomodoro::endSession()
    {
        HANDLE col= GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(col,4); //Aλλαγή χρώματος κονσόλας//
        char op=0;
        cout << "Are you sure you want to end the session?" << endl;
        cout << "1.Yes" << endl  << "2.No" << endl;
        do
        {
            op=getch();
        }while((op!='1')&&(op!='2')); //όσο ο χρήστης δεν εισάγει "1" ή "2", επανάληψη//
        switch (op)
        {
        case '1':                           //Aν πατηθεί το "1"//
            system ("cls");
            cout << "                                                  Session Ended" << endl;
            Sleep(750);
            system("cls");
            return 5;   //Τερματίζει το session και επιστροφή στο κυρίως μενού//
            break;
        case '2':
            return 10;    //Αν πατηθεί το "2"//
            break;
            default:
            cout << " " << endl;
    }
    }


   //ΕΜΦΑΝΙΣΗ ΣΤΑΤΙΣΤΙΚΩΝ//


    void pomodoro::getStatistics()
    {
         HANDLE col= GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(col,7);   //Aλλαγή χρώματος κονσόλας//
        const string filename = "cs.txt";
        const string filename1 = "twt.txt";
        totalWorkTime=0.0;
        sessionsCompleted=0;
        system("cls");
        cout << endl << endl << endl << endl << endl << endl << endl;
        cout <<"                                        * * * * * * * * * * * * * * * * * * *" << endl;
        cout <<"                                        *                                   *"<< endl;
        cout <<"                                        *                                   *"<< endl;
        cout <<"                                        *   User's Completed Pomodoros: ";
         fstream editFile(filename, ios::in | ios::out);
                 if (editFile.is_open()) {
        editFile >> sessionsCompleted;  //Διαβάζουμε τη τιμή από το αρχείο και την εκχωρούμε στη sessionsCompleted//
        cout << sessionsCompleted << "   *" << endl;

        editFile.close();
            }
        else
        {
            cout << "File not found!" << endl;  //Αν το αρχείο δεν υπάρχει//
        }
         cout <<"                                        *                                   *"<< endl;
         cout <<"                                        *                                   *"<< endl;
         cout <<"                                        *   User's Total Work Time: ";
         fstream editFile1(filename1, ios::in | ios::out);
                 if (editFile1.is_open()) {
        editFile1 >> totalWorkTime;  //Διαβάζουμε τη τιμή από το αρχείο και την εκχωρούμε σε totalWorkTime//
        cout << fixed << setprecision(2);  //Επειδή χρησιμοποιούμε double, και αφού έχουμε να κάνουμε με χρόνο, θέλουμε να εμφανίζονται μόνο 2 δεκαδικά ψηφία του αριθμού//
        cout << totalWorkTime <<   "    *"  << endl;

        editFile1.close();
            }
        else
        {
            cout << "File not found!" << endl;  //Αν το αρχείο δεν υπάρχει//
        }
         cout <<"                                        *                                   *" << endl;
         cout <<"                                        *                                   *" << endl;
         cout <<"                                        * * * * * * * * * * * * * * * * * * *" << endl;
         cout << " "<< endl << endl;
         Sleep(2500);
    }

      // CREDITS //
    void pomodoro::credits()
    {
        system("cls");
        HANDLE col= GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(col,10);  //Aλλαγή χρώματος κονσόλας//
        cout << " Programming: Eleftherios Chondromatidis " << endl << endl;
        cout << " In program design: Eleftherios Chondromatidis" << endl << endl;
        SetConsoleTextAttribute(col,5);
        cout << " Ico: Eleni Basi " << endl<< endl;
        SetConsoleTextAttribute(col,7);
        cout <<"                                          Copyright 2023-2024" << endl;
        Sleep(2666);
    }
