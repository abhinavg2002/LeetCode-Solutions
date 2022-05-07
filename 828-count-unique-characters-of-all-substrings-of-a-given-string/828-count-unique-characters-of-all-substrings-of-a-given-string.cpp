class Solution {
public:
    #define ll long long
    int uniqueLetterString(string s) {
        ll ans=0;
        int n=s.size();
        vector<vector<int>> v(26);
        for(int i=0;i<n;i++){
            if(v[s[i]-'A'].size()==0){
                v[s[i]-'A'].push_back(-1);
            }
            v[s[i]-'A'].push_back(i);
        }
        for(int i=0;i<26;i++){
            if(v[i].size()==0)continue;
            v[i].push_back(n);
        }
        for(int i=0;i<26;i++){
            if(v[i].size()==0)continue;
            for(int j=1;j<v[i].size()-1;j++){
                long long ct=1ll*(v[i][j]-v[i][j-1])*(v[i][j+1]-v[i][j]);
                ans+=ct;
            }
        }
        return ans;
    }
};