class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& a) {
        int n=a.size();
        map<int, int> s, e;
        for(int i=0;i<n;i++){
            s[a[i][0]]=i;
            e[a[i][1]]=i;
        }
        vector<int> ans;
        for(auto x:a){
            if(s.lower_bound(x[1])==s.end()){
                ans.push_back(-1);
            }else{
                ans.push_back(s.lower_bound(x[1])->second);   
            }
        }
        return ans;
    }
};