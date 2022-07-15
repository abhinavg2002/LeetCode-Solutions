// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this method */

class Solution{
  public:
    int n;
    vector<int> visit;
    bool fun(int v[], int sum, int target, int id, int k){
        if(k==1)return true;
        if(sum==target){
            return fun(v, 0, target, 0, k-1);
        }
        for(int i=id;i<n;i++){
            if((visit[i]) or sum+v[i]>target)continue;
            visit[i]=1;
            int ans=fun(v, sum+v[i], target, i+1, k);
            if(ans)return true;
            visit[i]=0;
        }
        return false;
    }
    bool isKPartitionPossible(int a[], int n, int k)
    {
        this->n=n;
        int sum=accumulate(a, a+n, 0);
        if(n<k or sum%k)return false;
        int target=sum/k;
        visit.resize(n, 0);
        return fun(a, 0, target, 0, k);
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}  // } Driver Code Ends