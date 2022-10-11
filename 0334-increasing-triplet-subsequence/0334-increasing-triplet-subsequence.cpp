class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        vector<int> v;
        for(auto x:a){
            if(v.size()==0){
                v.push_back(x);
            }
            else{
                if(v.back()<x){
                    v.push_back(x);
                }else{
                    int id=lower_bound(v.begin(), v.end(), x)-v.begin();
                    v[id]=x;
                }
            }
        }
        return v.size()>=3;
    }
};