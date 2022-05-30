class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        int ans=0;
        int n=p.size();
        for(int i=0;i<n;i++){
            map<pair<int, int>, int> m;
            int d=0;
            for(int j=i;j<n;j++){
                int dx=p[i][0]-p[j][0];
                int dy=p[i][1]-p[j][1];
                if(!dx and !dy)d++;
                else{
                    int g=__gcd(dx, dy);
                    dx/=g;
                    dy/=g;
                    m[{dy, dx}]++;
                }
            }
            ans=max(ans, d);
            for(auto x:m){
                ans=max(ans, x.second+d);
            }
        }
        return ans;
    }
};