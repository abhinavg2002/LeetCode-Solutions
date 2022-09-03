class Solution {
public:
    vector<vector<int>> subsets(vector<int>& a) {
        vector<vector<int>> v;
        int n=a.size();
        for(int i=0;i<(1<<n);i++){
            vector<int> t;
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0){
                    t.push_back(a[j]);
                }
            }
            v.push_back(t);
        }
        return v;
    }
};