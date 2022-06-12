#include<bits/stdc++.h>
using namespace std;

int LongestSubsetWithZeroSum(vector<int> arr) {
    unordered_map<int ,int> mp;
    int sum = 0;
    int ans = 0;

    for(int i=0; i<arr.size(); i++){

        sum = sum + arr[i];
        if(sum == 0)
            ans = i+1;
        else{
            if(mp.find(sum) != mp.end()){
                ans = max(ans, i - mp[sum]);
            }else{
                mp[sum] = i;
            }
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {1, -1, 2, -2};
    cout << LongestSubsetWithZeroSum(arr);
    return 0;
}