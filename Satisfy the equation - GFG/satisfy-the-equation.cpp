//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> satisfyEqn(int a[], int n) {
        map<int,vector<pair<int,int>>> m;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                m[a[i]+a[j]].push_back({i, j});
            }
        }
        vector<int> ok;
        int mn=1e9;
        for(auto x:m){
            sort(x.second.begin() , x.second.end());
            if(x.second.size()>1){
                for (int i = 1 ; i < x.second.size() ; i++){
                    if (x.second[0].first  < x.second[i].first and x.second[0].second != x.second[i].first and x.second[0].second != x.second[i].second){
                       vector<int> curr; // stroing curr ans 
                       curr = {x.second[0].first , x.second[0].second , x.second[i].first, x.second[i].second}; 
                       if (ok.empty()){
                        ok = curr;
                       }
                       else if (ok > curr){
                       ok = curr;
                       }
                    }
            }
            }
        }
        if(ok.size()==0){
            return {-1,-1,-1,-1};
        }
        return ok;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        vector<int> ptr = ob.satisfyEqn(A,N);
        
        cout<<ptr[0]<<" "<<ptr[1]<<" "<<ptr[2]<<" "<<ptr[3]<<endl;
    }
    return 0;
}
// } Driver Code Ends