vector<string> key={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
vector<string> v;
void solve(string d, int i, string &osf){
    if(i==d.size()){
        v.push_back(osf);
        return;
    }
    int cur=d[i]-48;
    for(int j=0;j<key[cur].size();j++){
        osf.push_back(key[cur][j]);
        solve(d, i+1, osf);
        osf.pop_back();
    }
}
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        v.clear();
        if(digits.size()==0)return v;
        string s="";
        solve(digits, 0, s);
        return v;
    }
};