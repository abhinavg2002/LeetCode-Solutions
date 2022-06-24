class Solution {
public:
    #define ll long long
    bool isPossible(vector<int>& a) {
        priority_queue<int> p(a.begin(), a.end());
        
        ll s=accumulate(a.begin(), a.end(), 0ll);
        
        while(1){
            ll v=p.top();
            p.pop();
            s-=v;
            if(s==1 or v==1){
                return true;
            }
            if(v<s or s==0 or v%s==0){
                return false;
            }
            v%=s;
            p.push(v);
            s+=v;
        }
        return true;
    }
};