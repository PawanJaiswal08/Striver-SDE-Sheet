#include<bits/stdc++.h>
using namespace std;

void solve(string &s, vector<string> &ans, int index){
    if(index == s.size()){
        ans.push_back(s);
        return;
    }

    for(int i=index; i<s.size(); i++){
        swap(s[index], s[i]);
        solve(s, ans, index+1);
        swap(s[index], s[i]);
    }
}

vector<string> findPermutations(string &s) {
    vector<string> ans;
    solve(s, ans, 0);
    return ans;
}

int main(){
    string s = "cba";
    vector<string> ans = findPermutations(s);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << endl;
    }
    
    return 0;
}