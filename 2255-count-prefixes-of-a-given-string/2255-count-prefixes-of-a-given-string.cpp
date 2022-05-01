class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int ct=0;
        for(auto x:words){
            if(s.find(x)==0){
                ct++;
            }
        }
        return ct;
    }
};