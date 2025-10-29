// majority_element_yash.cpp
// Find majority element (> n/2 occurrences) using Boyer-Moore vote algorithm
// Input: n\n a1 a2 ... an
// Output: majority element or "No majority element"
// Example: Input: 5\n3 3 4 2 3\nOutput: 3
// Complexity: O(n) time, O(1) extra space

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; if(!(cin >> n)) return 0;
    vector<long long> a(n);
    for(int i=0;i<n;i++) cin >> a[i];

    long long candidate = 0;
    int count = 0;
    for(long long x : a){
        if(count == 0){
            candidate = x;
            count = 1;
        } else if(candidate == x) count++;
        else count--;
    }

    // Verification step: candidate must actually appear > n/2 times
    int freq = 0;
    for(long long x : a) if(x == candidate) freq++;
    if(freq > n/2) cout << candidate << '\n';
    else cout << "No majority element\n";
    return 0;
}
