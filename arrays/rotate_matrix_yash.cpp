// rotate_matrix_yash.cpp
// Rotate an n x n matrix by 90 degrees clockwise in-place.
// Input: n\n n lines each with n integers
// Output: rotated matrix (n lines)
// Example: Input: 3\n1 2 3\n4 5 6\n7 8 9\nOutput:\n7 4 1\n8 5 2\n9 6 3
// Complexity: O(n^2)

#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; if(!(cin>>n)) return 0;
    vector<vector<long long>> m(n, vector<long long>(n));
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin>>m[i][j];
    // transpose
    for(int i=0;i<n;i++) for(int j=i+1;j<n;j++) swap(m[i][j], m[j][i]);
    // reverse each row
    for(int i=0;i<n;i++) reverse(m[i].begin(), m[i].end());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j) cout<<' ';
            cout<<m[i][j];
        }
        cout<<'\n';
    }
    return 0;
}
