#include <bits/stdc++.h> 
using namespace std;

int findDuplicate(vector<int> &arr, int n){
    sort(arr.begin(), arr.end());
    // for(int i=0; i<n; i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    int ans = -1;
    for(int i=0; i<n-1; i++){
        ans = arr[i] ^ arr[i+1];
        if(ans == 0)
            return arr[i];
    }
}


int main(){
    vector<int> arr = {4, 5, 8, 4, 6, 1, 2, 3, 7, 4};
    cout << findDuplicate(arr,10);
    return 0;
}