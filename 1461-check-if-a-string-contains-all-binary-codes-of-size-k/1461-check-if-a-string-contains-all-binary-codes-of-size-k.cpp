class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> us;
        deque<char> q;
        for(auto x:s){
            q.push_back(x);
            if(q.size()==k){
                us.insert({q.begin(), q.end()});
                q.pop_front();
            }
        }
        return us.size()==(1<<k);
    }
};