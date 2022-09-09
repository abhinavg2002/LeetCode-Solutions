class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& v) {
        auto c=[](auto &a, auto &b){
            return a[0]==b[0]?a[1]<b[1]:a[0]>b[0];  
        };
        int mx=INT_MIN;
        int ans=0;
        sort(v.begin(), v.end(), c);
        for(auto x:v){
            ans+=(x[1]<mx);
            mx=max(mx, x[1]);
        }
        return ans;
    }
};