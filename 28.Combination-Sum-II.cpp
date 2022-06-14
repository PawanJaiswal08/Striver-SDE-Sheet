#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, int target, int index, vector<int> &temp, vector<vector<int>> &ans){
    if(target == 0){
        ans.push_back(temp);
        return;
    }

    if(target < 0 || index >= arr.size()){
        return;
    }

    for(int i=index; i<arr.size(); i++){

        if((i > index) && (arr[i] == arr[i-1]))
            continue;
        
        if(arr[i] > target)
            break;

        temp.push_back(arr[i]);
        solve(arr, target-arr[i], i+1, temp, ans);
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target){
	sort(arr.begin(), arr.end());
    // for(int i=0; i<arr.size(); i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    vector<int> temp;
    vector<vector<int>> ans;
    int index = 0;
    solve(arr, target, index, temp, ans);
    return ans;
}

int main(){
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> ans = combinationSum2(arr, 7, 8);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}