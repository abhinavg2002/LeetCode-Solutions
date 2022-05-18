class Solution {
public:
    int fun(vector<int> &a, int b){
        int n=a.size();
        int i=0, j=0;
        // atmost b
        unordered_map<int,int> m;
        int ct=0;
        while(j<n){
            m[a[j]]++;
            while(m.size()>b){
                if(--m[a[i]]==0){
                    m.erase(a[i]);
                }
                i++;
            }
            ct+=(j-i+1);
            j++;
        }
        return ct;
    }
    int subarraysWithKDistinct(vector<int>& a, int k) {
        int n=a.size();
        return fun(a, k)-fun(a, k-1);
    }
};