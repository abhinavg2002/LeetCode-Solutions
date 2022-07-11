class Solution {
public:
    #define pb push_back
    int countBinarySubstrings(string s) {
        int pc=0, cc=1, n=s.size(), ans=0;
        for(int i=1;i<n;i++){
            if(s[i]!=s[i-1]){
                ans+=min(pc, cc);
                pc=cc;
                cc=1;
            }else{
                cc++;
            }
        }
        ans+=min(pc, cc);
        return ans;
    }
};