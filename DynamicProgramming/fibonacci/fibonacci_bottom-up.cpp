// Includes and shortcuts
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
/*
    Fibonacci function using DP (Dynamic programming) bottom-up: 
    An iterative function.
    Returns the n-th fibonacci number in linear time and linear space ( O(n) )
*/
int fib(int n){
    // Creating and initializing the DP array
    int dp[n + 1];
    for(int i = 0; i <= n; i++) dp[i] = (int) NULL;
    // Defining the first two fibonacci numbers
    dp[1] = 1;
    dp[2] = 2;
    // Filling the array with fibonacci numbers from 1 to n
    for(int i = 3; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
    // Returning the n-th fibonacci number
    return dp[n];
}
// Main function
int main(){
    // Asking the user to enter the index of the fibonacci number they want to find
    int n;
    cout << "Enter the index of the fibonacci number you want to find: ";
    cin >> n;
    // Outputing the result
    cout << "The " << n << "-th fibonacci number is: " << fib(n) << '\n';
}
