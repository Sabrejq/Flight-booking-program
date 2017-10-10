#ifndef PLANE_H
#define PLANE_H

struct Seat
{
    char status;
    bool isBooked;
};

class Plane

{
private:
    Seat **firstClass;
    Seat **economy;
    int firstClassRows;
    int firstClassCols;
    int econRows;
    int econCols;
public:
    Plane();
    Plane(int, int , int ,int);
    void displaySeats();
    void bookSeat();
    void checkSeat();
    void clearSeat();
    void clearAllseats();
    ~Plane();
    
};

#endif

