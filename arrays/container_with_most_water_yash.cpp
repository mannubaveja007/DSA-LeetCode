// container_with_most_water_yash.cpp
// Given n lines at positions 0..n-1 with heights ai, find max area contained between two lines.
// Input: n\n a1 a2 ... an
// Output: single integer (max area)
// Example: Input: 9\n1 8 6 2 5 4 8 3 7\nOutput: 49
// Complexity: O(n) two-pointer

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    int l=0, r=n-1; long long best=0;
    while(l<r){
        best = max(best, (long long)min(a[l], a[r]) * (r-l));
        if(a[l] < a[r]) l++; else r--;
    }
    cout << best << '\n';
    return 0;
}
