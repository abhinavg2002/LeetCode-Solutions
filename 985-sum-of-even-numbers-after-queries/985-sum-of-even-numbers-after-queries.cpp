class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& v, vector<vector<int>>& queries) {
        vector<int> ans;
        int s=0;
        for(auto x:v){
            if(x%2==0){
                s+=x;
            }
        }
        for(auto q:queries){
            int id=q[1], val=q[0];
            if(v[id]%2==0){
                s-=v[id];
            }
            v[id]+=val;
            if(v[id]%2==0){
                s+=v[id];
            }
            ans.push_back(s);
        }
        return ans;
    }
};