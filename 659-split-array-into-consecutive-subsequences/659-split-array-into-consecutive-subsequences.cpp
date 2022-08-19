class Solution {
public:
    bool isPossible(vector<int>& v) {
        int n=v.size();
        unordered_map<int, int> end, ct;
        for(auto x:v){
            ct[x]++;
        }
        for(auto x:v){
            if(!ct[x])continue;
            ct[x]--;
            if(end[x-1]){
                end[x-1]--;
                end[x]++;
            }
            else if(ct[x+1] and ct[x+2]){
                ct[x+1]--;
                ct[x+2]--;
                end[x+2]++;
            }else return false;
        }
        return true;
    }
};