// range_sum_queries_yash.cpp
// Answer q range sum queries (1-based inclusive indices) using prefix sums
// Input: n q\n a1 a2 ... an\n q lines each: l r  (1-based inclusive)
// Output: q lines, each containing the sum for that query
// Example:\n// Input:\n// 5 3\n// 1 2 3 4 5\n// 1 3\n// 2 5\n// 3 3\n// Output:\n// 6\n// 14\n// 3
// Complexity: O(n + q)

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    if(!(cin >> n >> q)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    vector<long long> pref(n+1, 0);
    for(int i=0;i<n;i++) pref[i+1] = pref[i] + a[i];

    for(int i=0;i<q;i++){
        int l, r; cin >> l >> r; // expecting 1-based inclusive indices
        // clamp indices to valid range to prevent UB when input is out of expected bounds
        if(l < 1) l = 1;
        if(r > n) r = n;
        if(l > r){ cout << 0 << '\n'; continue; }
        cout << (pref[r] - pref[l-1]) << '\n';
    }
    return 0;
}
