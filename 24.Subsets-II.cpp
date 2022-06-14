#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<int> &arr, int index, vector<int> &temp, vector<vector<int>> &ans){
    if(index == n){
        // sort(temp.begin(), temp.end());
        ans.push_back(temp);
        return;
    }

    // Include
    temp.push_back(arr[index]);
    solve(n, arr, index+1, temp, ans);
    temp.pop_back();

    // Exclude
    while(index+1 < arr.size() && arr[index]==arr[index+1]) index++;
    solve(n, arr, index+1, temp, ans);

    
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    int index = 0;
    solve(n, arr, index, temp, ans);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr = {5, 5, 3, 5};
    vector<vector<int>> ans = uniqueSubsets(arr.size(), arr);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}