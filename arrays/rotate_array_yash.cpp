// rotate_array_yash.cpp
// Rotate an array to the right by k positions (in-place).
// Input (single test):
//  n k
//  a1 a2 ... an
// Output:
//  rotated array elements on one line
// Example:
//  Input: 5 2\n1 2 3 4 5\nOutput: 4 5 1 2 3
// Complexity: O(n) time, O(1) extra space (ignoring input storage)

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; long long k;
    if(!(cin >> n >> k)) return 0; // if input missing, exit gracefully
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    if(n == 0){ // empty array -> nothing to print
        cout << '\n';
        return 0;
    }

    // Normalize k to [0, n-1]
    k %= n;
    if(k < 0) k += n; // support negative k if provided

    // Reverse trick: reverse all, reverse first k, then reverse rest
    reverse(a.begin(), a.end());
    reverse(a.begin(), a.begin() + k);
    reverse(a.begin() + k, a.end());

    // Print result in single line
    for(int i=0;i<n;i++){
        if(i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
