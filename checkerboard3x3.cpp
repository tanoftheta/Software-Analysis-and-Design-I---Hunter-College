
#include <iostream> 
using namespace std; 

/*Name: Tanisha Mahmud 
Class: CS 135
Lab 4*/

int main()
{
    int width; 
    int height; //establish variables
    cout << "Enter width: \n"; 
    cin >> width; //store user input in variables 
    cout << "Enter height: \n"; 
    cin >> height; 
    for (int i=0; i < height; i++) //for loop to create height 
    {
        int z = i/3; //new variable to maintain 3x3 pattern 
        if (z%2==0) //every third 
        {
            for (int j=0; j < width; j++)// for pattern to create width 
            {
                int k = j/3; //maintains 3x3 pattern among columns
                if (k%2==0)
                {
                    cout << "*"; //makes checkerboard pattern 
                }
                else
                {
                    cout << " ";
                }
            }
        }
        else 
        {
            for (int j=0; j < width; j++) //pattern 
            {
                int k = j/3; 
                if (k%2==0)
                {
                    cout << " ";
                }
                else
                {
                    cout << "*";
                }                
            }
        }
    cout << endl; //endline to create rows 
    }
}