class Solution {
public:
    int compress(vector<char>& c) {
        int n=c.size();
        vector<pair<char,int>> v;
        v.push_back({c[0],1});
        for(int i=1;i<n;i++){
            if(c[i]==c[i-1])v.back().second++;
            else v.push_back({c[i],1});
        }
        string s;
        for(auto x:v){
            s.push_back(x.first);
            if(x.second>1){
                s+=to_string(x.second);                
            }
        }
        for(int i=0;i<s.size();i++){
            c[i]=s[i];
        }
        return s.size();
    }
};