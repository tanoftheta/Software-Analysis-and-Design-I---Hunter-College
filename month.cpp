#include <iostream>
using namespace std;
/*
Name: Tanisha Mahmud 
Lab1D */

int main()
{
    //set variable
    int year; 
    //ask for year
    cout << "Enter year: " << endl; 
    cin >> year;
    int month; 
    //ask for month
    cout << "Enter month: " << endl; 
    cin >> month; 
    //in the case of february leap year
    if (year%400==0 and month==2)
    cout << "29 days"; 
    if (year%100==0 and year%400!=0 and month==2)
    cout << "28 days"; 
    //in the case of february common year
    if (year%4==0 and year%100!=0)
    cout << "29 days"; 
    if (year%4!=0 and month==2)
    cout << "28 days";
    //in compliance with the "knuckle bumps" guidelines
    if (month<8 and month%2==1)
    cout << "31 days"; 
    if (month<8 and month%2==0 and month!=2)
    cout << "30 days";
    if (month > 7 and month%2==1)
    cout << "30 days" ; 
    if (month > 7 and month%2==0)
    cout << "31 days" ;
}