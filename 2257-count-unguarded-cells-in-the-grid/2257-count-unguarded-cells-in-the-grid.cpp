class Solution {
public:
    int countUnguarded(int n, int m, vector<vector<int>>& d, vector<vector<int>>& w) {
        int ct=0;
        vector<vector<int>> v(n, vector<int> (m, 0)), t(n, vector<int>(m, 0));
        for(auto x:d){
            v[x[0]][x[1]]=1;
        }
        for(auto x:w){
            v[x[0]][x[1]]=-1;
        }
        for(int i=0;i<n;i++){
            int p=0;
            for(int j=0;j<m;j++){
                if(v[i][j]==1)p=1;
                else if(v[i][j]==-1)p=0;
                if(!t[i][j])
                t[i][j]=p;
            }
            p=0;
            for(int j=m-1;j>=0;j--){
                if(v[i][j]==1)p=1;
                else if(v[i][j]==-1)p=0;
                if(!t[i][j])
                t[i][j]=p;
            }
        }
        for(int j=0;j<m;j++){
            int p=0;
            for(int i=0;i<n;i++){
                if(v[i][j]==1)p=1;
                else if(v[i][j]==-1)p=0;
                if(!t[i][j])
                t[i][j]=p;
            }
            p=0;
            for(int i=n-1;i>=0;i--){
                if(v[i][j]==1)p=1;
                else if(v[i][j]==-1)p=0;
                if(!t[i][j])
                t[i][j]=p;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(t[i][j]==0 and v[i][j]==0)ct++;
            }
        }
        return ct;
    }
};