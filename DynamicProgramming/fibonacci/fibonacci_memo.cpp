// Includes and shortcuts
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
/*
    Fibonacci function using DP (Dynamic programming) memoization: 
    A recursive function.
    Returns the n-th fibonacci number, faster than normal recursion, in linear time ( O(n) ) and linear space ( O(n) )
    The idea of DP is to create an array to stock repeating subproblems.
*/
int fib(int n, vector<int> &dp){
    // Checking if we have already computed the n-th fibonacci number
    if(dp[n] != -1) return dp[n];
    // Base cases
    if(n == 0) return 0;
    else if(n == 1 || n == 2) return 1;
    // Calculating the number if it's not a base case and storing it in the DP array
    dp[n] = fib(n - 1, &dp) + fib(n - 2, &dp);
    // Returning the result
    return dp[n];
}
// Main function
int main(){
    // Asking the user to enter the index of the fibonacci number they want to find
    int n;
    cout << "Enter the index of the fibonacci number you want to find: ";
    cin >> n;
    // Creating and initializating the DP array
    vector<int> dp(n + 1, -1);
    // Outputing the result
    cout << "The " << n << "-th fibonacci number is: " << fib(n, dp) << '\n';
}
