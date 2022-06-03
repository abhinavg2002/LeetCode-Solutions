class NumMatrix {
public:
    vector<vector<int>> v;
    NumMatrix(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        for(int i=1;i<n;i++){
            a[i][0]=a[i][0]+a[i-1][0];
        }
        for(int i=1;i<m;i++){
            a[0][i]=a[0][i-1]+a[0][i];
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                a[i][j]=a[i][j]+a[i-1][j]+a[i][j-1]-a[i-1][j-1];
            }
        }
        v=a;
    }
    
    int sumRegion(int x1, int y1, int x2, int y2) {
        long res = v[x2][y2];
        if (x1 > 0)
        res = res - v[x1-1][y2];
        if (y1 > 0)
        res = res - v[x2][y1-1];
        if (x1 > 0 && y1 > 0){
            res = res + v[x1-1][y1-1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */