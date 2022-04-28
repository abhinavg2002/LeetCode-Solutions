class Solution {
public:
    vector<vector<int>> v;
    int n, m;
    bool path(int i, int j, int val, vector<vector<int>>&vis, int lst){
        if(i<0 or j<0 or i>=n or j>=m or vis[i][j] or abs(v[i][j]-lst)>val)return 0;
        if(i==n-1 and j==m-1)return 1;
        vis[i][j]=1;
        bool ans=false;
        ans|=path(i+1, j, val, vis, v[i][j]);
        ans|=path(i-1, j, val, vis, v[i][j]);
        ans|=path(i, j+1, val, vis, v[i][j]);
        ans|=path(i, j-1, val, vis, v[i][j]);
        return ans;
    }
    int minimumEffortPath(vector<vector<int>>& ht) {
        v=ht;
        n=v.size(), m=v[0].size();
        int l=0, h=1e6+5;
        int ans;
        while(l<=h){
            int mid=(l+h)/2;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            if(path(0, 0, mid, vis, v[0][0])){
                ans=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return ans;
    }
};