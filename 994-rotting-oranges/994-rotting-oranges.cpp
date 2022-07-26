class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        int n=g.size();
        int m=g[0].size();
        
        queue<pair<int, int>> q;
        int ct=0, res=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(g[i][j]==2){
                    q.push({i, j});
                }else{
                    if(g[i][j]){
                        ct++;
                    }
                }
            }
        }
        // cout<<ct<<endl;
        vector<vector<int>> dir={{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        while(q.size()){
            // cout<<q.size()<<endl;
            int s=q.size();
            while(s--){
                pair<int, int> p=q.front();
                q.pop();
                for(auto d:dir){
                    int x=p.first+d[0];
                    int y=p.second+d[1];
                    if(x>=0 and y>=0 and x<n and y<m and g[x][y]==1){
                        g[x][y]=2;
                        q.push({x, y});
                        ct--;
                        // cout<<"1"<<endl;
                    }
                }
            }
            res++;
        }
        // cout<<res<<endl;
        // cout<<ct<<endl;
        if(ct)return -1;
        if(res==-1)return 0;
        return res;
        
    }
};