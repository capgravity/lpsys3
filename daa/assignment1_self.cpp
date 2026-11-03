#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int recursive(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    return recursive(n-1) + recursive(n-2);
}

int iterative(int n){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    int a=0;
    int b=1;
    int c=0;
    for(int i=3; i<=n; i++){
        c=a+b;
        a=b;
        b=c;
    }
    return c;
}

int dpfn(int n, vector<int>& dp){
    if(n==1){
        return 0;
    }
    if(n==2){
        return 1;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    return dp[n]= dpfn(n-1, dp)+ dpfn(n-2, dp);
    
}


int main(){
    cout<<"Enter nth term for which you want to calculate fibonacci number"<<endl;
    int n;
    cin>>n;
    cout<<"Enter 1. Recursive 2. Non recursive 3. DP solution for calculating the nth fibonacci Number"<<endl;
    int ans;
    cin>>ans;
    switch(ans){
        case 1:
            cout<<"FIb: "<<recursive(n);
            break;
        case 2: 
            cout<<"FIb: "<<iterative(n);
            break;
        case 3: {
            vector<int>dp(n+1, -1);
             cout<<"FIb: "<<dpfn(n, dp);
            break;
        }
        default:
            break;
    }
    return 0;
} 