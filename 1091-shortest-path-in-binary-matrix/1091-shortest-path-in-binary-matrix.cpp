class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(n==0)return -1;
        if(grid[0][0]==1 or grid[n-1][n-1]==1)return -1;
        queue<pair<int, int>> q;
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        q.push({0, 0});
        grid[0][0]=1;
        while(q.size()){
            auto p=q.front();
            q.pop();
            int x=p.first;
            int y=p.second;
            if(x==n-1 and y==n-1)return grid[x][y];
            for(auto direction:directions){
                int nx = x + direction[0];
                int ny = y + direction[1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && grid[nx][ny] == 0){
                    q.push(make_pair(nx,ny));
                    grid[nx][ny] = grid[x][y] + 1;
                }
            }
        }
        return -1;
    }
};