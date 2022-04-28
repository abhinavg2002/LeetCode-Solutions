class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int ct=0;
                ct+=(mat[i][j]>(i?mat[i-1][j]:-1));
                ct+=(mat[i][j]>(i+1<n?mat[i+1][j]:-1));
                ct+=(mat[i][j]>(j?mat[i][j-1]:-1));
                ct+=(mat[i][j]>(j+1<m?mat[i][j+1]:-1));
                if(ct==4){
                    return {i, j};
                }
            }
        }
        return {};
    }
};