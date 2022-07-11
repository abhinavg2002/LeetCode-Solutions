class Solution {
public:
    #define pb push_back
    int countBinarySubstrings(string s) {
        vector<pair<char,int>> v;
        int n=s.size();
        v.pb({s[0],1});
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1])v.back().second++;
            else v.pb({s[i],1});
        }
        int ans=0;
        for(int i=0;i<v.size()-1;i++){
            ans+=min(v[i].second, v[i+1].second);
        }
        return ans;
    }
};