bool check(string &s, int i, int j, vector<vector<int>> &p){
    if (i >= j) return true;
    if (p[i][j]!=-1) return p[i][j];
    if (s[i] == s[j]) return p[i][j] = check(s, i + 1, j - 1, p);
    return p[i][j] = false;
}
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int ct=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(check(s, i, j, dp)){
                    ct++;
                }
            }
        }
        return ct;
    }
};