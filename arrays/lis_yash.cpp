// lis_yash.cpp
// Longest Increasing Subsequence length (n log n)
// Input: n\n a1 a2 ... an
// Output: length
// Example: Input: 6\n10 9 2 5 3 7\nOutput: 3 (2,3,7)
// Complexity: O(n log n)

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    vector<long long> dp;
    for(auto x: a){
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it==dp.end()) dp.push_back(x);
        else *it = x;
    }
    cout << (int)dp.size() << '\n';
    return 0;
}
