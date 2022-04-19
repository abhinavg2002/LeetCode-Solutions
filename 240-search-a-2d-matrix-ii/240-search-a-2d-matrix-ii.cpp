class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
        vector<int> v;
        int n=a.size();
        int m=a[0].size();
        for(int i=0;i<n;i++){
            v.push_back(a[i][0]);
        }
        
        int id=upper_bound(v.begin(), v.end(), x)-v.begin()-1;
        if(id==-1)return false;
        for(int i=0;i<=id;i++){
            if(binary_search(a[i].begin(), a[i].end(), x)){
                return true;
            }
        }
        return false;
    }
};