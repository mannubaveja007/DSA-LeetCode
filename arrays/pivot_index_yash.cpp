// pivot_index_yash.cpp
// Find pivot index where sum of numbers to the left equals sum to the right.
// Input: n\n a1 a2 ... an
// Output: index (0-based) of pivot or -1 if none (prints first pivot found)
// Example: Input: 3\n1 7 3\nOutput: -1
// Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    long long total=0; for(auto v: a) total += v;
    long long left=0;
    for(int i=0;i<n;i++){
        if(left == total - left - a[i]){ cout << i << '\n'; return 0; }
        left += a[i];
    }
    cout << -1 << '\n';
    return 0;
}
