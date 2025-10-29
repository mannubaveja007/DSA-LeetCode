// longest_consecutive_yash.cpp
// Given an unsorted array of integers, return the length of the longest consecutive elements sequence.
// Input: n\n a1 a2 ... an
// Output: single integer (length)
// Example: Input: 6\n100 4 200 1 3 2\nOutput: 4  (sequence: 1,2,3,4)
// Complexity: O(n) average expected using unordered_set

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    unordered_set<long long> s; s.reserve(n*2);
    vector<long long> a(n); for(int i=0;i<n;i++){cin>>a[i]; s.insert(a[i]);}
    int best = 0;
    for(long long x: s){
        if(s.find(x-1) == s.end()){
            long long cur = x;
            int len = 1;
            while(s.find(cur+1) != s.end()){
                cur++; len++;
            }
            best = max(best, len);
        }
    }
    cout << best << '\n';
    return 0;
}
