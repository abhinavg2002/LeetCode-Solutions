class Solution {
public:
    int numTimesAllBlue(vector<int>& a) {
        int r=0;
        int n=a.size();
        int ct=0;
        for(int i=0;i<n;i++){
            r=max(r, a[i]);
            if(r==i+1){
                ct++;
            }
        }
        return ct;
    }
};