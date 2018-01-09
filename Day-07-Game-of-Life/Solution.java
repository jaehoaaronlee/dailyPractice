class Solution {
    public void gameOfLife(int[][] board) {
        int rowLen = board.length;
        int colLen = board[0].length;
        if(rowLen == 0 || colLen == 0) return;
        
        // compute next state
        for(int row = 0; row < rowLen; row++) {
            for(int col = 0; col < colLen; col++) {
                int count = countNeighbors(board, rowLen, colLen, row, col);
                
                if( board[row][col] == 1 && (count == 2 || count == 3) )
                    board[row][col] = 3;
                
                if( board[row][col] == 0 && count == 3)
                    board[row][col] = 2;
            }
        }
        
        // manipulate bits
        for(int i = 0; i < rowLen; i++) {
            for(int j = 0; j < colLen; j++) {
                board[i][j] >>= 1;
            }
        }
        
    }
    
    public int countNeighbors(int[][] board, int rowLen, int colLen, int row, int col) {
        int count = 0;
        for(int i = Math.max(row - 1, 0); i <= Math.min(row + 1, rowLen - 1); i++) {
            for(int j = Math.max(col - 1, 0); j <= Math.min(col + 1, colLen - 1); j++) {
                count += board[i][j] & 1;
            }
        }
        count -= board[row][col] & 1;
        
        return count;
    }
}
