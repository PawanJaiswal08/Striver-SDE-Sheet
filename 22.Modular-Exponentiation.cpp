#include <bits/stdc++.h>
using namespace std;

long long int power(int x, int n, int m){
    if(n == 0)
        return 1;
    if(n==1)
        return x;

    long long int ans = power(x, n/2, m);

    if(n&1)
        return ans = (((x * ans) % m) * ans) % m;
    else
        return ans = ((ans * ans) % m) % m;
}

int modularExponentiation(int x, int n, int m) {
    int ans = power(x, n, m);
    ans = ans % m;
    return ans;
}

int main(){
    int x = 10000000;
    int n = 2;
    int m = 10000001;
    cout << modularExponentiation(x,n,m);
    return 0;
}