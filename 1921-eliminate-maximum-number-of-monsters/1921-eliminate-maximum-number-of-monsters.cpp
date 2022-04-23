class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        vector<int> t(n);
        map<int,int> m;
        for(int i=0;i<n;i++){
            int v=ceil((1.0*dist[i])/speed[i]);
            t[i]=v;
            m[t[i]]++;
        }
        // for(auto x:t)cout<<x<<" ";
        // cout<<endl;
        // for(auto x:m){
        //     cout<<x.first<<" "<<x.second<<endl;
        // }
        int tot=0;
        int time=0;
        for(auto x:m){
            if(time+x.second>x.first){
                time+=abs(time-x.first);
                break;
            }else{
                time+=x.second;
            }
            
        }
        return time;
    }
};