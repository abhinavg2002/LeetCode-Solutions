class Solution {
public:
    int minimumJumps(vector<int>& f, int a, int b, int x) {
        unordered_set<int> v(f.begin(), f.end());
        vector<vector<int>> visit(2, vector<int>(10000, 0));
        queue<pair<int, int>> q;
        q.push({0, false});
        visit[0][0] = 1;
		visit[1][0] = 1;
        int ans=0;
        while(q.size()){
            int l=q.size();
            while(l--){
                int cur=q.front().first;
                int fg=q.front().second;
                q.pop();
                if(cur==x)return ans;
                int fw=cur+a;
                int bw=cur-b;
                if(fw<10000 and v.count(fw)==0 and visit[0][fw]==0){
                    q.push({fw, false});
                    visit[0][fw]=1;
                }
                if(bw>=0 and v.count(bw)==0 and !fg and visit[1][bw]==0){
                    q.push({bw, true});
                    visit[1][bw]=1;
                }
            }
            ans++;
        }
        return -1;
    }
};