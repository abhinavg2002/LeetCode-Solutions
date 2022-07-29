class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string s) {
        vector<string> ans;
        for(auto x:words){
            unordered_map<char, char> m;
            if(s.size()==x.size()){
                map<char, int> a, b;
                for(auto x:s){
                    a[x]++;
                }
                for(auto c:x){
                    b[c]++;
                }
                if(a.size()!=b.size())continue;
                int n=s.size();
                int k=0;
                for(int i=0;i<n;i++){
                    char c=s[i];
                    if(m.count(c)){
                        if(m[c]!=x[i]){
                            k=1;
                            break;
                        }
                    }else{
                        m[c]=x[i];
                    }
                }
                if(k==0){
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};