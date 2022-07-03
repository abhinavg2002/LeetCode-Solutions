class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        vector<int> v;
        for(auto x:a){
            for(auto y:x){
                v.push_back(y);
            }
        }   
        sort(v.begin(), v.end());
        return v[k-1];
    }
};