class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        vector<vector<int>> v(m, vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                v[j][i]=a[i][j];
            }
        }
        return v;
    }
};