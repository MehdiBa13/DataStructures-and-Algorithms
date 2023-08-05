// Includes and shortcuts
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
/*
    Fibonacci function: an iterative function (Optimization of the DP bottom-up, it's still considered a DP solution, since you use the sub-problems)
    Returns the n-th fibonacci number in linear time ( O(n) ) and constant space ( O(1) )
*/
int fib(int n){
    // Defining the values of the first two fibonacci number and declaring the result variable
    int a = 0, b = 1, res;
    // Base cases
    if(n <= 1) return n;
    // Updating the values of the two previous fibonacci numbers and setting the result to their sum
    for(int i = 2; i <= n; i++){
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
