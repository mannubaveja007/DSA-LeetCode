// sliding_window_max_yash.cpp
// Given array nums and window size k, print max for every contiguous subarray of size k
// Input: n k\n a1 a2 ... an
// Output: n-k+1 numbers (maxes)
// Example: Input: 8 3\n1 3 -1 -3 5 3 6 7\nOutput: 3 3 5 5 6 7
// Complexity: O(n) time using deque

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,k; if(!(cin>>n>>k)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    deque<int> dq; // store indices, decreasing values
    for(int i=0;i<n;i++){
        while(!dq.empty() && dq.front() <= i-k) dq.pop_front();
        while(!dq.empty() && a[dq.back()] <= a[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k-1){
            if(i>k-1) cout << ' ';
            cout << a[dq.front()];
        }
    }
    cout << '\n';
    return 0;
}
