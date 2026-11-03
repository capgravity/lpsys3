#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void queens(int row,int n, vector<vector<char>>& board, vector<int>& cols, vector<int>&diag1, vector<int>& diag2, vector<vector<vector<char>>>& ans){
    if(row==n){
        ans.push_back(board);
        return;
    }
    for(int i=0; i<n; i++){
        if(cols[i]|| diag1[row+i] || diag2[row-i+n-1]){
            continue;
        }
        board[row][i]='Q';
        cols[i]=1;
        diag1[row+i]= 1;
        diag2[row-i+n-1]=1;

        queens(row+1, n, board, cols, diag1, diag2, ans);

        board[row][i]='.';
        cols[i]=0;
        diag1[row+i]=0;
        diag2[row-i+n-1]=0;
    }
}

int main(){
    int n;
    cin>>n;
    vector<vector<char>>board(n, vector<char>(n, '.'));
    vector<int>cols(n, 0);
    vector<int>diag1((2*n)-1, 0);
    vector<int>diag2((2*n)-1, 0);
    vector<vector<vector<char>>>ans;
    queens(0,n, board, cols, diag1, diag2, ans);
    cout<<"no of solns: "<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++){
        cout<<"board"<<i<<":"<<endl;
        for(int j=0; j<ans[i].size(); j++){
            for(int k=0; k<ans[i].size(); k++){
                cout<<ans[i][j][k]<<"";
            }
            cout<<endl;
        }
    }
    return 0;
}