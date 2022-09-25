class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int n=a.size();
        int mx=*max_element(a.begin(), a.end());
        vector<pair<int,int>> v;
        v.push_back({a[0],1});
        for(int i=1;i<n;i++){
            if(a[i]==a[i-1])v.back().second++;
            else v.push_back({a[i],1});
        }
        int ans=0;
        for(auto x:v){
            if(x.first==mx){
                ans=max(ans, x.second);
            }
        }
        return ans;
    }
};