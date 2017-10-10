#include <iostream>
#include <iomanip>
#include "Plane.h"
using namespace std;

Plane::Plane()
{
    int r11, c11, r21, c21;
    cout<<"\nEnter the rows and colums in first class: ";
    cin>>r11>>c11;
    cout<<"\nEnter the rows and colums in economy class: ";
    cin>>r21>>c21;
    Plane (r11, c11, r21, c21);
}

Plane::Plane(int r1, int c1, int r2, int c2)
{
    this->firstClassRows=r1;
    this->firstClassCols=c1;
    this->econRows=r2;
    this->econCols=c2;
    firstClass = new Seat *[r1];
    
    for (int i = 0; i < r1; i++) {
        firstClass[i] = new Seat[c1];
    }
    
    for (int i = 0; i < firstClassRows; i++) {
        for (int j = 0; j < firstClassCols; j++) {
            firstClass[i][j].status='-';
            firstClass[i][j].isBooked=false;
        }
        
    }
    
    economy = new Seat *[r2];
    for (int i = 0; i < r2; i++) {
        economy[i] = new Seat[c2];
        
    }
    
    for (int i = 0; i < econRows; i++) {
        for (int j = 0; j < econCols; j++) {

            economy[i][j].status='-';
            economy[i][j].isBooked=false;
            
        }
        
    }
    
}

void Plane::displaySeats()
{
    cout<<"\nFirst Class"<<endl;
    cout<<"____________"<<endl;
    for (int i = 0; i < firstClassRows; i++) {
        for (int j = 0; j < firstClassCols; j++) {
            cout<<firstClass[i][j].status<<" ";
        }
        cout<<endl;
        
    }
    cout<<"\nEconomy"<<endl;
    cout<<"_______"<<endl;
    for (int i = 0; i < econRows; i++) {
        for (int j = 0; j < econCols; j++) {
            cout<<economy[i][j].status<<" ";
        }
        cout<<endl;
    }
    cout<< "\n\n";
}

void Plane:: bookSeat(){
    cout<<"\nSelect class\n 1. First Class\n 2. Economy\n";
    int ch, r, c;
    cin>>ch;
    bool booked=false;
    while(!booked)
    {
        switch(ch)
        {
            case 1:
                cout<<"Enter the row: ";
                cin>>r;
                cout << "Enter the column: ";
                cin >>c;
                if(firstClass[r][c].isBooked==false){
                    firstClass[r][c].isBooked=true;
                    firstClass[r][c].status='X';
                    cout<<"\nBooking sucessfull!\n";
                    booked=true;
                    break;
                }
                else
                {
                    cout<<"\nEntered seat unavilable, Enter another seat.\n";
                    booked=false;
                    break;
                    
                }
                
            case 2:
                cout<<"Enter the row: ";
                cin>>r;
                cout << "Enter the column: ";
                cin >>c;
                if(economy[r][c].isBooked==false){
                    economy[r][c].isBooked=true;
                    economy[r][c].status='X';
                    cout<<"\nBooking sucessfull!\n";
                    booked=true;
                    break;
                    
                }
                else
                {
                    cout<<"\nEntered seat unavilable, Enter another seat.\n";
                    booked=false;
                    break;
                }
            default:
                cout << "\nInvalid input\n";
                break;
        }
    }
}

void Plane::checkSeat(){
    cout<<"\nSelect class\n 1. First Class\n 2. Economy\n";
    int ch, r, c;
    cin>>ch;
    switch(ch)
    {
        case 1:
            cout<<"Enter the row: ";
            cin>>r;
            cout << "Enter the column: ";
            cin>>c;
            if(firstClass[r][c].isBooked)
                cout<<"\nThe seat is booked.\n";
            else
                cout<<"\nThe seat is empty.\n";
            break;
        
        case 2:
            cout<<"Enter the row: ";
            cin>>r;
            cout << "Enter the column: ";
            cin>>c;
            if(economy[r][c].isBooked)
                cout<<"\nThe seat is booked.\n";
            else
                cout<<"\nThe sear it empty.\n";
            break;
        
        default:
            cout<<"\nInvalid input.\n"<<endl;
            break;
    }
}

void Plane::clearSeat()
{
    cout<<"Select class\n 1. First Class\n 2. Economy\n";
    int ch, r, c;
    cin>>ch;
    switch(ch)
    {
        case 1:
            cout<<"Enter the row: ";
            cin>>r;
            cout<< "Enter the column: ";
            cin>>c;
            cout<<"\nThe seat is Cleared.\n";
            firstClass[r][c].isBooked=false;
            firstClass[r][c].status='-';
            break;
    
        case 2:
            cout<<"Enter the row: ";
            cin>>r;
            cout<< "Enter the column: ";
            cin>>c;
            cout<<"\nThe seat is Cleared.\n";
            economy[r][c].isBooked=false;
            economy[r][c].status='-';
            break;
        
        default:
            cout<<"\nInvalid input.\n"<<endl;
            break;
    }
    
    
}

void Plane::clearAllseats(){
    for (int i = 0; i < firstClassRows; i++) {
        for (int j = 0; j < firstClassCols; j++) {
            firstClass[i][j].status='-';
            firstClass[i][j].isBooked=false;
        }
    }
    
    for (int i = 0; i < econRows; i++) {
        for (int j = 0; j < econCols; j++) {
            economy[i][j].status='-';
            economy[i][j].isBooked=false;
        }
    }
    cout<<"\nAll seats have been cleared.\n";
}

Plane::~Plane(){
    if (firstClass != NULL)
    {
        for(int r=0;r<firstClassRows;r++)
            delete []firstClass[r];
        delete []firstClass;
    }
    firstClass = NULL;
    
    if (economy != NULL)
    {
        for(int r=0;r<econRows;r++)
            delete []economy[r];
        delete []economy;
    }
    economy = NULL;
}

