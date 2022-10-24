class Solution {
public:
    map<string, int> m;
    int mx=0;
    void fun(vector<string> &v, int i, int mask){
        if(i==v.size()){
            mx=max(mx, __builtin_popcount(mask));
            return;
        }
        fun(v, i+1, mask);
        if((mask&m[v[i]])==0){
            fun(v, i+1, mask+m[v[i]]);
        }
    }
    int maxLength(vector<string>& v) {
        for(auto &x:v){
            int mask=0;
            for(auto ch:x){
                if((mask&(1<<(ch-'a')))==0)mask|=(1<<(ch-'a'));
                else{
                    mask=0;break;
                }
            }
            m[x]=mask;
        }
        fun(v, 0, 0);
        return mx;
    }
};