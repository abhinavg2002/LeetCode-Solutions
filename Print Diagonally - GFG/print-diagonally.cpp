//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> a)
	{
	    vector<int> ans;
	    for(int i=0;i<n;i++){
	        for(int j=i, r=0;j>=0 and r<n;j--, r++){
	            ans.push_back(a[r][j]);
	        }
	    }
	    for(int i=1;i<n;i++){
	        for(int j=n-1, r=i;j>=0 and r<n;j--, r++){
	            ans.push_back(a[r][j]);
	        }
	    }
	    return ans;
		// Your code goes here
	}

};

//{ Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}

// } Driver Code Ends