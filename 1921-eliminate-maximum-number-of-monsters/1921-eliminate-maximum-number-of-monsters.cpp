class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> t(n);
        for(int i=0;i<n;i++){
            int v=ceil((1.0*dist[i])/speed[i]);
            t[i]=v;
        }
        int time=1;
        sort(t.begin(), t.end());
        for(int i=0;i<n;i++){
            int x=t[i];
            if(time>x){
                return i;
            }
            time++;
        }
        return n;
    }
};