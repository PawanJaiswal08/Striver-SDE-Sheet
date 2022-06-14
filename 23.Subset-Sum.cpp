#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> &arr, vector<int> &ans, int &temp, int index){
    if(index == arr.size()){
        ans.push_back(temp);
        return;
    }

    // Exclude
    solve(arr, ans, temp, index+1);

    // Include
    temp = temp + arr[index];
    solve(arr, ans, temp, index+1);
    temp = temp - arr[index]; 
}

vector<int> subsetSum(vector<int> &arr){
    vector<int> ans;
    int temp = 0;
    int index = 0;
    solve(arr, ans, temp, index);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr = {1, 2, 3};
    vector<int> ans = subsetSum(arr);
    for(int i=0; i<ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}