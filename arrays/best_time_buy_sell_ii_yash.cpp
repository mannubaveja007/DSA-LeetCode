// best_time_buy_sell_ii_yash.cpp
// Given prices over days, maximize profit with as many transactions as you like (no overlapping)
// Input: n\n p1 p2 ... pn
// Output: single integer (max profit)
// Example: Input: 6\n7 1 5 3 6 4\nOutput: 7 (buy1->sell2, buy3->sell5)
// Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> p(n); for(int i=0;i<n;i++) cin>>p[i];
    long long profit=0;
    for(int i=1;i<n;i++) if(p[i]>p[i-1]) profit += p[i]-p[i-1];
    cout << profit << '\n';
    return 0;
}
