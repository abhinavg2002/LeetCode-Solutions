class Solution {
public:
    int kthSmallest(vector<vector<int>>& a, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> p;
        int n=a.size();
        for(int i=0;i<n;i++){
            p.push({a[i][0], {i,0}});
        }
        int ct=0;
        int lst;
        while(ct<k-1){
            auto x=p.top();
            p.pop();
            int i=x.second.first;
            int j=x.second.second;
            if(j+1<n){
                p.push({a[i][j+1], {i, j+1}});
            }
            ct++;
        }
        return p.top().first;
    }
};