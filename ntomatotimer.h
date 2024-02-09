#include <iostream>

extern int ch;
int menu (); //εξωτερική συνάρτηση για το κυρίως μενού επιλογών//
class pomodoro
{

private:

    int workDuration; // Πόσο θα διαρκέσει η εργασία//
    int breakDuration; // Πόσο θα διαρκέσει το διάλειμμα//
    int sessionsCompleted; // Πόσες συνεδρίες είναι πλήρως ολοκληρωμένες//
    double totalWorkTime; // Πόσο χρόνο έχει αφιερώσει συνολικά ο χρήστης για την εργασία//

    public:

    void setworkduration (int wd); //Setter για προσπέλαση του ιδιωτικού μέλους workDuration//
    void setbreakduration (int bd); //Setter για προσπέλαση του ιδιωτικού μέλους breakDuration//
    int getworkduration(); //Getter για να πάρουμε τη τιμή από το ιδιωτικό μέλος workDuration//
    int getbreakduration(); //Getter για να πάρουμε τη τιμή από το ιδιωτικό μέλος workDuration//
    void settings(); // Συνάρτηση της κλάσης με την οποία ο χρήστης μπορεί να επηρεάζει τη διάρκεια της εργασίας και του διαλείμματος//
    int startSession (); //Συνάρτηση της κλάσης που όταν κληθεί θα αρχίζει ή θα συνεχίζει μια συνεδρία//
    int endSession (); // Συνάρτηση που όταν θα κληθεί, και αν ο χρήστης το επιλέξει, θα τερματίζει τη συνεδρία και θα επιστρέφει τον χρήστη στο κυρίως μενού//
    void getStatistics(); // Συνάρτηση που όταν κληθεί, θα εμφανίζει στον χρήστη τον συνολικό χρόνο εργασίας του όσο έχει το πρόγραμμα στον υπολογιστή του, και το πόσες συνεδρίες έχει ολοκληρώσει//
    void credits();
    pomodoro()  // Default Constructor//
    {
        workDuration=25;
        breakDuration=5;
    }
    int wtimer(int *ch); // Χρονόμετρο εργασίας//
    int btimer(int *ch); // Χρονόμετρο διαλείμματος//
};
