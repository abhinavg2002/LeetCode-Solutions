// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    long long countKdivPairs(int a[], int n, int k)
    {
        //code here
        long long ans=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            int s=a[i]%k;
            if(m.count(k-s)){
                ans+=m[k-s];
            }else if(s==0 and m.count(0)){
                ans+=m[0];
            }
            m[s]++;
        }
        return ans;
    }
    
};

// { Driver Code Starts.

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

		int k;
		cin >> k;

        Solution ob;
		cout << ob. countKdivPairs(a, n , k) << "\n";



	}


	return 0;
}
  // } Driver Code Ends