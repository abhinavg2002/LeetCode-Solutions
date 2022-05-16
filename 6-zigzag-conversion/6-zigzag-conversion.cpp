class Solution {
public:
    string convert(string s, int b) {
        vector<string> v(b);
        if(b==1)return s;
        int i=0;
        int a=1;
        for(auto x:s){
            v[i].push_back(x);
            i+=a;
            if(i==b){
                a=-1;
                i=b-2;
            }
            if(i==-1){
                a=1;
                i=1;
            }
        }
        string ans;
        for(auto x:v){
            ans+=x;
        }
        return ans;
    }
};