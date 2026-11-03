//val[], wt[], W
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int rec(vector<int>& val, vector<int>& wt, int W, int n, vector<vector<int>>& dp){
    if(n==0|| W==0){
        return 0;
    }
    if(dp[n][W]!=-1){
        return dp[n][W];
    }
    //pick it
    int pick1=0;
    if(W- wt[n-1]>=0){
        pick1= val[n-1]+ rec(val, wt, W- wt[n-1], n-1, dp);
    }
    //dont pick it
    int pick2= rec(val, wt, W, n-1, dp);
    return dp[n][W]= max(pick1, pick2);
}

int knapsack(vector<int>& val, vector<int>& wt, int W){
    int n=wt.size();
    vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
    return rec(val , wt, W, n, dp);
}

int main(){
    vector<int>val= {1, 2, 3};
    vector<int>wt={4, 5, 1};
    int W= 3;
    cout<<knapsack(val, wt, W);
    return 0;
}