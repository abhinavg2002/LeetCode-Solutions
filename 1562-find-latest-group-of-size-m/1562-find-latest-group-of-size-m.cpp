class Solution {
public:
    int findLatestStep(vector<int>& a, int m) {
        int n=a.size();
        queue<pair<int, int>> q;
        q.push({1, n});
        int st=0;
        for(int i=n-1;i>=0;i--){
            int s=q.size();
            int x=a[i];
            while(s--){
                auto p=q.front();
                q.pop();
                int l=p.second-p.first+1;
                if(l==m){
                    return n-st;
                }
                if(l<m)continue;
                if(x>=p.first and x<=p.second){
                    if(x-p.first>=m){
                        q.push({p.first, x-1});
                    }
                    if(p.second-x>=m){
                        q.push({x+1, p.second});
                    }
                }else{
                    q.push(p);
                }
            }
            st++;
        }
        return -1;
    }
};