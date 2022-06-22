#include<bits/stdc++.h>
using namespace std;

int uniqueSubstrings(string s){
    // int ans = 0;
    // int maxi = 0;
    int i = 0, j = 0, n = s.size(), ans = 0;
    set<char> charSet;

    while(i<n && j<n){
        //If the character does not in the set
        if(charSet.find(s[j]) == charSet.end()){
            charSet.insert(s[j++]);  //If the character does not in the set
            ans = max(ans, j-i);  //Check if the new distance is longer than the current answer
        }

        else{
            charSet.erase(s[i++]);
        }
    }
    return ans;
}

int main(){
    string s = "dvdf";
    cout << uniqueSubstrings(s);
    return 0;
}