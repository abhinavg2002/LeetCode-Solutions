//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	public:
	int LongestBitonicSequence(vector<int>a)
	{
	    int n=a.size();
        vector<int> dp1(n, 1), dp2(n, 1);;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[j]<a[i]){
                    dp1[i]=max(dp1[i],1+dp1[j]);
                }
            }
        }
        vector<int> b=a;
        reverse(b.begin(), b.end());
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(b[j]<b[i]){
                    dp2[i]=max(dp2[i],1+dp2[j]);
                }
            }
        }
        int mx=0, sum=0;
        for(int i=0;i<n;i++){
            sum=dp1[i]+dp2[n-i-1];
            mx=max(sum, mx);
        }
        return mx-1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution ob;
		int ans = ob.LongestBitonicSequence(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends