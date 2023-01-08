// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 
  
// Array to store the numbers used 
// to form the required sum 
int dp[200]; 
int count = 0; 
  
// Function to print the array which contains 
// the unique partitions which are used 
// to form the required sum 
void print(int idx) 
{ 
    for (int i = 1; i < idx; i++) { 
        cout << dp[i] << " "; 
    } 
    cout << endl; 
} 
  
// Function to find all the unique partitions 
// remSum = remaining sum to form 
// maxVal is the maximum number that 
// can be used to make the partition 
void solve(int remSum, int maxVal, int idx, int& count) 
{ 
  
    // If remSum == 0 that means the sum 
    // is achieved so print the array 
    if (remSum == 0) { 
        print(idx); 
        count++; 
        return; 
    } 
  
    // i will begin from maxVal which is the 
    // maximum value which can be used to form the sum 
    for (int i = maxVal; i >= 1; i--) { 
        if (i > remSum) { 
            continue; 
        } 
        else if (i <= remSum) { 
  
            // Store the number used in forming 
            // sum gradually in the array 
            dp[idx] = i; 
  
            // Since i used the rest of partition 
            // cant have any number greater than i 
            // hence second parameter is i 
            solve(remSum - i, i, idx + 1, count); 
        } 
    } 
} 
  
// Driver code 
int main() 
{ 
    int n = 3, count = 0; 
  
    solve(n, n, 1, count); 
  
    return 0; 
} 