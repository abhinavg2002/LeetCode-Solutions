//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> a) {
        unordered_map<int,int> m;
        for(auto x:a)m[x]++;
        int ans=0;
        for(auto x:a){
            m[x]--;
            if(m[x]==0)m.erase(x);
            for(int i=1;i<=sqrt(x);i++){
                if(x%i==0){
                    if(m.count(i)){
                        ans++;
                        break;
                    }
                    if(x!=i*i){
                        if(m.count(x/i)){
                            ans++;
                            break;
                        }
                    }
                }
            }
            m[x]++;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends