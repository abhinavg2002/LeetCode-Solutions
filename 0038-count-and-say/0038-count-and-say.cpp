class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        
        if(n==2)return "11";
        
        string s="11";
        n-=2;
        while(n--){
            int ct=1;
            string t="";
            s+='$';
            for(int i=1;i<s.size();i++){
                if(s[i]==s[i-1]){
                    ct++;
                }else{
                    t+=ct+'0';
                    t+=s[i-1];
                    ct=1;
                }
            }
            s=t;
        }
        return s;
    }
};