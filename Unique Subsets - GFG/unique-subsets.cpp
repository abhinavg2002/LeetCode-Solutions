// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> a, int n)
    {
        vector<vector<int>> v;
        set<vector<int>> s;
        for(int i=0;i<(1<<n);i++){
            vector<int> t;
            for(int j=0;j<n;j++){
                if((i&(1<<j))!=0){
                    t.push_back(a[j]);
                }
            }
            sort(t.begin(), t.end());
            s.insert(t);
        }
        for(auto x:s){
            v.push_back(x);
        }
        return v;
        // code here 
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A;
        int x;
        for(int i=0;i<n;i++){
            cin>>x;
            A.push_back(x);
        }
        Solution obj;
        vector<vector<int> > result = obj.AllSubsets(A,n);
        // printing the output
        for(int i=0;i<result.size();i++){
            cout<<'(';
            for(int j=0;j<result[i].size();j++){
                cout<<result[i][j];
                if(j<result[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<"\n";
    }
}   


  // } Driver Code Ends