#include<bits/stdc++.h>
using namespace std;

// Approach 1
pair<int,int> missingAndRepeating1(vector<int> &arr, int n){
    pair<int,int> ans;
    vector<int> temp;

    for(int i=0; i<n+1; i++){
        temp.push_back(0);
    }
    
    for(int i=0; i<n; i++){
        temp[arr[i]] = temp[arr[i]] + 1;
    }
    for(int i=1; i<n+1; i++){
        if(temp[i] == 0)
            ans.first = i;
        if(temp[i] > 1)
            ans.second = i;
    }
    return ans;
}

// Approach 2
pair<int,int> missingAndRepeating(vector<int> &arr, int n){
    
    pair<int,int> ans;
    int arraySum = 0, arrayPowerSum = 0;

    for(int i=0; i<n; i++){
        arraySum = arraySum + arr[i];
    }

    for(int i=0; i<n; i++){
        arrayPowerSum = arrayPowerSum + arr[i]*arr[i];
    }

    int sum = (n*(n+1))/2;
    int powerSum = (n*(n+1)*((2*n)+1))/6;

    sum = sum - arraySum;
    powerSum = powerSum - arrayPowerSum;

    ans.first = ((powerSum/sum) + sum)/2;
    ans.second = ans.first - sum;

    return ans;
}

int main(){
    vector<int> arr = {1, 3, 5, 4, 4};
    int n = 5;

    pair<int,int> ans = missingAndRepeating(arr, n);
    cout << ans.first << " " << ans.second << endl;
    return 0;
}