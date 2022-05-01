class Solution {
public:
    int maximumMinutes(vector<vector<int>>& g) {
        // 0 grass 1 fire 2 wall
        /*
        so its like we have to find the path jispe se wo safe house tk ja sake plus wha fir ko pohchne me max time lage 
        so our ans will be time taken by fire to reach intersection pt - time taken by man to reach intersection pt
        if our ans is negative then return -1
        if fire cant reach intersection pt ans is 1e9
        hm binary search laga sakte hai ig
        */
        int n=g.size(), m=g[0].size();
        int l=0, h=2*1e4+5, ans=-1;
        int d[]={0, -1, 0, 1, 0};
        // check func ki itne suff hai ya nhi
        // now we have to write check func and our job is done
        auto check=[&](int t){
            vector<vector<int>> v=g;
            queue<pair<int, int>> q, qm;
            vector<vector<int>> vis(n, vector<int>(m, 0)), vism=vis;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(g[i][j]==1){
                        q.push({i, j});
                        vis[i][j]=1;
                    }
                }
            }
            for(int k=0;k<t;k++){
                int s=q.size();
                while(s--){
                    auto p=q.front();
                    q.pop();
                    int x=p.first, y=p.second;
                    for(int i=0;i<4;i++){
                        int nx=x+d[i], ny=y+d[i+1];
                        if(nx<0 or ny<0 or nx>=n or ny>=m or vis[nx][ny] or v[nx][ny]==2)continue;
                        if((nx==0 and ny==0) or (nx==n-1 and ny==m-1))return false;
                        q.push({nx, ny});
                        vis[nx][ny]=1;
                        v[nx][ny]=1;
                    }
                }
            }
            // we got the state of board after t seconds
            qm.push({0, 0});
            vism[0][0]=1;
            // now we will simulate man
            while(qm.size()){
                // move the fire to nbrs
                int f=0;
                int s=q.size();
                while(s--){
                    auto p=q.front();
                    q.pop();
                    int x=p.first, y=p.second;
                    for(int i=0;i<4;i++){
                        int nx=x+d[i], ny=y+d[i+1];
                        if(nx<0 or ny<0 or nx>=n or ny>=m or vis[nx][ny] or g[nx][ny]==2)continue;
                        if(nx==n-1 and ny==m-1){
                            f=1;
                            continue;
                        }
                        q.push({nx, ny});
                        vis[nx][ny]=1;
                        v[nx][ny]=1;
                    }
                }
                s=qm.size();
                while(s--){
                    auto p=qm.front();
                    qm.pop();
                    int x=p.first, y=p.second;
                    if(x==n-1 and y==m-1){
                        return true;
                    }
                    for(int i=0;i<4;i++){
                        int nx=x+d[i], ny=y+d[i+1];
                        if(nx<0 or ny<0 or nx>=n or ny>=m or vism[nx][ny] or g[nx][ny]==2 or v[nx][ny]==1)continue;
                        if(nx==n-1 and ny==m-1)return true;
                        qm.push({nx, ny});
                        vism[nx][ny]=1;
                    }
                }
                if(f){
                    return false;
                }
            }
            return false;
        };
        while(l<=h){
            int mid=l+(h-l)/2;
            if(check(mid)){
                ans=mid;
                l=mid+1;
            }else{
                h=mid-1;
            }
        }
        return ans==(2*1e4+5)?1e9:ans;
    }
};