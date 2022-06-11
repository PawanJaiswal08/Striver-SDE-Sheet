#include<bits/stdc++.h>
using namespace std;

int majorityElement(int arr[], int n) {
    int num = -1;
    int count = 0;

    for(int i=0; i<n; i++){
        if(count == 0){
            num = arr[i];
            // count++;
        }
        if(arr[i] == num){
            count++;
        }
        else
            count--;
    }

    count = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == num)
            count++;
    }

    if(count > floor(n/2))
        return num;
    else
        return -1; 
}

int main(){
    int arr[] = {5, 2, 0, 0};
    cout << majorityElement(arr,4);
    return 0;
}