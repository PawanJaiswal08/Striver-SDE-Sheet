#include<bits/stdc++.h>
using namespace std;

int subarraysXor(vector<int> &arr, int x){
    int count = 0;
    map<int, int> mp;
    int xr = 0;

    for(int i=0; i<arr.size(); i++){
        xr = xr ^ arr[i];

        if(xr == x){
            count++;
        }

        if(mp.find(xr ^ x) != mp.end())
            count += mp[xr ^ x];

        mp[xr] += 1; 
    }

    return count;
}

int main(){
    vector<int> arr = {5, 3, 8, 3, 10};
    cout << subarraysXor(arr, 8);
    return 0;
}