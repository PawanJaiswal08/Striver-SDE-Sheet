// Rotate Matrix Elements Clockwise
#include <bits/stdc++.h> 
using namespace std;

void solve(vector<vector<int>> &arr, int n, int m, int startRow, int startCol, int lastRow, int lastCol){

    if(startRow >= lastRow || startCol >= lastCol)
        return;

    int temp = arr[startRow][lastCol];
    // cout<<temp<<endl;
    
    for(int j=lastCol; j>startCol; j--){
        arr[startRow][j] = arr[startRow][j-1];
    }

    for(int i=startRow; i<lastRow; i++){
        arr[i][startCol] = arr[i+1][startCol];
    }

    for(int j=startCol; j<lastCol; j++){
        arr[lastRow][j] = arr[lastRow][j+1];
    }

    for(int i=lastRow; i>startRow; i--){
        arr[i][lastCol] = arr[i-1][lastCol];
    }

    arr[startRow+1][lastCol] = temp;

    solve(arr, n, m, startRow+1, startCol+1, lastRow-1, lastCol-1);
    // return;
}

void rotateMatrix(vector<vector<int>> &arr, int n, int m){
    int startRow = 0;
    int startCol = 0;
    int lastRow = n-1;
    int lastCol = m-1;
    return solve(arr, n, m, startRow, startCol, lastRow, lastCol);  
}

int main(){
    vector<vector<int>> arr 
    {
        {1,2,3,4}, 
        {5,6,7,8}, 
        {9,10,11,12}, 
        {13,14,15,16}
    };
    rotateMatrix(arr,4,4);
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}