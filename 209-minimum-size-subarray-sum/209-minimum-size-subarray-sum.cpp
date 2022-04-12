class Solution {
public:
    int minSubArrayLen(int x, vector<int>& a) {
        int i=0, j=0;
        int n=a.size();
        int sum=0;
        int mn=INT_MAX;
        while(j<n){
            sum+=a[j];
            while(sum>=x){
                mn=min(mn, j-i+1);
                sum-=a[i++];
            }
            j++;
        }
        if(mn==INT_MAX)return 0;
        return mn;
    }
};