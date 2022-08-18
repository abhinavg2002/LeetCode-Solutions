class Solution {
public:
    int minSetSize(vector<int>& a) {
        unordered_map<int, int> m;
        for(auto x:a){
            m[x]++;
        }
        priority_queue<int> p;
        for(auto x:m){
            p.push(x.second);
        }
        int ans=0, res=0;
        while(ans<a.size()/2){
            ans+=p.top();
            p.pop();
            res++;
        }
        return res;
    }
};