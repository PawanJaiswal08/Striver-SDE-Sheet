#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &arr, int n){

    if(n < 2)
        return arr;

    int i = n - 1;
    
    while(i > 0 && arr[i-1] >= arr[i])
        i--;

    // last permutation in reverse order
    if(i == 0) {
        sort(arr.begin(), arr.end());
        return arr;
    }

    // int temp = arr[i-1];
    // cout << i;

    int q = i;
    while(q < arr.size() && arr[q] > arr[i - 1]) {
        q++;
    }
    // cout << q;
    q--;
    swap(arr[i-1], arr[q]);
    sort(arr.begin() + i, arr.end());

    return arr;
}

int main(){
    vector<int> permutation = {0,1,2,5,3,3,0};
    int n = permutation.size();
    nextPermutation(permutation, n);
    for(int i=0; i<n; i++){
        cout << permutation[i] << " ";
    }
    return 0;
}