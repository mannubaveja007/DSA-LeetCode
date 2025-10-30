// subarray_sum_k_yash.cpp
// Count number of continuous subarrays whose sum equals k
// Input: n k\n a1 a2 ... an
// Output: single integer (count)
// Example: Input: 5 0\n1 -1 0 0 0\nOutput: 6
// Complexity: O(n) time using hashmap

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; long long k; if(!(cin>>n>>k)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<long long,int> cnt; cnt.reserve(n*2);
    long long sum=0; long long ans=0; cnt[0]=1;
    for(int i=0;i<n;i++){
        sum += a[i];
        if(cnt.find(sum-k) != cnt.end()) ans += cnt[sum-k];
        cnt[sum]++;
    }
    cout << ans << '\n';
    return 0;
}
