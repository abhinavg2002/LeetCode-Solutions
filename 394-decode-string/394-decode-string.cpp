class Solution {
public:
    string fun(string &s, int &i){
        int x=0;
        string w;
        for(;i<s.size();i++){
            if(s[i]>='0' and s[i]<='9'){
                x=x*10+s[i]-'0';
            }else if(s[i]=='['){
                i++;
                string temp=fun(s, i);
                while(x--){
                    w+=temp;
                }
                x=0;
            }else if(s[i]==']'){
                return w;
            }else{
                w.push_back(s[i]);
            }
        }
        return w;
    }
    string decodeString(string s) {
        int i=0;
        return fun(s, i);
    }
};