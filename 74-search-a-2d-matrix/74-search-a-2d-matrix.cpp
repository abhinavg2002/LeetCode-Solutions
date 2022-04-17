class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int x) {
        int n=a.size();
        int m=a[0].size();
        int i=0;
        while(i<n and a[i][m-1]<x)i++;
        if(i==n)return false;
        return binary_search(a[i].begin(), a[i].end(), x);
    }
};