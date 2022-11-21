//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int countTriplets(vector<int>a){
	    unordered_map<int,unordered_map<int,int>> m;
	    int n=a.size();
	    for(int i=0;i<n;i++){
	        for(int j=i+1;j<n;j++){
	            if(a[j]>a[i]){
	                m[a[j]][j]++;
	            }
	        }
	    }
	    int ans=0;
	    for(auto X:m){
	        int e=X.first;
	        for(auto x:X.second){
    	        int j=x.first;
    	        int ct=x.second;
    	        for(int i=j+1;i<n;i++){
    	            if(a[i]>e){
    	                ans+=ct;
    	            }
    	        }
	        }
	    }
	    return ans;
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
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution ob;
		int ans = ob.countTriplets(nums);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends