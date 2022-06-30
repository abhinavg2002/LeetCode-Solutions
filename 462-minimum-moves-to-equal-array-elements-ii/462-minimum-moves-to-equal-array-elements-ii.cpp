class Solution {
public:
    int minMoves2(vector<int>& v) {
        sort(v.begin(), v.end());
        int med;
        int n=v.size();
        if(v.size()&1){
            med=(v[(n-1)/2]+v[n/2])/2;
        }else{
            med=v[n/2];
        }
        int ans=0;
        for(auto x:v){
            ans+=abs(x-med);
        }
        return ans;
    }
};