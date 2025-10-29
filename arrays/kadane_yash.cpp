// kadane_yash.cpp
// Kadane's algorithm to compute maximum subarray sum.
// Input: n\n a1 a2 ... an
// Output: single integer (maximum subarray sum)
// Example: Input: 9\n-2 1 -3 4 -1 2 1 -5 4\nOutput: 6
// Complexity: O(n) time, O(1) extra space

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    long long best = LLONG_MIN, cur = 0;
    for(int i=0;i<n;i++){
        long long x; cin >> x;
        if(i==0){
            cur = x;
            best = x;
        } else {
            // either start new subarray at x or extend previous
            cur = max(x, cur + x);
            best = max(best, cur);
        }
    }
    cout << best << '\n';
    return 0;
}
