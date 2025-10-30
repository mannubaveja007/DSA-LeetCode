// missing_number_yash.cpp
// Given n numbers in range [0..n], find the missing number (one missing)
// Input: n (number of elements, which is actually n)\n a1 a2 ... an  (values are distinct from 0..n)
// Output: missing number
// Example: Input: 3\n0 1 3\nOutput: 2
// Complexity: O(n) time, O(1) extra

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    long long xorSum = 0; // compute xor 0..n and xor with array
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<=n;i++) xorSum ^= i;
    for(int x: a) xorSum ^= x;
    cout << xorSum << '\n';
    return 0;
}
