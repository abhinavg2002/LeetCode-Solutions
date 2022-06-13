class Solution {
public:
    pair<int,int> fd(vector<vector<int>>&b){
        int n=2, m=3;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(b[i][j]==0){
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }
    vector<vector<int>>sol={{1,2,3},{4,5,0}};
    int slidingPuzzle(vector<vector<int>>& b) {
        int n=2, m=3;
        queue<vector<vector<int>>> q;
        q.push(b);
        vector<int> d={0, -1, 0, 1, 0};
        set<vector<vector<int>>> vis;
        vis.insert(b);
        int l=0;
        while(q.size()){
            int s=q.size();
            while(s--){
                auto x=q.front();
                q.pop();
                if(x==sol)return l;
                auto p=fd(x);
                int u=p.first, v=p.second;
                for(int k=0;k<4;k++){
                    int i=u+d[k], j=v+d[k+1];
                    if(i<0 or j<0 or i>=n or j>=m)continue;
                    swap(x[i][j], x[u][v]);
                    if(vis.count(x)){
                        swap(x[i][j], x[u][v]);
                        continue;
                    }
                    q.push(x);
                    vis.insert(x);
                    swap(x[i][j], x[u][v]);
                }
            }
            l++;
        }
        return -1;
    }
};