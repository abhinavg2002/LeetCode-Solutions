class Solution {
public:
    pair<int, int> fun(int x){
        int t=0, f=0;
        while(x%2==0)t++,x/=2;
        while(x%5==0)f++,x/=5;
        return {t, f};
    }
    #define ll long long
    typedef pair<int, int> pii; 
    int maxTrailingZeros(vector<vector<int>>& g) {
        int n=g.size(), m=g[0].size();
        vector<vector<pii>>r(n, vector<pii>(m));
        vector<vector<pii>>l(n, vector<pii>(m));
        vector<vector<pii>>u(n, vector<pii>(m));
        vector<vector<pii>>d(n, vector<pii>(m));
        for(int j=0;j<m;j++){
            pair<int, int> p={0, 0};        
            for(int i=0;i<n;i++){
                auto t=fun(g[i][j]);
                p.first+=t.first;
                p.second+=t.second;
                u[i][j]=p;
            }    
        }
        for(int i=0;i<n;i++){
            pair<int, int> p={0, 0};
            for(int j=0;j<m;j++){
                auto t=fun(g[i][j]);
                p.first+=t.first;
                p.second+=t.second;
                l[i][j]=p;
            }
        }
        for(int j=0;j<m;j++){
            pair<int, int> p={0, 0};        
            for(int i=n-1;i>=0;i--){
                auto t=fun(g[i][j]);
                p.first+=t.first;
                p.second+=t.second;
                d[i][j]=p;
            }    
        }
        for(int i=0;i<n;i++){
            pair<int, int> p={0, 0};
            for(int j=m-1;j>=0;j--){
                auto t=fun(g[i][j]);
                p.first+=t.first;
                p.second+=t.second;
                r[i][j]=p;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                auto p=fun(g[i][j]);
                // l u
                ans=max(ans, min({l[i][j].first+u[i][j].first-p.first, l[i][j].second+u[i][j].second-p.second}));                
                // l d
                ans=max(ans, min({l[i][j].first+d[i][j].first-p.first, l[i][j].second+d[i][j].second-p.second}));
                // r u
                ans=max(ans, min({r[i][j].first+u[i][j].first-p.first, r[i][j].second+u[i][j].second-p.second}));
                // r d
                ans=max(ans, min({r[i][j].first+d[i][j].first-p.first, r[i][j].second+d[i][j].second-p.second}));

            }
        }
        return ans;
    }
};