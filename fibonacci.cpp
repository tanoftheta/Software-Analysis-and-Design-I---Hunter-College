/* Name: Tanisha Mahmud 
Course: CSCI 135 
Lab 2 */

#include <iostream>
using namespace std; 

int main()
{
    int i; //set variable for for-loop
    int fib[60]; //create an array with 60 indexes 
    fib[0] = 0; 
    fib[1] = 1; 
    cout << fib[0] << endl << fib[1] << endl;
    for(i=2; i<60; i++) //for getting through first 60 digits of sequence
    {
        fib[i] = fib[i-1] + fib[i-2]; //algorithm for fib seq
        cout << fib[i] << endl; //print 
    }
}
