/*------------------ Segment Tree - 1-indexed ------------------*/
/*
	Basic Segment tree - supports point updates.
	Operation: Sum (just as an example)
	Build time complexity: O(n log n)
	Sum Query time complexity: O(log n)
	Point update time complexity: O(log n)
*/
// Includes and shortcuts
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define pb push_back
#define sz(a) sizeof(a) / sizeof(a[0])
#define F first
#define S second
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const int MAXN = 2e6;
// Defining the array and the segment tree globally
vector<int> a(MAXN + 1), seg(4 * MAXN + 1);
// Build function
void build(int i, int l, int r){
	// Base case
	if(l == r){
		seg[i] = a[l];
		return;
	}
	// Building the segment tree
	int mid = l + (r - l) / 2;
	build(i << 1, l, mid);
	build(i << 1 | 1, mid + 1, r);
	// Assigning each node to its value
	seg[i] = seg[i << 1] + seg[i << 1 | 1];;
}
// Query function: returns the sum of elements in range [ql...qr]
int sum(int i, int l, int r, int ql, int qr){
	// Total overlap of the range of the current node [l...r]
	// and [ql...qr]
	if(l >= ql && r <= qr) return seg[i];
	// No overlap between [l...r] and [ql...qr]
	if(r < ql || l > qr) return 0;
	// Partial overlap between [l..r] and [ql...qr]
	int mid = l + (r - l) / 2;
	int a = sum(i << 1, l, mid, ql, qr);
	int b = sum(i << 1 | 1, mid + 1, r, ql, qr);
	return a + b;
}
// Update element at position K to U
void update(int i, int l, int r, int k, int u){
	// Base case
	if(l == r){
		seg[i] = u;
		return;
	}
	// Updating
	int mid = l + (r - l) / 2;
	if(k <= mid) update(i << 1, l, mid, k, u);
	else update(i << 1 | 1, mid + 1, r, k, u);
	seg[i] = seg[i << 1] + seg[i << 1 | 1];
}
// Main function
int main(){
	// Fast-IO (optional)
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	// Inputing the size of the array and the number of queries
	int n, q;
	cin >> n >> q;
	// Inputing the elements of the array
	for(int i = 1; i <= n; i++) cin >> a[i];
	// Building the segment tree
	build(1, 1, n);
	// Inputing the queries
	while(q--){
		int o; // Type of the query (update / sum)
		cin >> o;
		if(o == 1){ // Update element at position k to u
			int k, u;
			cin >> k >> u;
			update(1, 1, n, k, u);
		} else{ // Sum in range [ql...qr]
			int ql, qr;
			cin >> ql >> qr;
			cout << sum(1, 1, n, ql, qr) << '\n';
		}
	}
	return 0;
}