// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
    public:
        int findNum(int n){
        //complete the function here
            auto check=[&](int m){
                int count = 0;
                for (int i = 5; m/i>=1; i*=5)
                    count += m/i;
                return count>=n;  
            };
            int l=5, h=1e9, ans;
            while(l<=h){
                int mid=l+(h-l)/2;
                if(check(mid)){
                    ans=mid;
                    h=mid-1;
                }else{
                    l=mid+1;
                }
            }
            return ans;
        }
};

// { Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        Solution ob;
        cout <<ob.findNum(n) << endl;
    }
return 0;
}  // } Driver Code Ends