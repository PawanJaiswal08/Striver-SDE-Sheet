#include<bits/stdc++.h>
using namespace std;

// approach 1
int binary_search(vector<int> &arr, int start, int end, int target){
    if(start<=end){
        int mid = start + (end - start)/2;
        
        if(target == arr[mid])
            return mid;
        if(target < arr[mid])
            return binary_search(arr, start, mid, target);
        else
            return binary_search(arr, mid+1, end, target);
    }
    return -1;
}

string fourSum1(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());
    string res = "No";
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            for(int k=j+1; k<n-1; k++){
                target = target - (arr[i] + arr[j] + arr[k]);
                int index = binary_search(arr, k+1, n-1, target);
                if(index != -1){
                    res="Yes";
                    return res;
                }
            }
        }
    }
    return res;
}

// Approach 2 (Getting TLE)
string fourSum2(vector<int> arr, int target, int n) {
    sort(arr.begin(), arr.end());
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            int newtarget = target - (arr[i] + arr[j]);
            int start = j+1, end = n-1;
            while(start < end){
                if(arr[start] + arr[end] == newtarget)
                    return "Yes";
                else if(arr[start] + arr[end] < newtarget)
                    start++;
                else 
                    end--;
            }
        }
    }
    return "No";
}

// Approach 3 (Getting TLE)
string fourSum(vector<int> arr, int target, int n) {
    // sort(arr.begin(), arr.end());
    unordered_map<int, pair<int, int>> mp;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int sum = arr[i] + arr[j];
            mp[sum] = {i, j};
        }
    }
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int leftTarget = target - (arr[i] + arr[j]);
            if(mp.find(leftTarget) != mp.end()){
                pair<int, int> it = mp[leftTarget];
                    int k = it.first;
                    int l = it.second;
                    if(i != k && i != l && j != k && j != l)
                        return "Yes";
            }
        }
    }
    return "No";
}

int main(){
    vector<int> arr = {-2, 12, -1, 1, 20, 1};
    int n = 6;
    int target = 20;
    string ans = fourSum(arr, target, n);
    cout << ans;
    return 0;
}