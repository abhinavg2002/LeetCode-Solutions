class Solution {
public:
    bool fun(string &s, vector<vector<int>>&v){
        int lst=-1;
        for(auto x:s){
            int i=x-'a';
            auto it=upper_bound(v[i].begin(), v[i].end(), lst);
            if(it==v[i].end())return false;
            lst=*it;
        }
        return true;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> v(26);
        int n=s.size();
        for(int i=0;i<n;i++){
            v[s[i]-'a'].push_back(i);
        }
        int ct=0;
        for(auto &x:words){
            ct+=fun(x, v);
        }
        return ct;
    }
};