// majority_n_by_3_yash.cpp
// Find all elements that appear more than floor(n/3) times (Boyer-Moore extension)
// Input: n\n a1 a2 ... an
// Output: elements separated by spaces (or "None" if none)
// Example: Input: 7\n3 2 3 2 2 1 1\nOutput: 2
// Complexity: O(n)

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<long long> a(n); for(int i=0;i<n;i++) cin>>a[i];
    long long cand1=0, cand2=0; int cnt1=0, cnt2=0;
    for(auto x: a){
        if(cnt1 && x==cand1) cnt1++;
        else if(cnt2 && x==cand2) cnt2++;
        else if(cnt1==0){ cand1=x; cnt1=1; }
        else if(cnt2==0){ cand2=x; cnt2=1; }
        else { cnt1--; cnt2--; }
    }
    vector<long long> res;
    int c1=0,c2=0; for(auto x: a){ if(x==cand1) c1++; if(x==cand2) c2++; }
    if(c1>n/3) res.push_back(cand1);
    if(cand2!=cand1 && c2>n/3) res.push_back(cand2);
    if(res.empty()) cout << "None\n";
    else { for(size_t i=0;i<res.size();++i){ if(i) cout<<' '; cout<<res[i]; } cout<<'\n'; }
    return 0;
}
