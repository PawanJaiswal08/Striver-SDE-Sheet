#include<bits/stdc++.h>
using namespace std;

int search(int* arr, int n, int key) {
    int start = 0;
    int end = n - 1;
    while (start <= end){
        int mid = start + (end - start)/2;
        if(arr[mid] == key)
            return 1;

        if(arr[start] <= arr[mid]){
            if(key >= arr[start] && key < arr[mid]){
                end = mid - 1;
            }
            else{
                start = mid + 1;
            }
        }
        else{
            if(key >= arr[mid+1] && key <= arr[end]){
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }
    }
    return -1;
}

int main(){
    int arr[] = {};
    cout << search(arr, 0, 4);
    return 0;
}