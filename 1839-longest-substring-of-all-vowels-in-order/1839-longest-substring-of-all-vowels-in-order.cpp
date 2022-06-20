class Solution {
public:
    int longestBeautifulSubstring(string s) {
        int n=s.size();
        int l=1, ct=1, ans=0;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                l++;
            }else if(s[i-1]<s[i]){
                ct++;l++;
            }else{
                l=1, ct=1;
            }
            if(ct==5){
                ans=max(ans, l);
            }
        }
        return ans;
    }
};