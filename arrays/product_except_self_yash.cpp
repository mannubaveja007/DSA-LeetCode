// product_except_self_yash.cpp
// Given an array nums, return an array answer such that answer[i] is the product
// of all the elements of nums except nums[i]. Do it without division and in O(n).
// Input: n\n a1 a2 ... an
// Output: n numbers (product except self)
// Example: Input: 4\n1 2 3 4\nOutput: 24 12 8 6
// Complexity: O(n) time, O(1) extra (output not counted)

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    vector<long long> ans(n,1);
    long long left = 1;
    for(int i=0;i<n;i++){
        ans[i] = left;
        left *= a[i];
    }
    long long right = 1;
    for(int i=n-1;i>=0;i--){
        ans[i] *= right;
        right *= a[i];
    }
    for(int i=0;i<n;i++){
        if(i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';
    return 0;
}
