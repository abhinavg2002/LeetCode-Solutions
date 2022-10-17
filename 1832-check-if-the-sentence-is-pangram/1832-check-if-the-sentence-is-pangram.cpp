class Solution {
public:
    bool checkIfPangram(string s) {
        map<char,int> m;
        for(auto x:s)m[x]++;
        return m.size()==26;
    }
};