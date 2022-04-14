class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        vector<int> lis;
        for(auto x:a){
            if(lis.size()==0){
                lis.push_back(x);
            }
            if(x>lis.back()){
                lis.push_back(x);
            }else if(x<lis.back()){
                auto it=lower_bound(lis.begin(), lis.end(), x);
                lis[it-lis.begin()]=x;
            }
        }
        return lis.size();
    }
};