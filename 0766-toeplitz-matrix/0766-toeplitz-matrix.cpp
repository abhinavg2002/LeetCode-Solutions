class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for (int r = 1; r < n; ++r)
            for (int c = 1; c < m; ++c)
                if (matrix[r][c] != matrix[r - 1][c - 1]) return false;
        
        return true;
    }
};