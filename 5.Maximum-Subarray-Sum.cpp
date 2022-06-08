#include<bits/stdc++.h>
using namespace std;

long long maxSubarraySum(int arr[], int n){
    long long ans = INT_MIN;
    long long sum = 0;
    
    for(int i=0; i<n; i++){
        sum = sum + arr[i];
        ans = max(ans, sum);
        if(sum < 0)
            sum = 0;
    }
    
    if(ans < 0)
        return 0;
    
    return ans;
}

int main(){
    int arr[] = {1, 2, 7, -4, 3, 2, -10, 9, 1};
    long long ans = maxSubarraySum(arr, 9);
    cout << ans;
    return 0;
}