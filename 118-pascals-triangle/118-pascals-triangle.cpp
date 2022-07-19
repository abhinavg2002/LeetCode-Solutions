class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        ans.push_back({1});
        if(n==1)return ans;
        ans.push_back({1, 1});
        if(n==2)return ans;
        n-=2;
        while(n--){
            vector<int> t;
            t.push_back(1);
            int s=ans.back().size();
            for(int i=0;i<s-1;i++){
                t.push_back(ans.back()[i]+ans.back()[i+1]);
            }
            t.push_back(1);
            ans.push_back(t);
        }
        return ans;
    }
};