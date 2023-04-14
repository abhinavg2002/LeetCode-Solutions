//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int finLength(int n, vector<int> c, vector<int> r) {
        vector<pair<int,int>> a;
        for(int i=0;i<n;i++){
            pair<int,int> p={c[i], r[i]};
            if(a.size()){
                auto x=a.back();
                if(x.first==p.first and x.second==p.second){
                    a.pop_back();
                }else{
                    a.push_back(p);
                }
            }else{
                a.push_back(p);
            }
        }
        return a.size();
    }
};


//{ Driver Code Starts.
int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        vector<int> color(n), radius(n);
        for (int i = 0; i < n; i++) cin >> color[i];
        for (int i = 0; i < n; i++) cin >> radius[i];
        int ans = sol.finLength(n, color, radius);
        cout << ans << "\n";
    }

    return 0;
}

// } Driver Code Ends