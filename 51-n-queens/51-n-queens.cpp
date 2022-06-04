class Solution {
public:
    vector<vector<string>> ans;
    bool is_safe_queen(vector<string> &grid, int row, int col, int n){
        //vertically up
        for(int i= row-1;i>=0;i--){
            if(grid[i][col]=='Q')return false;
        }
        //horizontally left not needed
        // for(int j=col-1;j>=0;j--){
        //     if(grid[row][j]==true)return false;
        // }
        //upper left diagonal
        for(int i=row-1, j=col-1;i>=0 && j>=0;i--,j--){
            if(grid[i][j]=='Q')return false;
        }
        //lower right diag not needed
        // for(int i=row+1, j=col+1;i<n && j<n;i++,j++){
        //     if(grid[i][j]==true)return false;
        // }
        //upper right diag
        for(int i=row-1, j=col+1;i>=0 && j<n;i--,j++){
            if(grid[i][j]=='Q')return false;
        }
        //lower left diag not needed
        // for(int i=row+1, j=col-1;i<n && j>=0;i++,j--){
        //     if(grid[i][j]==true)return false;
        // }
        return true;
    }
    void n_queen(vector<string> &grid, int curr_row, int n){
        //base case
        if(curr_row==n){
            ans.push_back(grid);
            return ;
        }
        for(int i=0;i<n;i++){
            if(is_safe_queen(grid,curr_row,i, n)){
                grid[curr_row][i]='Q';
                n_queen(grid,curr_row+1, n);
                grid[curr_row][i]='.';//to make ques in original state
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> grid(n, string(n, '.'));
        n_queen(grid, 0, n);
        return ans;
    }
};