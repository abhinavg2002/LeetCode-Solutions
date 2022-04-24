class Solution {
public:
    vector<int> a;
    int s=0;
    Solution(vector<int>& w) {
        for(auto x:w){
            if(a.size()){
                a.push_back(a.back()+x);
            }else{
                a.push_back(x);
            }
        }
    }
    
    int pickIndex() {
        int x=rand()%a.back();
        auto it=upper_bound(a.begin(), a.end(), x);
        return it-a.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */