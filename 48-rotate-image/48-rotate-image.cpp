class Solution {
public:
    void rotate(vector<vector<int>>& a) {
        reverse(a.begin(), a.end());
        for(int i=0;i<a.size();i++){
            for(int j=i+1;j<a.size();j++){
                swap(a[j][i], a[i][j]);
            }
        }
    }
};