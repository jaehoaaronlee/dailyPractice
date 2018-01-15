class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> sol;
        
        if(matrix.size() == 0)
            return sol;

        int r1 = 0, r2 = matrix.size() - 1;
        int c1 = 0, c2 = matrix[0].size() - 1;
        
        while(r1 <= r2 && c1 <= c2) {
            for(int c = c1; c <= c2; ++c)
                sol.push_back(matrix[r1][c]);
            for(int r = r1 + 1; r <= r2; ++r)
                sol.push_back(matrix[r][c2]);
            
            if(r1 < r2 && c1 < c2) {
                for(int c = c2 - 1; c >= c1; --c)
                    sol.push_back(matrix[r2][c]);
                for(int r = r2 - 1; r >= r1 + 1; --r)
                    sol.push_back(matrix[r][c1]);
            }
            
            ++r1;
            --r2;
            ++c1;
            --c2;
        }
        
        return sol;
    }
};
