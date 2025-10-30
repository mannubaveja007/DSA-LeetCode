// kth_largest_yash.cpp
// Find the k-th largest element in an unsorted array
// Input: n k\n a1 a2 ... an
// Output: single number (k-th largest)
// Example: Input: 5 2\n3 2 1 5 6\nOutput: 5
// Complexity: O(n log k) using min-heap

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; if(!(cin>>n>>k)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for(auto x: a){ pq.push(x); if((int)pq.size() > k) pq.pop(); }
    cout << pq.top() << '\n';
    return 0;
}
