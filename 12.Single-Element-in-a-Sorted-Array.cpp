#include <bits/stdc++.h> 
using namespace std;

int uniqueElement(vector<int> arr, int n){
	int ans = 0;
    for(int i = 0; i < n; i++){
        ans = ans^arr[i];
    }
    return ans;
}

int main(){
    vector<int> arr = {2, 2, 4, 4, 5, 7, 7};
    cout << uniqueElement(arr,7);
    return 0;
}