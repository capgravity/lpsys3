#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void nqueens(int i, vector<vector<vector<char>>>& boards, vector<vector<char>>& board, vector<int>& diag1, 
    vector<int>& diag2, vector<int>& col, int& n){
    if(i==n){
        boards.push_back(board);
        return;
    }
    for(int j=0; j<n; j++){
        int d1= i+ j;
        int d2= i-j+n-1;
        if(diag1[d1]|| diag2[d2]|| col[j]){
            continue;
        }
        diag1[d1]=1;
        diag2[d2]=1;
        col[j]=1;
        board[i][j]='Q';
        nqueens(i+1, boards, board, diag1, diag2, col, n);
        diag1[d1]=0;
        diag2[d2]=0;
        col[j]=0;
        board[i][j]='.';

    }

}


int main(){
    int n=4;
    vector<vector<vector<char>>>boards;
    vector<vector<char>>board(n, vector<char>(n,'.'));
    vector<int>diag1(2*n-1, 0);
    vector<int>diag2(2*n-1, 0);
    vector<int>col(n,0);
    nqueens(0, boards, board, diag1, diag2, col, n);
    for(int i=0; i<boards.size(); i++){
        cout<<"BOARD : "<<i<<endl;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                cout<<boards[i][j][k];
            }
            cout<<endl;
        }
    }
    return 0;
}