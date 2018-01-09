class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        const int rowLen = board.size();
        if(rowLen == 0) return;
        const int colLen = board[0].size();
        
	// compute next state
        for(int row = 0; row != rowLen; ++row) {
            for(int col = 0; col != colLen; ++col) {
                int count = countNeighbors(board, rowLen, colLen, row, col);
                
                if(board[row][col] && (count == 2 || count == 3))
                    board[row][col] = 3;
                
                if(board[row][col] == 0 && count == 3)
                    board[row][col] = 2;
            }
        }
        
	// manipulate bits
        for(int i = 0; i != rowLen; ++i) {
            for(int j = 0; j != colLen; ++j) {
                board[i][j] >>= 1;
            }
        }
    }

private:
    int countNeighbors(vector<vector<int>>& board, int rowLen, int colLen, int row, int col) {
        int count = 0;
        
        for(int i = max(row - 1, 0); i != min(row + 2, rowLen); ++i) {
            for(int j = max(col - 1, 0); j != min(col + 2, colLen); ++j) {
                count += board[i][j] & 1;
            }
        }
        
	// subtract itself if 1
        count -= board[row][col] & 1;
        
        return count;
    }
};
