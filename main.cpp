#include "ntomatotimer.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <string>
#include <cctype>
#include <string.h>
#include <fstream>
#include <math.h>
#include <iomanip>
#include <mmsystem.h>



using namespace std;
int main ()
{
    pomodoro (); //κλήση default constructor//
    pomodoro me;
    const string filename = "cs.txt"; //ορισμός ονόματος αρχείου για σύνολο ολοκληρωμένων συνεδριών//
    const string filename1 = "twt.txt"; //oρισμός ονόματος αρχείου για συνολικό χρόνο εργασίας//
    int re=1, pressedset=0, cho=0, piswstomenu=0;
    char ans;
            ifstream file(filename);
        if (file.is_open()) {          //Έλεγχος εαν το αρχείο cs.txt όντως υπαρχει//
                cout << " ";
        }
        else
        {
           ofstream filename; // Aν το αρχείο ΔΕΝ υπάρχει, θα φτιαχτεί νέο αρχείο//
           filename.open ("cs.txt");
           filename<< 0; //Αρχικοποίηση αρχείου με 0//
          filename.close();
        }
         ifstream file1(filename1);
        if (file1.is_open()) {    //Έλεγχος αν το αρχείο twt.txt όντως υπάρχει//
                cout << " ";
        }
        else
        {
           ofstream filename1; //Aν το αρχείο ΔΕΝ υπάρχει, θα φτιαχτεί νέο αρχείο twt.txt//
           filename1.open ("twt.txt");
           filename1<< 0;  //Αρχικοποίηση αρχείου με 0//
          filename1.close();
        }

    while (re!=2)
    {
   HANDLE col= GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleTextAttribute(col,7); //Αλλαγή χρώματος κονσόλας//
    cho=0;
    piswstomenu=0;
    cho=menu(); //Κλήση συνάρτησης menu για εμφάνιση του μενού επιλογών//
    if (cho==0)  //Έξοδος από την εφαρμογή αν η menu επέστρεψε τιμή 0//
    {
        re=2;
        system("cls");
        cout << "Exiting NtomatoTimer." << endl;
        Sleep(250);
        system("cls");
        cout << "Exiting NtomatoTimer.." << endl;
        Sleep(250);
         system("cls");
        cout << "Exiting NtomatoTimer..." << endl;
        Sleep(500);
       return 0;
    }
    else if (cho==1) // Αν η menu επέστρεψε τιμή 1//
    {
        if (pressedset==0) //Αν ο χρήστης δεν έχει πάει στα settings για να αλλάξει τους χρόνους//
        {
            me.setworkduration(25); //Χρόνος εργασίας τα 25 λεπτά//
            me.setbreakduration(5); //Χρόνος διαλείμματος τα 5 λεπτά//
        }
            piswstomenu=me.startSession();
        if (piswstomenu!=69)
        {

            do{
              
                    SetConsoleTextAttribute(col,7);
                    piswstomenu==0;
            cout << "Press 1 To Continue With The Same Settings" << endl;
            ans=getch(); //Διάβασμα τιμής από τον χρήστη για το αν επιθυμεί να συνεχίζει με τις ίδιες ρυθμίσεις//
                 if((ch==0)&&(ans=='1')) //Αν ο χρήστης πατήσει το "1" και ο δείκτης ch έχει τιμή 0//

                 {
                     piswstomenu=me.btimer(&ch); //Πήγαινε-συνέχισε με το διάλειμμα//
                 }
                 else if((ch==1)&&(ans=='1'))  //Αν ο χρήστης πατήσει το "1" και ο δείκτης ch έχει τιμή 1//
                 {
                     piswstomenu=me.startSession(); //Ξεκίνα από την αρχή, δηλαδή από το χρονόμετρο της εργασίας//
                 }
              

    }while((ans=='1')&&(piswstomenu!=69));
        }
   pressedset=0;
    }
    else if (cho==2) //Aν η συνάρτηση γύρισε τιμή 2//
    {
        me.settings(); //Καλείται η συνάρτηση μέλος με τις ρυθμίσεις για τον χρόνο//
        pressedset=1;

    }
    else if (cho==3) //Aν η συνάρτηση γύρισε τιμή 3//
    {
        me.getStatistics(); //Καλείται η συνάρτηση μέλος για την εμφάνιση των στατιστικών//
    }
    else if (cho==5)
    {
        me.credits();
    }
    else if (cho==69) //Aν η συνάρτηση γυρίσει 69, δηλάδη ο χρήστης έγραψε τυχαίο αριθμό//
    {
        cho=menu(); //Κάλεσε ξανά το μενού επιλογών//
    }

    }
}






