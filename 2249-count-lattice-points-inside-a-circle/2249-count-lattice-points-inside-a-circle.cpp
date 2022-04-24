class Solution {
public:
    int d(pair<int, int> a, pair<int,int> b){
        return pow((a.first-b.first),2)+pow(a.second-b.second, 2);
    }
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int, int>> p;
        for(auto c:circles){
            int x=c[0], y=c[1], r=c[2];
            int lx=x-r, ux=x+r, ly=y-r, ry=y+r;
            for(int i=lx;i<=ux;i++){
                for(int j=ly;j<=ry;j++){
                    if(d({i, j}, {x, y})<=r*r){
                        p.insert({i, j});
                    }
                }
            }
        }
        return p.size();
    }
};