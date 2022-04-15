class Solution {
public:
    int longestSubarray(vector<int>& v, int l) {
        multiset<int> s;
        int n=v.size(), i=0;
        int mx=0;
        for(int j=0;j<n;j++){
            s.insert(v[j]);
            while(*s.rbegin()-*s.begin()>l){
                s.erase(s.find(v[i]));
                i++;
            }
            mx=max(mx, j-i+1);
        }
        return mx;
    }
};