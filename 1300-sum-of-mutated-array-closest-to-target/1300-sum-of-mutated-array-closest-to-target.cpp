class Solution {
public:
    int findBestValue(vector<int>& a, int target) {
        int n=a.size();
        sort(a.begin(), a.end());
        vector<int> cal(n);
        cal[0]=a[0];
        //cout<<cal[0]<<" ";
        for(int i=1;i<n;i++){
            cal[i]=cal[i-1]+a[i];
            //cout<<cal[i]<<" ";
        }
        //cout<<endl;
        
        int ans=0;
        int p=abs(target);
        for(int i=1;i<=a[n-1];i++){
            if(i<a[0]){
                if(p>abs(target-n*i)){
                    p=abs(target-n*i);
                    ans=i;
                }
            }else{
                int id=upper_bound(a.begin(), a.end(), i)-a.begin();
                id--;
                int sum=cal[id]+i*(n-1-id);
                if(p>abs(target-abs(sum))){
                    p=abs(target-abs(sum));
                    ans=i;
                }
                // cout<<id<<endl;
                // cout<<sum<<endl;
            }
            // cout<<p<<endl;
            // cout<<ans<<endl;
            // cout<<endl;
        }
        return ans;
    }
};