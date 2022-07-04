// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
public:
    int maxPoints(int x[], int y[], int n) {
       //code here
        int ans=0;
        for(int i=0;i<n;i++){
            map<pair<int, int>, int> m;
            int d=0;
            for(int j=i;j<n;j++){
                int dx=x[i]-x[j];
                int dy=y[i]-y[j];
                if(!dx and !dy)d++;
                else{
                    int g=__gcd(dx, dy);
                    dx/=g;
                    dy/=g;
                    m[{dy, dx}]++;
                }
            }
            ans=max(ans, d);
            for(auto x:m){
                ans=max(ans, x.second+d);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x[n], y[n];
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        for(int i=0;i<n;i++){
            cin>>y[i];
        }
        Solution ob;
        cout << ob.maxPoints(x, y, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends