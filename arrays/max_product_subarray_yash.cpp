// max_product_subarray_yash.cpp
// Find the contiguous subarray within an array (containing at least one number) which has the largest product.
// Input: n\n a1 a2 ... an
// Output: single number (maximum product)
// Example: Input: 3\n2 3 -2\nOutput: 6
// Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    long long maxProd=a[0], minProd=a[0], ans=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<0) swap(maxProd, minProd);
        maxProd = max(a[i], maxProd * a[i]);
        minProd = min(a[i], minProd * a[i]);
        ans = max(ans, maxProd);
    }
    cout << ans << '\n';
    return 0;
}
