class Solution {
public:
    vector<int> fun(string &s){
        vector<int> v(26, 0);
        for(auto x:s){
            v[x-'a']++;
        }
        return v;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> ct(26), t;
        for(auto x:words2){
            t=fun(x);
            for(int i=0;i<26;i++){
                ct[i]=max(ct[i], t[i]);
            }
        }
        vector<string> ans;
        for(auto x:words1){
            t=fun(x);
            int f=1;
            for(int i=0;i<26;i++){
                if(ct[i]>t[i]){
                    f=0;
                    break;
                }
            }
            if(f){
                ans.push_back(x);
            }
        }
        return ans;
    }
};