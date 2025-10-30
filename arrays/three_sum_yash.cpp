// three_sum_yash.cpp
// Find all unique triplets in the array which gives the sum of zero.
// Input: n\n a1 a2 ... an
// Output: each unique triplet on its own line (three numbers separated by spaces),
// triplets printed in non-decreasing order within the triplet and lexicographic order between triplets.
// Example: Input: 6\n-1 0 1 2 -1 -4\nOutput:\n-1 -1 2\n-1 0 1
// Complexity: O(n^2) time

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    sort(a.begin(), a.end());
    vector<array<long long,3>> res;
    for(int i=0;i<n;i++){
        if(i>0 && a[i]==a[i-1]) continue;
        int l=i+1, r=n-1;
        while(l<r){
            long long s = a[i]+a[l]+a[r];
            if(s==0){
                res.push_back({a[i],a[l],a[r]});
                long long lv=a[l], rv=a[r];
                while(l<r && a[l]==lv) l++;
                while(l<r && a[r]==rv) r--;
            } else if(s<0) l++;
            else r--;
        }
    }
    // print
    for(auto &t: res){
        cout << t[0] << ' ' << t[1] << ' ' << t[2] << '\n';
    }
    return 0;
}
