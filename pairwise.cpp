#include <iostream> 
#include <vector>
using namespace std; 

/* Name: Tan Mahmud 
Class: CS 135 
Lab 12D */ 

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2)
{ //declare function
    vector<int> pairwise; // declare new vector
    if (v1.empty())
    {
        pairwise = v2; 
        return pairwise; 
    }
    if (v2.empty())
    {
        pairwise = v1; 
        return pairwise; 
    }
    if (v1.size() > v2.size()) // loop through larger variable 
    {
        for (int i = 0; i < v1.size(); i++)
        {
            pairwise.push_back(v1[i]+v2[i]); // add pairwise elements 
        } 
    }
    else // accounts for other variable / equal 
    {
        for (int i=0; i < v2.size(); i++)
        {
            pairwise.push_back(v2[i]+v1[i]);
        }
    }
    return pairwise; // return 
}
int main()
{ // test 
    vector<int> v1 = {7, 13, 69, 666}; 
    vector<int> v2;
    vector<int> test = sumPairWise(v1, v2); 
    for (int i = 0; i < test.size(); i++)
    {
        cout << test[i] << " "; 
    }
}