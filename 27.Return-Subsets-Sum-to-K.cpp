#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> arr, int k, int index, vector<int> &temp, vector<vector<int>> &ans){
    if(index == arr.size()){
        int sum = 0;
        for(int i=0; i<temp.size(); i++){
            sum = sum + temp[i];
        }
        if(sum == k){
            ans.push_back(temp);
        }
        return;
    }

    // Exclude
    solve(arr, k, index+1, temp, ans);

    // Include
    temp.push_back(arr[index]);
    solve(arr, k, index+1, temp, ans);
    temp.pop_back();
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k){
    vector<int> temp;
    vector<vector<int>> ans;
    int index = 0;
    solve(arr, k, index, temp, ans);
    return ans;
}

int main(){
    vector<int> arr = {5, -1, 8, 2, 7, 0};
    vector<vector<int>> ans = findSubsetsThatSumToK(arr, 6, 7);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}