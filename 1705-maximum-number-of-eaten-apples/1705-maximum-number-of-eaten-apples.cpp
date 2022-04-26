class Solution {
public:
    int eatenApples(vector<int>& a, vector<int>& d) {
        int n=a.size(), ans=0;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> p;
        int i=0;
        while(i<n or p.size()){
            if(i<n){
                if(a[i])p.push({i+d[i]-1, a[i]});
            }
            while(p.size() and p.top().first<i)p.pop();
            
            if(p.size()){
                auto x=p.top();
                p.pop();
                x.second--;
                if(x.second){
                    p.push(x);
                }
                ans++;
            }
            i++;
        }
        return ans;
    }
};