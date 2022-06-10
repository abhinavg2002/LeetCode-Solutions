// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
bool sortbysec(const pair<int,int> &a,
             const pair<int,int> &b)
   {
       return (a.second < b.second);
    } 

class Solution {
  public:
     // this function is used for sorting purpose of vector of //pair on the basis of second element.

    
   int maxCoins(int A[], int B[], int T, int N) {
       // code here
       int sum = 0;
       vector<pair<int,int>> vec;
       
       for(int i = 0;i < N;i++)
        vec.push_back(make_pair(A[i],B[i]));
        
        sort(vec.begin(), vec.end(), sortbysec);
                       
         for (int i=N-1; i>=0; i--)
         {  
           
                if(vec[i].first >= T)
                 {
                     sum = sum + vec[i].second*T;
                     T = 0;
                     return sum;
                 }
                else{
                    
                    sum = sum + vec[i].first*vec[i].second;  
                    T = T - vec[i].first; 
                }
                             
           
        }
        return sum;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int T,N;
        cin>>T>>N;
        
        int A[N], B[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<N; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.maxCoins(A,B,T,N) << endl;
    }
    return 0;
}  // } Driver Code Ends