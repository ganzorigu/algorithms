// 289. Game of Life

// check all 8 neighboring cells.
// easies solution is using mxn extra array
// if in place, -1 for destroyed cell, 2 for become alive cell.
// so that count -1, 1 cells.

#include <iostream>     // std::cout
#include <algorithm>    // std::sort
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
//         vector<vector<int>> nextState(board.size(), vector<int>(board[0].size(),0));
        
//         for (int i=0; i<board.size(); i++) {
//             for (int j=0; j<board[0].size(); j++) {
//                 checkNextState(board, nextState, i, j);                
//             }
//         }                        
        
//         for (int i=0; i<board.size(); i++) {
//             for (int j=0; j<board[0].size(); j++) {
//                 board[i][j] = nextState[i][j];
//             }
//         }
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                changeInplace(board, i, j);                
            }
        }
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j]==-1) {
                    board[i][j] = 0;
                } else if (board[i][j] == 2) {
                    board[i][j] = 1;
                }
            }
        }
        
        
    }
    
    void changeInplace(vector<vector<int>>& board, int i, int j) {
        int liveNeighbors = 0;
        bool topValid = false;
        bool botValid = false;
        bool leftValid = false;
        bool rightValid = false;
        
        if (i-1 >= 0) {
            if (abs(board[i-1][j])==1) {
                liveNeighbors++;
            }            
            topValid = true;
        }
        if (i+1 < board.size()) {
            if (abs(board[i+1][j])==1) {
                liveNeighbors++;
            }            
            botValid = true;
        }
        
        if (j+1 < board[0].size()) {
            if (abs(board[i][j+1])==1) {
                liveNeighbors++;
            }            
            rightValid = true;
        }
        
        if (j-1 >= 0) {
            if (abs(board[i][j-1])==1) {
                liveNeighbors++;
            }            
            leftValid = true;
        }
        
        if (topValid && leftValid) {
            if (abs(board[i-1][j-1])==1) {
                liveNeighbors++;
            }            
        }
        
        if (topValid && rightValid) {
            if (abs(board[i-1][j+1])==1) {
                liveNeighbors++;
            }            
        }
        
        if (botValid && leftValid) {
            if (abs(board[i+1][j-1])==1) {
                liveNeighbors++;
            }            
        }
        
        if (botValid && rightValid) {
            if (abs(board[i+1][j+1])==1) {
                liveNeighbors++;
            }            
        }
        
        // cout << "neighbors:" << i << " "<< j << "->" << liveNeighbors << endl;
        if (!board[i][j] && liveNeighbors == 3) {
            board[i][j] = 2;
        }
        if (board[i][j] && (liveNeighbors > 3 || liveNeighbors < 2)) {
            // dies
            board[i][j] = -1;
        }                
    }
    
    
    
    
    
    void checkNextState(vector<vector<int>>& board, vector<vector<int>>& nextState, int i, int j) {
        int liveNeighbors = 0;
        bool topValid = false;
        bool botValid = false;
        bool leftValid = false;
        bool rightValid = false;
        
        if (i-1 >= 0) {
            liveNeighbors += board[i-1][j];        
            topValid = true;
        }
        if (i+1 < board.size()) {
            liveNeighbors += board[i+1][j];            
            botValid = true;
        }
        
        if (j+1 < board[0].size()) {
            liveNeighbors += board[i][j+1];            
            rightValid = true;
        }
        
        if (j-1 >= 0) {
            liveNeighbors += board[i][j-1];            
            leftValid = true;
        }
        
        if (topValid && leftValid) {
            liveNeighbors += board[i-1][j-1];            
        }
        
        if (topValid && rightValid) {
            liveNeighbors += board[i-1][j+1];            
        }
        
        if (botValid && leftValid) {
            liveNeighbors += board[i+1][j-1];            
        }
        
        if (botValid && rightValid) {
            liveNeighbors += board[i+1][j+1];            
        }
        
        // cout << "neighbors:" << i << " "<< j << "->" << liveNeighbors << endl;
        if (!board[i][j] && liveNeighbors == 3) {
            nextState[i][j] = 1;
        }
        if (board[i][j] && (liveNeighbors == 3 || liveNeighbors == 2)) {
            nextState[i][j] = 1;
        }        
    }
    
};