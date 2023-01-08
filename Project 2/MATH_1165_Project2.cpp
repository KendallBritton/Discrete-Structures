/*  Name: Kendall Britton

    The program will take in two sizes of a grid system and will output the distinct
    number of rectangles that can be made from the specific grid size.

    The linux based command run code is "g++ -std=c++11 MATH_1165_Project2.cpp -o test"
    followed by a "./test" at the next command prompt.
*/

#include <iostream>
using namespace std;

int recCounter(int& m, int& n){
    
    if((m <= 0) || (n <= 0)){ // Ensures that no negative inputs are allowed
        return -1;
    }

    int m1 = m + 1; // Creates variables to carry out the two n choose k procedures that will be multiplied together.
    int n1 = n + 1;
    int temp, temp2;

    temp = m1 - 1; // Calculates the second number in the falling factorial
    temp2 = n1 - 1;

    int ans, ans2;

    ans = (m1 * temp)/2; // Calculates the part of the n choose k formula
    ans2 = (n1 * temp2)/2;

    return ans * ans2;
}

int main(){
    int n,m,r;

    cout << "Enter row size for the grid: " << endl;
    cin >> m;
    cout << "Enter the column size for the grid: " << endl;
    cin >> n;

    r = recCounter(m,n);

    if(r == -1){
        cout << "DNE" << endl;
    } else {

        cout << "There are " << r << " distinct rectangles in a " << m << " x " << n << " grid." << endl;
    }

    return 0;
}