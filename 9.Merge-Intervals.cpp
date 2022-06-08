#include <bits/stdc++.h> 
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals){
    
    vector<vector<int>> output;
    
    sort(intervals.begin(), intervals.end());

    vector<int> temp = intervals[0];

    for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0] <= temp[1])
            temp[1] = max(temp[1] , intervals[i][1]);
        else{
            output.push_back(temp);
            temp = intervals[i];
        }
    }
    
    output.push_back(temp);

    return output;
}

int main(){
    // vector<vector<int>> intervals = {{1, 2}, {3, 6}, {8, 10}};
    vector<vector<int>> intervals = {{1, 5}, {2, 3}};
    vector<vector<int>> mergedIntervals = mergeIntervals(intervals);
    for (int i = 0; i < mergedIntervals.size(); i++){
        for (int j = 0; j < mergedIntervals[i].size(); j++)
        {
            cout << mergedIntervals[i][j] << " ";
        }
    }
    return 0;
}