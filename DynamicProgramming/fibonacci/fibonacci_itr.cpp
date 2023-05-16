// Includes and shortcuts
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
/*
    PS: This function does not use DP.
    I added it because it's the most
    efficient way to compute the n-th fibonacc number.
    It's an iterative function.
*/
int fib(int n){
    // Defining the values of the first two fibonacci number and declaring the result variable
    int a = 1, b = 1, res;
    // Base case
    if(n == 0) res = 0;
    else if(n == 1 || n == 2) res = 1;
    // Updating the values of the two previous fibonacci numbers and setting the result to their sum
    else for(int i = 3; i <= n; i++){
        res = a + b;
        b = a;
        a = res;
    }
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
