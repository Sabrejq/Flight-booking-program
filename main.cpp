#include <iostream>
#include "Plane.h"
using namespace std;

int main(){
    Plane COSC1430 = *new Plane(4,4,10,4);
    cout<< "COSC1430 PLANE SEATING MAP\n\n";
    COSC1430.displaySeats();
    while(1)
    {
        cout<<"Pick one of these options"<<endl;
        cout<<"1. Display all Seat."<<endl;
        cout<<"2. Check a Seat."<<endl;
        cout<<"3. Clear a Seat."<<endl;
        cout<<"4. Book a Seat."<<endl;
        cout<<"5. Empty all Seat."<<endl;
        cout<<"6. Exit."<<endl;
        cout << "Input: ";
        int ch;
        cin>>ch;
        switch(ch)
        
        {
            case 1:
                COSC1430.displaySeats();
                break;
            case 2:
                COSC1430.checkSeat();
                break;
            case 3:
                COSC1430.clearSeat();
                break;
            case 4:
                COSC1430.bookSeat();
                break;
            case 5:
                COSC1430.clearAllseats();
                break;
            case 6:
                COSC1430.clearAllseats();
                COSC1430.~Plane();
                cout<<"\nThank you for flying with 338_9 Airlines!\nCome back soon!\n";
                return 0;
                break;
            default:
                cout << "Invalid input";
                break;
        }
        cout<<endl;
    }
    return 0;
    
}
