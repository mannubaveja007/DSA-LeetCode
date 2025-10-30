// subarray_xor_k_yash.cpp
// Count subarrays with XOR equal to k
// Input: n k\n a1 a2 ... an
// Output: single integer (count)
// Example: Input: 5 2\n4 2 2 6 4\nOutput: 2 (subarrays [2],[2] at indexes 2 and 3)
// Complexity: O(n) using prefix xor + hashmap

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; long long k; if(!(cin>>n>>k)) return 0;
    unordered_map<long long,int> cnt; cnt.reserve(n*2);
    long long pref = 0; long long ans = 0; cnt[0]=1;
    for(int i=0;i<n;i++){
        long long x; cin>>x;
        pref ^= x;
        long long need = pref ^ k;
        if(cnt.find(need) != cnt.end()) ans += cnt[need];
        cnt[pref]++;
    }
    cout << ans << '\n';
    return 0;
}
