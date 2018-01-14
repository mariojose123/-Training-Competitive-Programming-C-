#include <bits/stdc++.h>
//https://www.hackerrank.com/contests/programming-interview-questions/challenges/coin-change

using namespace std;

long getWays(long n, vector < long > c){
    int m=c.size();
    long t[n+1];
    memset(t,0,sizeof(t));
    t[0]=1;
    for(int i=0;i<m;i++){
        for(int j=c[i];j<=n;j++){
             t[j]+=t[j-c[i]];
        }
    }
    return t[n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c);
    cout<< ways;
    return 0;
}
