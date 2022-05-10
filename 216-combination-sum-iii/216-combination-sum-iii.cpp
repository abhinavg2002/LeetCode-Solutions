vector<vector<int>> a;
void solve(int i, int k, int n, vector<int>&v){
    if(n==0 and v.size()==k){
        a.push_back(v);
        return;
    }
    
    for(int s=i;s<=9;s++){
        if(s>n)break;
        v.push_back(s);
        solve(s+1, k, n-s, v);
        v.pop_back();
    }
}


class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        a.clear();
        if(k>n)return {};
        vector<int>v;
        solve(1, k, n, v);
        return a;
    }
};