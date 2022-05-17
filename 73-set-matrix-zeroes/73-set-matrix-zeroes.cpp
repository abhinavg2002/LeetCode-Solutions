class Solution {
public:
    void setZeroes(vector<vector<int>>& a) {
        int n=a.size(), m=a[0].size();
        vector<int> r, c;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!a[i][j]){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        for(auto x:r){
            for(int j=0;j<m;j++){
                a[x][j]=0;
            }
        }
        for(auto x:c){
            for(int i=0;i<n;i++){
                a[i][x]=0;
            }
        }
    }
};