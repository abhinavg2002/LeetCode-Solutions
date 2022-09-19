class Solution {
public:
    string breakPalindrome(string s) {
        if(s.size()==1){
            return "";
        }
        int c=count(s.begin(), s.end(), 'a');
        if(c==s.size() or c==s.size()-1){
            s.back()='b';
            return s;
        }
        for(auto &x:s){
            if(x!='a'){
                x='a';
                break;
            }
        }
        return s;
    }
};