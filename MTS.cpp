#include <bits/stdc++.h>

using namespace std;

typedef struct MovieDetails moviesAva;
typedef struct MShow movieShow;

struct MShow{
    string time ;
    int HallNo;
    string Seats[10][10];
};

struct MovieDetails{
    string movieName;
    string Lang;
    string genre;
    vector<movieShow> Shows;
    int price;
};

class BookMyShow{
    string CinemaName;
    public:
    int NoOfMovies;
    vector<moviesAva> moviesAvail;
    virtual void printName(){ cout << CinemaName; }
    void HomePage();
    BookMyShow();
    void SearchMovie(int index);
    void showSeating(int , int);
    void BookSeats(int , int);
    void Confirmation(vector<string> , int , int);
};

class imax  : public BookMyShow{
    string CinemaName;
    vector<pair<string , vector<moviesAva>>> Cities;
    public:
    void printName() {cout << "IMAX";}
    imax();
};

class inox : public BookMyShow{
    string CinemaName;
    
    public:
    void printName() {cout << "INOX";}
    inox();
};

class pvr : public BookMyShow {
    string CinemaName;
    
    public:
    void printName() {cout << "PVR";}
    pvr();
};

imax IMAX ; inox INOX ; pvr PVR;
imax * ptrIMAX = &IMAX ; inox *  ptrINOX = &INOX ; pvr * ptrPVR = &PVR;
vector<BookMyShow *> parentPtr;

void Cinemas(){
    parentPtr.push_back(ptrIMAX);
    parentPtr.push_back(ptrINOX);
    parentPtr.push_back(ptrPVR);
}

int main(){
    
    BookMyShow newUser;
    Cinemas();
    newUser.HomePage();

    return 0;
}

inox::inox(){
    
    CinemaName = "INOX";

    moviesAvail.push_back({"Fight Club" , "English" , "Mystery" , {{"10:00am" , 3} , {"8:30 pm" , 2}}, 12 }); NoOfMovies ++;
    moviesAvail.push_back({"Spiderman : No Way Home" , "English" , "Action" , {{"11:30am" , 2} , {"3:00 pm" , 1}} , 7});  NoOfMovies ++;
    moviesAvail.push_back({"Gladiator" , "English" ,"Action" ,  {{"10:00 am" , 1} , {"6:30pm" , 4}} , 14});  NoOfMovies ++;
    moviesAvail.push_back({"Dangal" ,"Hindi" , "Drama" , {{"9:00am" , 4}, {"6:30 pm" , 3}}, 10});    NoOfMovies ++;

   for(int k = 0 ; k< NoOfMovies ; k++){
       for(int l = 0 ; l < (moviesAvail[k].Shows).size() ; l++){
        char Let[10] = {'A' , 'B' , 'C' , 'D' , 'E' , 'F', 'G' , 'H' , 'I', 'J'};
        for(int i = 0 ; i<10 ; i++){
        for(int j = 0 ; j<10 ; j++){
            string SNo = to_string(j+1);
            (moviesAvail[k].Shows)[l].Seats[i][j] = Let[i];
            if(j != 9) (moviesAvail[k].Shows[l]).Seats[i][j] += '0' + SNo;
            else (moviesAvail[k].Shows)[l].Seats[i][j] += SNo;
        }
        }
    }
   }

}

imax::imax(){
    CinemaName = "IMAX";

    moviesAvail.push_back({"Spiderman : No Way Home" , "English" , "Action" , {{"9:00am" , 4}, {"6:30 pm" , 3}} , 12}); NoOfMovies ++;
    moviesAvail.push_back({"Batman" , "English" , "Action" ,{{"10:00am" , 3} , {"8:30 pm" , 2}} , 14});  NoOfMovies ++;
    moviesAvail.push_back({"Shawshank Redemption" , "English" , "Mystery" , {{"10:00 am" , 1} , {"6:30pm" , 4}} , 9});  NoOfMovies ++;
    moviesAvail.push_back({"The Intern" , "English" , "Comedy" ,{{"11:30am" , 2} , {"3:00 pm" , 1}} , 8});    NoOfMovies ++;

   for(int k = 0 ; k< NoOfMovies ; k++){
       for(int l = 0 ; l < (moviesAvail[k].Shows).size() ; l++){
        char Let[10] = {'A' , 'B' , 'C' , 'D' , 'E' , 'F', 'G' , 'H' , 'I', 'J'};
        for(int i = 0 ; i<10 ; i++){
        for(int j = 0 ; j<10 ; j++){
            string SNo = to_string(j+1);
            (moviesAvail[k].Shows)[l].Seats[i][j] = Let[i];
            if(j != 9) (moviesAvail[k].Shows[l]).Seats[i][j] += '0' + SNo;
            else (moviesAvail[k].Shows)[l].Seats[i][j] += SNo;
        }
        }
    }
   }
}

