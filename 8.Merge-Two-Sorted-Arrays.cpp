#include <bits/stdc++.h> 
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	vector<int> ans;
    int i = 0, j = 0;
    while(i<m && j<n){
        if(arr1[i] <= arr2[j])
            ans.push_back(arr1[i++]);
        else
            ans.push_back(arr2[j++]);
    }

    while(i<m){
        ans.push_back(arr1[i++]);
    }

    while(j<n){
        ans.push_back(arr2[j++]);
    }
    return ans;
}

int main(){
    vector<int> arr1 = {3, 6, 9};
    vector<int> arr2 = {4, 10};
    vector<int> ans = ninjaAndSortedArrays(arr1, arr2, 3, 2);
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    return 0;
}