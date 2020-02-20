//
//  minesweeper
//  https://leetcode.com/problems/minesweeper/
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    typedef struct coordinate {
        int row;
        int col;
    } coord;
    
    //check adjcent nodes. return the number of mines around this node.
    // and add empty node to processing queue
    int checkAdj(const vector<vector<char>>& board, const coord& node, queue<coord>& processingQueue) {
        int mine = 0;
        int maxRow = static_cast<int> (board.size());
        int maxCol = static_cast<int> (board.at(0).size());
        //cout << "check" <<"(" << node.row << "," << node.col << ") " << endl;
        vector<coord> adjcents; //= getAdjacents(board, node);
        //cout << "Adject nodes: " << endl;
        //printList(adjcents);
        
        for (int row = (node.row - 1); row <= (node.row + 1); row++) {
            for (int col = (node.col - 1); col <= (node.col + 1); col++) {
                if ( !(row == node.row && col == node.col) /*this node*/
                    && (row < maxRow) && (row >= 0) /*bound check*/
                    && (col < maxCol) && (col >= 0)) {
                    if (board[row][col] == 'M') {
                         mine++;
                     }
                    adjcents.push_back(coord{row, col});
                }
            }
        }

        if (mine == 0) {
            for (coord& co:adjcents) {
                if (board[co.row][co.col] == 'E') {
                    processingQueue.push(co);
                    //cout << "push" <<"(" << co.row << "," << co.col << ") " << endl;
                }
            }
        }
        //cout << "Return mines: " << mine << endl;

        return mine;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        //case 1: 'M' is revealed, then mark 'X' and game over
        if (board[click[0]][click[1]] == 'M') {
            board[click[0]][click[1]] = 'X';
            return board;
        }
        
        /*Queue to process empty nodes**/
        queue<coord> processingQueue;

        //this is an 'E' node. Add it to processing queue
        processingQueue.push(coord{click[0], click[1]});
        //cout << "Push" <<"(" << click[0] << "," << click[1] << ") " << endl;
        //do proceed until no node in queue
        while (!processingQueue.empty()) {
            coord node = processingQueue.front();
            processingQueue.pop();
            //cout << "Pop" <<"(" << node.row << "," << node.col << ") " << endl;
            /*must confirm whether this is 'E' (1 node can be added multiple times)*/
            if (board[node.row][node.col] == 'E') {
                int mine = checkAdj(board, node, processingQueue);
                if (mine > 0) {
                    board[node.row][node.col] = '0' + mine;
                } else {
                    board[node.row][node.col] = 'B';
                }
                //cout << "set" << board[node.row][node.col] <<"to (" << node.row << "," << node.col << ") " << endl;
            }
            
            //printboard(board);
        }
        
        return board;
    }
    
    void printboard (vector<vector<char>> board) {
        int maxRow = static_cast<int> (board.size());
        int maxCol = static_cast<int> (board.at(0).size());
        
        for (int row = 0; row < maxRow; row++) {
            for (int col = 0; col < maxCol; col++) {
                cout << board[row][col] << " ";
                if(col == maxCol - 1) {
                    cout << endl;
                }
            }
        }
    }
    
    
};

int main(int argc, const char * argv[]) {
    Solution solution;
    
    vector<vector<char>> board;
    board.push_back({'E', 'E', 'E', 'E', 'E'});
    board.push_back({'E', 'E', 'M', 'E', 'E'});
    board.push_back({'E', 'E', 'E', 'E', 'E'});
    board.push_back({'E', 'E', 'E', 'E', 'E'});
    
    cout << "Board: " << endl;
    solution.printboard(board);
    
    vector<int> click {3,0};
    cout << "Click on: (" << click[0] << ", " << click[1] << ")" << endl;
    vector<vector<char>> board_ret = solution.updateBoard(board, click);
        
    cout << "Result: " << endl;
    solution.printboard(board_ret);
    
    return 1;
}
