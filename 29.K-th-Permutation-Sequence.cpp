#include<bits/stdc++.h>
using namespace std;

// Approach 1
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
string kthPermutation1(int n, int k) {
    string s = "";
    for(int i=0; i<n; i++){
       s = s + to_string(i+1);
    }
    vector<string> ans;
    solve(s, ans, 0);
    return ans[k-1];
}


// Apporach 2
string kthPermutation(int n, int k) {
    k = k - 1;

    vector<int> nums;
    string ans = "";
    
    int fact = 1;
    for(int i=1; i<n; i++){
        fact = fact * i;
        nums.push_back(i);
    }
    
    nums.push_back(n);

    while(true){
        ans = ans + to_string(nums[k/fact]);
        nums.erase(nums.begin() + k/fact);
        if(nums.size() == 0)
            break;
        k = k % fact;
        fact = fact / nums.size();
    }

    return ans;
}


int main(){
    int n = 3, k = 6;
    cout << kthPermutation(n, k);
    return 0;
}