class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int maxs=0;
        
        for(int i=1;i<m-1;i++){
            int sum;
            for(int j=1;j<n-1;j++){
                sum=grid[i-1][j-1]+grid[i-1][j]+grid[i-1][j+1]+grid[i][j]+
                    grid[i+1][j-1]+grid[i+1][j]+grid[i+1][j+1];
                maxs=max(sum,maxs);
            }
            
        }
        return maxs;
    }
};