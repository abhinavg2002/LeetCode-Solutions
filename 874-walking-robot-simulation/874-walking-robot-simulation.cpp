class Solution {
public:
    // NSEW
    // 0123
    // -1->1, -2->2
    vector<vector<int>> m={{0, 2, 3}, {0, 3, 2}, {0, 1, 0}, {0, 0, 1}};
    int robotSim(vector<int>& c, vector<vector<int>>& o) {
        int x=0, y=0, cd=0;
        int mx=0;
        set<vector<int>> s(o.begin(), o.end());
        for(auto k:c){
            if(k<0){
                cd=m[cd][abs(k)];
            }else{
                if(cd==0){
                    while(k--){
                        if(s.count({x, y+1})==0){
                            y++;
                        }
                        else break;
                    }
                    
                }else if(cd==1){
                    while(k--){
                        if(s.count({x, y-1})==0){
                            y--;
                        }
                        else break;
                    }
                }else if(cd==2){
                    while(k--){
                        if(s.count({x+1, y})==0){
                            x++;
                        }
                        else break;
                    }
                }else{
                    while(k--){
                        if(s.count({x-1, y})==0){
                            x--;
                        }
                        else break;
                    }
                }
                mx=max(mx, x*x+y*y);
            }
        }
        return mx;
    }
};