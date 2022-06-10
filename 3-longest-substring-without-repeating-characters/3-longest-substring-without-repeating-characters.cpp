class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0, j=0;
        unordered_map<char, int> m;
        int n=s.length();
        int l=0;
        int ml=0;
        while(j<n){
            char ch=s[j];
            if(m.count(ch) and m[ch]>=i){
                i=m[ch]+1;
                l=j-i;
            }
            m[ch]=j;
            l++;
            j++;
            if(l>ml){
                ml=l;
            }
        }
        return ml;
    }
};