/*  Name: Kendall Britton

    The program will ask the user to input to integers, positive or negeative,
    where the output will be the greatest common divisor of the two integers.

    If the user enters 0 and 0 to be compared using the Euclidean Algorithm,
    the terminal will output a -1 meaning that this operation is not possible.

    The linux based command run code is "g++ -std=c++11 MATH_1165_Project1.cpp -o test"
    followed by a "./test" at the next command prompt.
*/

#include <iostream>
#include <cmath>
using namespace std;


int gcd(int& a, int& b){ //Function defintion for gcd algorithm

    
    int a1,b1, temp; // Allows for the input of negative numbers
    a1 = abs(a);
    b1 = abs(b);

    if((a1 == 0)&&(b1 == 0)){ // Eliminates the operation of two zeroes being computed
        return -1;
    }

    if(a1 < b1){ // Ensures that A1 is greater than B1 so that function will properly
        temp = a1;
        a1 = b1;
        b1 = temp;
    }

    if(a1 == 0){ // Take into consideration any number that is compared with 0
        return b1;
    } else if( b1 == 0){
        return a1;
    }

    int remainder, multipier, ans; // Introduces the core components of the algorithmm
    remainder = -1;

    if((a1 % b1) == 0){ // Finds gcd when A1 is a multiple of B1 before Euclidean Algorithm 
        return b1;
    }

    while(remainder != 0){ // Main part of algorithm - shifts numbers until remainder is 0
      remainder = a1 % b1;
      multipier = a1/b1;
      a1 = b1;
      b1 = remainder;
      if(remainder != 0){ // Updates and saves every remainder value until the remainder is zero
          ans = remainder;
      }
    } 
    
return ans;

}

int main(){

    int a,b;
    cout << "Enter the first integer you want to compute: " << endl;
    cin >> a;
    cout << "Enter the second integer you want to compute: " << endl;
    cin >> b;

    cout << "The greatest common divisor of " << a << " and " << b << " is: " << gcd(a,b) << endl;

    return 0;
}