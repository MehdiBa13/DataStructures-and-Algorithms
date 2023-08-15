// Includes and shortcuts
#include <bits/stdc++.h>
#define pb push_back
using namespace std;
using ll = long long;
/* 
    Binary Search function:
    returns the index of the researched element x in a, and -1 if it wasn't found.
    n is the size of the array.
    ( Time complexity: O(log2 n) )
*/
int binarySearch(int a[], int x, int n){
    // Defining 'right' and 'left' variables
    int l = 0, r = n - 1;
    // We'll be searching in the interval ['right' ... 'left']
    while(l <= r){
        // Calculating the middle of the arrau
        int mid = l + (r - l) / 2;
        /*
            If the element at the middle is equal to the element
            we're searching for, the it's index is the middle.
        */
        if(a[mid] == x) return mid;
        /*
            If the element at the middle is bigger than the element
            we're searching for, then x is less than the element at the
            middle. So we won't search after it, the 'right' variable will
            be equal to the element before the middle.
        */
        else if(a[mid] > x) r = mid - 1;
        /*
            If the element at the middle is less than the element
            we're searching for, then x is bigger than the element at the
            middle. So we won't search before it, the 'left' variable will
            be equal to the element after the middle.
        */
        else l = mid + 1;
    }
    // If no value was returned, then the element wasn't found
    return -1;
}
// Main function
int main(){
    // Asking the user to enter the size of array
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    // Asking the user to enter the elements of the array
    int a[n];
    cout << "Enter the elements of the array (space separated): ";
    for(int i = 0; i < n; i++) cin >> a[i];
    // Asking the user to enter the value they're searching for
    int x;
    cout << "Enter the value you're searching for: ";
    cin >> x;
    // Calling the binary search function
    int index = binarySearch(a, x, n);
    if(index == -1) cout << "The element wasn't found in that array!\n";
    else cout << "The element you're searching for is at index: " << index << '\n';
}
