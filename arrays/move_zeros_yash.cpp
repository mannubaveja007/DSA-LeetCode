// move_zeros_yash.cpp
// Move all zeros to the end while maintaining the relative order of non-zero elements.
// Input: n\n a1 a2 ... an
// Output: transformed array (non-zero order preserved, zeros at end)
// Example: Input: 6\n0 1 0 3 12 0\nOutput: 1 3 12 0 0 0
// Complexity: O(n) time, O(1) extra (in-place)

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if(!(cin >> n)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    // Two-pointer: pos tracks where next non-zero should go
    int pos = 0;
    for(int i=0;i<n;i++){
        if(a[i] != 0){
            a[pos++] = a[i];
        }
    }
    // Fill remainder with zeros
    while(pos < n) a[pos++] = 0;

    for(int i=0;i<n;i++){
        if(i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
    return 0;
}
