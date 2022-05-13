class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& a) {
        sort(a.begin(), a.end(), [](vector<int>&x, vector<int>&y){
            return x[1]==y[1]?x[0]>y[0]:x[1]<y[1];
        });
        int n=a.size();
        int p1=-1, p2=-1, ans=0;
        for(int i=0;i<n;i++){
            if(a[i][0]<=p1)continue;
            if(a[i][0]>p2){
                p2=a[i][1];
                p1=p2-1;
                ans+=2;
            }else{
                ans++;
                p1=p2;
                p2=a[i][1];
            }
        }
        return ans;
    }
};