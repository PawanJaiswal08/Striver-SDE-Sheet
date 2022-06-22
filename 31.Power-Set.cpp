#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, vector<int> &temp, vector<vector<int>> &ans, int index){
    if(index == arr.size()){
        ans.push_back(temp);
        return;
    }

    // Exclude
    solve(arr, temp, ans, index+1);

    // Include
    temp.push_back(arr[index]);
    solve(arr, temp, ans, index+1);
    temp.pop_back();
}

vector<vector<int>> pwset(vector<int> arr){
    int index = 0;
    vector<int> temp;
    vector<vector<int>> ans;
    solve(arr, temp, ans, index);
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<vector<int>> ans = pwset(arr);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}