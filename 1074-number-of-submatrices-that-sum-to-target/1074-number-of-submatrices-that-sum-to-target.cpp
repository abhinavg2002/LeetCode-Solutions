class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& v, int x) {
        int n=v.size();
        int m=v[0].size();
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                v[i][j]+=v[i][j-1];
            }
        }
        int ans=0;
        for(int c1=0;c1<m;c1++){
            for(int c2=c1;c2<m;c2++){
                int sum=0;
                unordered_map<int, int> mp;
                mp[sum]=1;
                for(int i=0;i<n;i++){
                    sum+=v[i][c2]-(c1?v[i][c1-1]:0);
                    if(mp.find(sum-x)!=mp.end()){
                        ans+=mp[sum-x];
                    }
                    mp[sum]++;
                }
            }
        }
        return ans;
    }
};