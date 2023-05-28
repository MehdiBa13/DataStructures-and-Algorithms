// Includes and shortcuts
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
/*
    Fibonacci function using DP (Dynamic programming) memoization: 
    A recursive function.
    Returns the n-th fibonacci number, faster than normal recursion, in linear time ( O(n) ) and linear space ( O(n) )
    The idea of DP is to create an array to stock intermidiate values.
*/
int fib(int n){
    // Creating and initializing the DP array
    int dp[n + 1];
    for(int i = 0; i <= n; i++) dp[i] = (int) NULL;
    // Checking if we have already computed the n-th fibonacci number
    if(dp[n] != NULL) return dp[n];
    // Result variable
    int res;
    // Bae case
    if(n == 1 || n == 2) res = 1;
    // Calling the function
    else res = fib(n - 1) + fib(n - 2);
    // Storing the result in our array
    dp[n] = res;
    // Returning the result
    return res;
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
