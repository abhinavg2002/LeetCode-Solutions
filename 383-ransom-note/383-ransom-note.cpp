class Solution {
public:
    bool canConstruct(string s, string a) {
        unordered_map<char, int> m;
        for(auto x:a){
            m[x]++;
        }   
        for(auto x:s){
            m[x]--;
        }
        for(auto x:m){
            if(x.second<0)return false;
        }
        return true;
    }
};