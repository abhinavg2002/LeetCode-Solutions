class Solution {
public:
    int minimumRounds(vector<int>& t) {
        map<int, int> m;
        for(auto x:t)m[x]++;
        int mn=1e9;
        for(auto x:m){
            mn=min(mn, x.second);
        }
        if(mn<2)return -1;
        int ans=0;
        for(auto x:m){
            int v=x.second;
            if(v%3){
                ans+=(v/3)+1;
            }else{
                ans+=(v/3);
            }
        }
        return ans;
    }
};