class Solution {
public:
    bool is(string s, string t){
        reverse(t.begin(), t.end());
        return s==t;
    }
    int removePalindromeSub(string s) {
        if(is(s, s))return 1;
        return 2;
    }
};