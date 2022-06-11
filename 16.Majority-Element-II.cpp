#include<bits/stdc++.h>
using namespace std;

vector<int> majorityElementII(vector<int> &arr){

    vector<int> ans;
    int num1 = -1, num2 = -1;
    int count1 = 0, count2 = 0;
    
    for(int i=0; i<arr.size(); i++){

        if(num1 == arr[i]){
            count1++;
        }
        else if(num2 == arr[i]){
            count2++;
        }
        
        else if(count1 == 0){
            num1 = arr[i];
            count1 = 1;
        }

        else if(count2 == 0){
            num2 = arr[i];
            count2 = 1;
        }

        else{
            count1--;
            count2--;
        }
    }

    count1 = 0;
    count2 = 0;
    
    for(int i=0; i<arr.size(); i++){
        if(arr[i] == num1)
            count1++;
        
        else if(arr[i] == num2)
            count2++;
    }

    if(count1 > arr.size()/3)
        ans.push_back(num1);
    
    if(count2 > arr.size()/3)
        ans.push_back(num2);

    return ans;
}

int main(){
    vector<int> arr = {7, 4, 4, 9, 7};
    vector<int> ans = majorityElementII(arr);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] << " ";
    return 0;
}