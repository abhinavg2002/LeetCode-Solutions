class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        map<int, int> m;
        vector<int> v;
        for(auto x:a){
            m[x]++;
        }
        for(auto x:m){
            while(m.find(x.first)!=m.end()){
                if(m.find(2*(x.first))==m.end() or (m.count(0) and m[0]%2))return {};
                v.push_back(x.first);
                m[x.first]--;
                m[2*(x.first)]--;
                if(m[2*(x.first)]==0){
                    m.erase(2*(x.first));
                }
                if(m[x.first]==0){
                    m.erase(x.first);
                }
            }
        }
        if(m.size()){
            return {};
        }
        return v;
    }
};