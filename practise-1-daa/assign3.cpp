#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int knapsack(int W, vector<int>& value, vector<int>& weight, vector<vector<int>>& memo, int n){
    if(memo[W][n]!=-1){
        return memo[W][n];
    }
    if(n==value.size() || W==0){
        return 0;
    }
    int k1=0;
    if(weight[n]<=W){
        k1= value[n]+ knapsack(W-weight[n], value, weight, memo, n+1);
    }
    int k2= knapsack(W,value, weight, memo, n+1);
    return memo[W][n]= max(k1,k2);
}

int main(){
    int W=5;
    vector<int>value={1,2,3,4,5};
    vector<int>weight={3,2,1,1,2};
    int n=value.size();
    vector<vector<int>>memo(W+1, vector<int>(n+1, -1));
    int maxval= knapsack(W, value, weight, memo, 0);
    cout<<"Max value that can be accomodated is : "<<maxval<<endl;
    return 0;
}