#include <bits/stdc++.h> 
using namespace std;

void setZeros(vector<vector<int>> &matrix){
    bool row = false, col = false;
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[0].size(); j++){
            if(matrix[i][j] == 0) {
                if(i == 0) row = true;
                if(j == 0) col = true;
                matrix[0][j] = matrix[i][0] = 0;
            }
        }
    }
    for(int i = 1; i < matrix.size(); i++){
        for(int j = 1; j < matrix[0].size(); j++){
            if(matrix[i][0] == 0 || matrix[0][j] == 0) matrix[i][j] = 0;
        }
    }
    if(col){
        for(int i = 0; i < matrix.size(); i++) matrix[i][0] = 0;
    }
    if(row){
        for(int j = 0; j < matrix[0].size(); j++) matrix[0][j] = 0;
    }
}

int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 0, 6}, {7, 8, 9}};
    setZeros(matrix);
    for(int i=0; i<matrix.size(); i++){
        for(int j=0; j<matrix[i].size(); j++){
            cout<< matrix[i][j] << " "; 
        }
        cout<< endl;
    }
    return 0;
}