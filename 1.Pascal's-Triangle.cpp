// Pascal's Triangle
#include <bits/stdc++.h>
using namespace std;

vector<vector<long long int>> printPascal(int n) {
    vector<vector<long long int>> r(n);

    for(int i=0; i<n; i++){
        r[i].resize(i+1);
        r[i][0] = r[i][i] = 1;
        for(int j=1; j<i; j++){
            r[i][j] = r[i-1][j-1] + r[i-1][j];
        }
    }

    return r;
}

int main(){
    vector<vector<long long int>> ans = printPascal(5);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout<< ans[i][j] << " "; 
        }
        cout<< endl;
    }
    return 0;
}