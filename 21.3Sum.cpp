#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> findTriplets(vector<int>& arr, int n, int target) {
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for(int i=0; i<n-2; i++){
        int start = i+1;
        int end = n-1;
        while(start < end){
            if((arr[start] + arr[end]) == (target - arr[i])){
                
                ans.push_back({arr[i], arr[start], arr[end]});

                int x = arr[start];
                int y = arr[end];
                //skipping the same returned elements of left and right 
                // if they are present in duplicate form
                while(start < end && arr[start] == x){
                    start++;
                }
                while(start < end && arr[end] == y){
                    end--;
                }
            }
            else if((arr[start] + arr[end]) > (target - arr[i])){
                end--;
            }
            else{
                start++;
            }
        }
        // skipping duplicate elements for for loop
        while(i+1<n && arr[i]==arr[i+1]){
            i++;
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {10, 5, 5, 5, 2};
    int n = arr.size(); 
    int target = 12;
    vector<vector<int>> ans = findTriplets(arr, n, target);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j<ans[i].size(); j++){
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}