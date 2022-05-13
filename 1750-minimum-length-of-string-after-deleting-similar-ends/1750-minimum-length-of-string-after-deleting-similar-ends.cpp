class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0, j=n-1;
        while(i<=j){
            if(s[i]!=s[j] or i==j){
                return j-i+1;
            }
            char c=s[i];
            while(i<=j and s[i]==c)i++;
            while(i<=j and s[j]==c)j--;
        }
        return 0;
    }
};