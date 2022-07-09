class Solution {
public:
    vector<int> prev(vector<int> &a) {
        stack<pair<int, int>> s;
        int n=a.size();
        vector<int> ans(n);
        unordered_map<int, int> m;
        for(int i=0;i<n;i++){
            if(s.size()==0){
                ans[i]=-1;
            }else if(s.size() and s.top().first<a[i]){
                ans[i]=s.top().second;
            }else{
                while(s.size() and s.top().first>=a[i]){
                    s.pop();
                }
                if(s.size()==0){
                    ans[i]=-1;
                }else{
                    ans[i]=s.top().second;
                }
            }
            s.push({a[i], i});
        }
        return ans;
    }
    vector<int> nxt(vector<int>&a){
        stack<pair<int, int>> s;
        int n=a.size();
        vector<int> ans(n);
        unordered_map<int, int> m;
        for(int i=n-1;i>=0;i--){
            if(s.size()==0){
                ans[i]=n;
            }else if(s.size() and s.top().first<a[i]){
                ans[i]=s.top().second;
            }else{
                while(s.size() and s.top().first>=a[i]){
                    s.pop();
                }
                if(s.size()==0){
                    ans[i]=n;
                }else{
                    ans[i]=s.top().second;
                }
            }
            s.push({a[i], i});
        }
        return ans;
    }
    int validSubarraySize(vector<int>& a, int t) {
        int n=a.size();
        vector<int> l=prev(a);
        vector<int> r=nxt(a);
        for(int i=0;i<n;i++){
            long long len=abs(r[i]-l[i]-1);
            if(1ll*a[i]*len>t){
                return len;
            }
        }
        return -1;
    }
};