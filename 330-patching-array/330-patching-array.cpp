class Solution {
public:
    #define ll long long
    int minPatches(vector<int>& a, int n) {
        sort(a.begin(), a.end());
        int i=0;
        ll s=1, ct=0;
        while(s<=n){
            if(i<a.size() and a[i]<=s){
                s+=a[i];
                i++;
            }else{
                s+=s;
                ct++;
            }
        }
        return ct;
    }
};