// Class composition: Class Date uses an object of class Time.

#include <iostream>
using namespace std;

class Time {
public:
    Time();
    Time(int, int, int);
    void setTime(int, int, int);
    void printTime() const;

private:
    int hour, minute, second;
};

Time::Time() {
    cout << "Constructor Time() is called" << endl;
    hour = 0;
    minute = 0;
    second = 0;
}

Time::Time(int _h, int _m, int _s)
{
    cout << "Constructor Time(int _h, int _m, int _s) is called" << endl;
    setTime(_h,_m,_s);
}

void Time::setTime(int h, int m, int s) {
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printTime() const {
    cout << hour << ":" << minute << ":" << second << endl;
}

class Date {
public:
    Date(int, int, int, int, int, int);   // sets day, month, year, hours, minutes, seconds
    Date(int, int, int, Time);
    void printDate() const;   	    // print date to the screen

private:
    int day, month, year;
    Time time;   // a component object
};

Date::Date(int d, int m, int y, int hour, int min, int sec) {
    cout << "Constructor Date(...) is called" << endl;
    day = d;
    month = m;
    year = y;
    time.setTime(hour, min, sec);
}

Date::Date(int d, int m, int y, Time t)
{
    cout << "Constructor Date(...) is called" << endl;
    day = d;
    month = m;
    year = y;
    time = t;
}

void Date::printDate() const {
    cout << month << "/" << day << "/" << year << " ";
    time.printTime();
}


int main()
{
    Time* t= new Time(10, 20, 45);
    Date date2(10, 12, 2006, *t);
    delete t;

    date2.printDate();

    Date date(10, 12, 2006, 10, 20, 45);
    cout << "The date is:" << endl;
    date.printDate();
   
}
