#include <bits/stdc++.h> 
using namespace std;

bool binarySearch(vector<vector<int>> & arr, int start, int end, int index, int target){
    if(start<=end){
        int mid = start + (end - start)/2;
        
        if(target == arr[index][mid])
            return true;
        if(target < arr[index][mid])
            return binarySearch(arr, start, mid, index, target);
        else
            return binarySearch(arr, mid+1, end, index, target);
    }
    return false;
}

bool findTargetInMatrix1(vector<vector<int>> & arr, int m, int n, int target){
    for(int i=0; i<m; i++){
        if(target == arr[i][0])
            return true;
        
        if(target == arr[i][n-1])
            return true;
            
        if(target > arr[i][0] && target < arr[i][n-1]){
            bool ans = binarySearch(arr, 0, n-1, i, target);
            if(ans){
                return true;
            };
        }
    }
    return false;
}

bool findTargetInMatrix(vector<vector<int>> & arr, int m, int n, int target){
    for(int i=0; i<m; i++){
        if(target == arr[i][0])
            return true;
        
        if(target == arr[i][n-1])
            return true;
            
        if(target > arr[i][0] && target < arr[i][n-1]){
            for(int j=0; j<n; j++){
                if(target == arr[i][j])
                    return true;
            }
        }
    }
    return false;
}

int main(){
    vector<vector<int>> arr = {{1,1},{4,8}};
    cout << findTargetInMatrix(arr,2,2,8);
    return 0;
}