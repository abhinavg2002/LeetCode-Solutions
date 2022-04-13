class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        // vector<int> a;
        vector<vector<int>> v(n, vector<int>(n, 0));
        int r=0, c=0;
        int m=v[0].size();
        int mr=n-1, mc=m-1;
        int ct=0;
        int t=n*m;
        while(ct<n*m){
            for(int j=c, i=r;j<=mc and ct<t;j++)v[i][j]=ct+1, ct++;
            r++;
            for(int i=r, j=mc;i<=mr and ct<t;i++)v[i][j]=ct+1 , ct++;
            mc--;
            for(int j=mc, i=mr;j>=c and ct<t;j--)v[i][j]=ct+1, ct++;
            mr--;
            for(int i=mr, j=c;i>=r and ct<t;i--)v[i][j]=ct+1 , ct++;
            c++;
        }
        return v;
    }
};