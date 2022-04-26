class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int th) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>p(n+1, vector<int>(m+1, 0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                p[i+1][j+1]=mat[i][j]+p[i][j+1]+p[i+1][j]-p[i][j];
            }
        }
        // for(auto x:p){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        auto sum=[&](int x1, int y1, int x2, int y2) {
            long res = p[x2][y2];
            if (x1 > 0)
            res = res - p[x1-1][y2];
            if (y1 > 0)
            res = res - p[x2][y1-1];
            if (x1 > 0 && y1 > 0){
                res = res + p[x1-1][y1-1];
            }
            return res;
        };
        auto check=[&](int mid){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    // if(sum(i, j, i+mid-1, j+mid-1)<=th)return true;
                    if(i-mid>=0 and j-mid>=0){
                        int sum=p[i][j]-p[i-mid][j]-p[i][j-mid]+p[i-mid][j-mid];
                        if(sum<=th)return true;
                    }
                }
            }
            return false;
        };
        
        int l=0, h=min(n, m);
        int ans=0;
        while(l<=h){
            int mid=l+(h-l)/2;
            int ta=check(mid);
            // cout<<mid<<" "<<ta<<endl;
            if(ta){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans;
    }
};