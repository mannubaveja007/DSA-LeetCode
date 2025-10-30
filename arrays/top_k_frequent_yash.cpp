// top_k_frequent_yash.cpp
// Return the k most frequent elements from the array
// Input: n k\n a1 a2 ... an
// Output: k elements (order may vary)
// Example: Input: 6 2\n1 1 1 2 2 3\nOutput: 1 2
// Complexity: O(n log k)

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; if(!(cin>>n>>k)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    unordered_map<long long,int> cnt; cnt.reserve(n*2);
    for(auto x: a) cnt[x]++;
    priority_queue<pair<int,long long>, vector<pair<int,long long>>, greater<pair<int,long long>>> pq;
    for(auto &p: cnt){
        pq.push({p.second, p.first});
        if((int)pq.size() > k) pq.pop();
    }
    vector<long long> res;
    while(!pq.empty()){ res.push_back(pq.top().second); pq.pop(); }
    reverse(res.begin(), res.end());
    for(size_t i=0;i<res.size();++i){ if(i) cout<<' '; cout<<res[i]; }
    cout<<'\n';
    return 0;
}
