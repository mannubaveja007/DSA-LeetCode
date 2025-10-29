// longest_subarray_sum_divisible_k_yash.cpp
// Find length of longest subarray with sum divisible by k
// Input: n k\n a1 a2 ... an
// Output: single integer (length)
// Example: Input: 6 3\n2 7 6 1 4 5\nOutput: 4 (subarray [7,6,1] length 3? but example simplified)
// Complexity: O(n) using prefix mod map

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; long long k; if(!(cin>>n>>k)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<long long,int> first; first.reserve(n*2);
    long long sum=0; int best=0; first[0]=-1;
    for(int i=0;i<n;i++){
        sum += a[i];
        long long m = ((sum % k) + k) % k;
        if(first.find(m)==first.end()) first[m]=i;
        else best = max(best, i - first[m]);
    }
    cout << best << '\n';
    return 0;
}
