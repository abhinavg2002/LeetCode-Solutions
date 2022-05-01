class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;
        for(auto x:s){
            if(x=='#'){
                if(a.size())a.pop_back();
            }else{
                a.push_back(x);
            }
        }
        for(auto x:t){
            if(x=='#'){
                if(b.size())b.pop_back();
            }else{
                b.push_back(x);
            }
        }
        return a==b;
    }
};