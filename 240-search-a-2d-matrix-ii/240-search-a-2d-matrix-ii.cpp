class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
        int n=a.size();
        int m=a[0].size();
        int i=0, j=m-1;
        while(i<n and j>=0){
            if(a[i][j]==x)return true;
            if(a[i][j]<x){
                i++;
            }else{
                j--;
            }
        }
        return false;
    }
};