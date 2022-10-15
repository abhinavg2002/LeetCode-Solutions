class Solution {
public:
    #define ll long long
    bool valid(string &s){
        ll h=stoll(s.substr(0, 2)), m=stoll(s.substr(3, 2));
        return (h>=0 && h<=23 && m>=0 && m<=59);
    }
    int ct=0;
    void fun(int i, string &s){
        if(i==s.size()){
            ct+=valid(s);
            return;
        }
        if(s[i]=='?'){
            for(int d=0;d<=9;d++){
                s[i]='0'+d;
                fun(i+1, s);
            }
            s[i]='?';
        }else{
            fun(i+1, s);   
        }
    }
    int countTime(string time) {
        fun(0, time);
        return ct;
    }
};