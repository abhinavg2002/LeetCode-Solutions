class Solution {
public:
    int fun(string &s, string &stamp){
        for(int i=0;i<s.size();i++){
            int a=i, b=0;
            bool f=0;
            while(a<s.size() and b<stamp.size() and (s[a]=='*' or s[a]==stamp[b])){
                if(s[a]==stamp[b])f=1;
                a++, b++;
            }
            
            if(f and b==stamp.size()){
                for(int j=0;j<stamp.size();j++){
                    s[i+j]='*';
                }
                return i;
            }
        }
        return -1;
    }
    vector<int> movesToStamp(string s, string t) {
        int n=t.size();
        string ans(n, '*');
        vector<int> a;
        while(ans!=t){
            int i=fun(t, s);
            if(i==-1)return {};
            a.push_back(i);
        }
        reverse(a.begin(), a.end());
        return a;
    }
};