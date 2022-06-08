#include<bits/stdc++.h>
using namespace std;

int maximumProfit(vector<int> &prices){
    int minPriceTillNow = INT_MAX;
    int profit = 0;
    
    for(int i=0; i<prices.size(); i++){
        minPriceTillNow = min(minPriceTillNow, prices[i]);
        profit = max(profit, prices[i] - minPriceTillNow);
    }
    return profit;
}

int main(){
    vector<int> prices = {1, 2, 3, 4};
    // vector<int> prices = {17, 20, 11, 9, 12, 6};
    cout << maximumProfit(prices);
    return 0;
}