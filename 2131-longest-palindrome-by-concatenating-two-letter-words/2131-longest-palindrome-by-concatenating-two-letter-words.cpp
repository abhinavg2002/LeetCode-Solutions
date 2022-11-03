class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int c[26][26];
        memset(c, 0, sizeof(c));
        for(auto x:words){
            int i=x[0]-'a';
            int j=x[1]-'a';
            c[i][j]++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            for(int j=i+1;j<26;j++){
                int k=min(c[i][j], c[j][i]);
                ans+=4*k;
            }
        }
        for(int i=0;i<26;i++){
            int k=c[i][i]/2;
            c[i][i]%=2;
            ans+=4*k;
        }
        for(int i=0;i<26;i++){
            if(c[i][i]){
                ans+=2;break;
            }
        }
        return ans;
    }
};