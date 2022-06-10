#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> pairSum(vector<int> &arr, int target){
    vector<vector<int>> ans;
    for(int i=0; i<arr.size(); i++){
       for(int j=i+1; j<arr.size(); j++){
            if((arr[i] + arr[j]) == target){
                vector<int> temp;
                temp.push_back(min(arr[i], arr[j]));
                temp.push_back(max(arr[i], arr[j]));
                ans.push_back(temp);
            }
       }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr = {2, -3, 3, 3, -2};
    // vector<int> arr = {1,2,3,4,5};
    vector<vector<int>> ans = pairSum(arr,0);
    for (int i = 0; i < ans.size(); i++){
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
    }
    return 0;
}