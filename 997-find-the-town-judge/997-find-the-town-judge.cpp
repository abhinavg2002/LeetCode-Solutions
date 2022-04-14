class Solution {
public:
    int findJudge(int n, vector<vector<int>>& v) {
        vector<int> l[n];
        vector<int> r[n];
        for(auto x:v){
            int a=x[0];
            int b=x[1];
            l[a-1].push_back(b-1);
            r[b-1].push_back(a-1);
        }
        int ct=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(l[i].size()==0 and r[i].size()==n-1){
                ct++;
                ans=i+1;
            }
        }
        if(ct==1)return ans;
        return -1;
    }
};