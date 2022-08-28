class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& a) {
        map<int, multiset<int>> d;
        int n=a.size(), m=a[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                d[i-j].insert(a[i][j]);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int t=i-j;
                int x=*d[t].begin();
                d[t].erase(d[t].find(x));
                a[i][j]=x;
            }
        }
        return a;
    }
};