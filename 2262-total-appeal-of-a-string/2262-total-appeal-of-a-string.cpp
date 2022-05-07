class Solution {
public:
    #define ll long long
    long long appealSum(string s) {
        ll ans=0;
        int n=s.size();
        vector<vector<int>> v(26, vector<int>(1, -1));
        for(int i=0;i<n;i++){
            v[s[i]-'a'].push_back(i);
        }
        for(int i=0;i<26;i++){
            if(v[i].size()==0)continue;
            v[i].push_back(n);
        }
        for(int i=0;i<26;i++){
            if(v[i].size()==0)continue;
            ll t=(1ll*n*(n+1))/2;
            for(int j=1;j<v[i].size();j++){
                long long ct=v[i][j]-v[i][j-1]-1;
                t-=(1ll*(ct)*(ct+1))/2;
            }
            ans+=t;
        }
        return ans;
    }
};