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
struct Seg{
	struct Node{
		int x;
		Node *l, *r;
		Node() : x(0), l(nullptr), r(nullptr){};
	};
	int n;
	Node *rt;
	Seg(int MAXN){
		n = MAXN;
		rt = new Node();
	}
	int merge(int a, int b){
		return min(a, b);
	}
	void upd(Node *i, int l, int r, int k, int u){
		if(l == r){
			i->x = u;
			return;
		}
		int mid = l + ((r - l) >> 1);
		if(k <= mid){
			if(!i->l) i->l = new Node();
			upd(i->l, l, mid, k, u);
		} else{
			if(!i->r) i->r = new Node();
			upd(i->r, mid + 1, r, k, u);
		}
		i->x = merge(i->l->x ? i->l->x : 0, i->r ? i->r->x : 0);
	}
	int query(Node *i, int l, int r, int ql, int qr){
		if(l >= ql && r <= qr) return i->x;
		if(r < ql || l > qr) return INT_MAX;
		int mid = l + ((r - l) >> 1);
		int a = query(i->l, l, mid, ql, qr);
		int b = query(i->r, mid + 1, r, ql, qr);
		return merge(a, b);
	}
	void upd(int k, int u){
		upd(rt, 1, n, k, u);
	}
	int query(int l, int r){
		return query(rt, 1, n, l, r);
	}
};
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	Seg seg(2e5);
	for(int i = 0; i < n; i++){
		cin >> a[i];
		seg.upd(i, a[i]);
	}
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int k, u;
			cin >> k >> u;
			seg.upd(k, u);
		} else{
			int l, r;
			cin >> l >> r;
			cout << seg.query(l, r) << '\n';
		}
	}
	return 0;
}