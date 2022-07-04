// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int a[], int n){
        int ct=0;
        int mn=INT_MAX, mx=0;
        int sum1=0, sum2=0;
        int f=0;
        for(int i=0;i<n;i++){
            int x=a[i];
            if(x>0){
                ct++;
            }
            f+=x;
            sum1+=x;
            sum2+=x;
            if(sum1>0)sum1=0;
            mn=min(mn, sum1);
            
            if(sum2<0)sum2=0;
            mx=max(mx, sum2);
        }
        if(!ct){
            return *max_element(a, a+n);
        }
        return max(mx, f-mn);
        // your code here
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends