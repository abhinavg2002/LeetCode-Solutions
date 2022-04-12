class Solution {
public:
    int n, m;
    int nbr(vector<vector<int>>&v, int i, int j){
        int ct=0;
        
        ct += i and v[i-1][j];
        ct += i+1<n and v[i+1][j];
        ct += j and v[i][j-1];
        ct += j+1<m and v[i][j+1];
        
        ct += i and j and v[i-1][j-1];
        ct += i+1<n and j+1<m and v[i+1][j+1];
        ct += i+1<n and j and v[i+1][j-1];
        ct += i and j+1<m and v[i-1][j+1];
        
        return ct;
    }
    void gameOfLife(vector<vector<int>>& b) {
        n=b.size(), m=b[0].size();
        vector<vector<int>> t=b;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ct=nbr(t, i, j);
                if(b[i][j]==1){
                    if(ct<2 or ct>3)b[i][j]=0;
                }else {
                    b[i][j]=(ct==3);
                }
            }
        }
    }
};