pvr::pvr(){    
    CinemaName = "PVR";

    moviesAvail.push_back({"Spiderman : No Way Home" ,"English" , "Action" , {{"11:30am" , 2} , {"3:00 pm" , 1}} , 12}); NoOfMovies ++;
    moviesAvail.push_back({"The Devil Wears Prada" ,  "English" , "Comedy" ,{{"10:00am" , 3} , {"8:30 pm" , 2}} , 6});  NoOfMovies ++;
    moviesAvail.push_back({"Fight Club" , "English" , "Mystery" ,{{"9:00am" , 4}, {"6:30 pm" , 3}} , 9});  NoOfMovies ++;
    moviesAvail.push_back({"The Intern" , "English" , "Comedy" , {{"10:00 am" , 1} , {"6:30pm" , 4}} , 8});    NoOfMovies ++;

   for(int k = 0 ; k< NoOfMovies ; k++){
       for(int l = 0 ; l < (moviesAvail[k].Shows).size() ; l++){
        char Let[10] = {'A' , 'B' , 'C' , 'D' , 'E' , 'F', 'G' , 'H' , 'I', 'J'};
        for(int i = 0 ; i<10 ; i++){
        for(int j = 0 ; j<10 ; j++){
            string SNo = to_string(j+1);
            (moviesAvail[k].Shows)[l].Seats[i][j] = Let[i];
            if(j != 9) (moviesAvail[k].Shows[l]).Seats[i][j] += '0' + SNo;
            else (moviesAvail[k].Shows)[l].Seats[i][j] += SNo;
        }
        }
    }
   }
}

BookMyShow::BookMyShow(){ NoOfMovies = 0; }

void BookMyShow::HomePage(){
    cout << "|------------------------------------         Welcome To Book My Show         ----------------------------------|\n\n\n\n" << endl;

    cout << "                 If you want to search by Movie Name(ex : 'Fight Club' , 'Gladiator' , etc) press 1             " << endl;
    cout << "                 If you want to search by Language(ex : 'English' , 'Hindi' , etc) press 2                " << endl;
    cout << "                 If you want to search by Genre(ex : 'Action' , 'Comedy' , 'Mystery') press 3                \n" << endl;
    cout << "                           Press any other number to exit                                 \n\n\n\n"<< endl;

    cout << "|---------------------------------------------------------------------------------------------------------------|\n\n" << endl;
    int choice;
    cout << "Your Choice : " ; cin >> choice;
    cout << "\n\n\n";
    if(choice == 1 || choice == 2 || choice == 3) SearchMovie(choice);
    else return;
}

void BookMyShow::SearchMovie(int choice){
    string MovieSearch;
    cout << "Search : " ; getline(cin >> ws, MovieSearch);
    cout << "\n\n\n";
    int count = 0;
    vector<pair<int , int>> reqMovie = {{0 , 0} ,{1 , 0} , {2 ,0}};
    for(int i = 0 ; i < parentPtr.size() ; i++){
        for(int j = 0 ; j < (parentPtr[i]->moviesAvail).size() ; j++){
            string search = "";
            if(choice == 1) search = (parentPtr[i]->moviesAvail)[j].movieName;
            if(choice == 2) search = (parentPtr[i]->moviesAvail)[j].Lang;
            if(choice == 3) search = (parentPtr[i]->moviesAvail)[j].genre;
            if(search == MovieSearch){
                reqMovie[i].second = j;
                count ++;
                cout << "Cinema Number " << i+1 << "\n";
                cout << "-------------------     AT " ; parentPtr[i]->printName() ; cout << " CINEMAS------------------\n\n";
                cout << (parentPtr[i]->moviesAvail)[j].movieName << endl;
                cout << (parentPtr[i]->moviesAvail)[j].Lang << " ( " << (parentPtr[i]->moviesAvail)[j].genre << " )" << endl;
                    
                for(int k = 0 ; k < ((parentPtr[i]->moviesAvail)[j].Shows).size() ; k++){
                    cout << ((parentPtr[i]->moviesAvail)[j].Shows)[k].time << "   ,   " ;
                }
                cout << endl;
                cout << "Price : " << (parentPtr[i]->moviesAvail)[j].price << endl;
                cout << "\n\n";
            }
        }
    }
    if(count == 0 ) {
        "           Sorry We couldn't find the movie :( \n\n\n";
        HomePage();
    }
    else{
        int CinemaIndex;
        cout << "Select the Cinema Number (ex : select 1 for IMAX) : " ; cin >> CinemaIndex;
        CinemaIndex--;
        int MovieIndex = reqMovie[CinemaIndex].second;

        cout << "Thank You for choosing " ; parentPtr[CinemaIndex]->printName(); cout << "\n\n" ;
        for(int k = 0 ; k < ((parentPtr[CinemaIndex]->moviesAvail)[MovieIndex].Shows).size() ; k++){
            cout << "Show " << k+1 << ": " << ((parentPtr[CinemaIndex]->moviesAvail)[MovieIndex].Shows)[k].time << "\n";
        }
        int ShowIndex;
        cout << "Here are the avaialble shows . Please select the show Number : "; cin >> ShowIndex;
        ShowIndex--;
        parentPtr[CinemaIndex]->BookSeats(MovieIndex , ShowIndex);
    }
}


void BookMyShow::showSeating(int MovIndex , int ShIndex){
    cout << "///////////////////   Available seats   /////////////////////"  << endl;
    cout << "\n\n\n";
    for(int i = 0 ; i<10 ; i++){
        for(int j = 0 ; j<10 ; j++){
            if(j == 3 || j== 7) cout << "               " ;
            cout << " [" << (moviesAvail[MovIndex].Shows[ShIndex]).Seats[i][j] << "] ";
        }
        cout << endl;
    }
}


void BookMyShow::BookSeats(int MovIndex , int ShIndex){
    cout << "---------------------      "; printName() ; cout << "       ---------------------\n\n"; 
    cout << "                       " << moviesAvail[MovIndex].movieName << "                   \n\n";
    int SeatsNum = 0;
    cout << "How many seats would you like to book ? " ;
    cin >> SeatsNum;

    showSeating(MovIndex , ShIndex);
    cout << "Please select the seat as follows:" << endl;
    cout << "If seat D08 is to be chosen write 'D08' " << endl;
    char row ; int col ;
    vector <string> bookedS;
    for(int i = 1 ; i<=SeatsNum ; i++){
        cout << "Seat " << i << ": " ;
        cin >> row >> col;

        int r = row - 65 , c = col-1;
        if((moviesAvail[MovIndex].Shows[ShIndex]).Seats[r][c] == " X ") {
            cout << "Seat not available ..... Choose another" << endl;
            i--;
        }

        else{
            bookedS.push_back((moviesAvail[MovIndex].Shows[ShIndex]).Seats[r][c]);
            (moviesAvail[MovIndex].Shows[ShIndex]).Seats[r][c] = " X ";
        }
    }

    Confirmation(bookedS , MovIndex , ShIndex);
}

void BookMyShow::Confirmation(vector<string> SB , int MovIndex , int ShIndex){
    cout << "\n\nYour ticket has been booked . Here are the details\n" << endl;
    cout << "..................................................................." << endl;
    cout << "                           "; printName() ; cout << "\n\n";
    cout << "       Movie : " << moviesAvail[MovIndex].movieName << endl;
    cout << "       Time : " << (moviesAvail[MovIndex].Shows[ShIndex]).time << endl;
    cout << "       Screen No. : " << (moviesAvail[MovIndex].Shows[ShIndex]).HallNo << endl;
    cout << "       Seats : " ;
    for(int i =0 ; i<SB.size() ; i++) {
        cout << SB[i] ;
        if(i != SB.size()-1 ) cout << " , ";
    }
    cout << endl;

    cout << "       Total Price : $" << SB.size()*(moviesAvail[MovIndex].price) << endl;
    cout << "..................................................................." << endl;
    cout << "\n\n\n";
    cout << "Enjoy Your Movie :)\n\n" << endl;

    char choice;
    cout << "Press any key to go back to the Home Page"; cin >> choice;
    
    HomePage();

}
