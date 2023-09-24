// Includes and shortcuts
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
/*
    Fibonacci function: a recursive function.
    Return the n-th fibonacci number in exponential time ( O(2^n) ) and linear space ( O(n) ).
*/
int fib(int n){
    // Base case
    if(n <= 1) return n;
    // Recursive call
    return fib(n - 1) + fib(n - 2);
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
