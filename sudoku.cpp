
//Leetcode problem No - 37 
/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.
*/
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    bool issafe(int row,int col,vector<vector<char>>& board,char val){
        for(int i=0;i<9;i++){
            if(board[row][i]==val||board[i][col]==val||board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(int val=1;val<=9;val++){
                        char c = val + '0';
                        if(issafe(i,j,board,c)){
                            board[i][j] = c;
                            if(solve(board))return true;
                             board[i][j] = '.';
                        }
                    }
                    return false;
                }
                
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
