class Solution {
public:
    int threeSumClosest(vector<int>& a, int target) {
        sort(a.begin(), a.end());
        int n=a.size();
        vector<vector<int>> v;
        int best=INT_MAX;
        int mn=INT_MAX;
        for(int i=0;i<n;i++){
            int l=i+1, h=n-1;
            while(l<h){
                int sum=a[i]+a[l]+a[h];
                if(abs(target-sum)<mn){
                    mn=abs(target-sum);
                    best=sum;
                }
                if(sum>target)h--;
                else{
                    l++;
                }
            }   
        }
        return best;
    }
};