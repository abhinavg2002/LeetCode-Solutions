class Solution {
public:
    int longestContinuousSubstring(string s) {
        int l=1, ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]+1){
                l++;
            }else{
                ans=max(ans, l);
                l=1;
            }
        }
        return max(ans, l);
    }
};