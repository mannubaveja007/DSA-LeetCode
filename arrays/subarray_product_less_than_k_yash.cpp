// subarray_product_less_than_k_yash.cpp
// Count contiguous subarrays where product < k
// Input: n k\n a1 a2 ... an
// Output: single integer (count)
// Example: Input: 4 10\n10 5 2 6\nOutput: 8
// Complexity: O(n) using sliding window

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; long long k; if(!(cin>>n>>k)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    if(k <= 1){ cout << 0 << '\n'; return 0; }
    long long prod = 1; int left=0; long long ans=0;
    for(int right=0; right<n; ++right){
        prod *= a[right];
        while(prod >= k && left <= right){ prod /= a[left++]; }
        ans += (right - left + 1);
    }
    cout << ans << '\n';
    return 0;
}
