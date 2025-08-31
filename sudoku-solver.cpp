class Solution {
public:
    struct Point {
        int row, col;
    };
    
    void solveSudoku(vector<vector<char>>& board) {
        vector<Point> emptyCells;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    emptyCells.push_back({i, j});
                }
            }
        }
        if (emptyCells.size() == 0) return;
        
        bool findSolution = false;
        backtrack(board, emptyCells, 0, findSolution);
    }
    
private:
    void backtrack(vector<vector<char>>& board, vector<Point>& emptyCells, int index, bool& findSolution) {
        if (index == emptyCells.size()) {
            findSolution = true;
        }
        if (findSolution) return;
        int row = emptyCells[index].row;
        int col = emptyCells[index].col;
        set<char> validNumbers = getValidNumbers(board, row, col);
        for (char number : validNumbers) {
            if (!findSolution) {
                board[row][col] = number;
                backtrack(board, emptyCells, index + 1, findSolution);
                if (!findSolution) {
                    board[row][col] = '.';
                }
            }
        }
    }
    
    set<char> getValidNumbers(vector<vector<char>>& board, int row, int col) {
        set<char> s;
        for (char c = '1'; c <= '9'; c++) {
            s.insert(c);
        }
        for (int j = 0; j < 9; j++) {
            s.erase(board[row][j]);
        }
        for (int i = 0; i < 9; i++) {
            s.erase(board[i][col]);
        }
        int r = row / 3 * 3;
        int c = col / 3 * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                s.erase(board[r + i][c + j]);
            }
        }
        return s;
    }
};
