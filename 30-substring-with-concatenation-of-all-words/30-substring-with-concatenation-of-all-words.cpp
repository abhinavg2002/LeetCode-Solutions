class Solution {
public:
    map<string, int> st;
    unordered_set<int> dp;
    bool fun(string &s, int i, int j, int cl){
        int f=1;
        map<string, int> taken;
        for(int id=i;i<=j;i+=cl){
            string t;
            int l=0;
            for(int k=i;l<cl;k++,l++){
                t.push_back(s[k]);
            }
            if(st.count(t)==0){
                f=0;break;
            }
            taken[t]++;
        }
        if(taken==st)return f==1;
        else return false;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        for(auto &x:words){
            st[x]++;
        }
        int n=s.size();
        vector<int> ans;
        int l=words.size()*words[0].size();
        for(int i=0;i+l-1<n;i++){
            if(fun(s, i, i+l-1, words[0].size())){
                ans.push_back(i);   
            }
        }
        return ans;
    }
};