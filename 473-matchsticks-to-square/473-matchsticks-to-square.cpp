class Solution {
public:
    vector<int> visit;
    bool fun(vector<int>&v, int id, int sum, int target, int k){
        if(k==1)return true;
        if(sum==target){
            return fun(v, 0, 0, target, k-1);
        }
        for(int i=id;i<v.size();i++){
            if(visit[i] or sum+v[i]>target)continue;
            visit[i]=1;
            int ans=fun(v, i+1, sum+v[i], target, k);
            if(ans)return true;
            visit[i]=0;
        }
        return false;
    }
    bool makesquare(vector<int>& v) {
        int sum=accumulate(v.begin(), v.end(), 0);
        int n=v.size();
        int k=4;
        if(n<k or sum%k)return false;
        int target=sum/k;
        visit.resize(n);
        for(auto &x:visit)x=0;
        return fun(v, 0, 0, target, k);
    }
};