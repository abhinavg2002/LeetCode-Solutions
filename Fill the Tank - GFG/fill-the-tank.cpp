// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
    #define ll long long
    vector<vector<int>> l;
    bool fun(int src, int p, ll w, int *cap){
        if(cap[src]>w){
            return false;
        }
        w-=cap[src];
        int b=l[src].size();
        if(p!=-1){
            b--;
        }
        for(auto x:l[src]){
            if(x==p)continue;
            if(fun(x, src, w/b, cap)==0)return false;
        }
        return true;
    }
    long long minimum_amount(vector<vector<int>> &e, int n, int s, int *c){
       // Code here
        l.resize(n);
        s--;
        for(int i=0;i<e.size()-1;i++){
            auto x=e[i];
            x[0]--;
            x[1]--;
            l[x[0]].push_back(x[1]);
            l[x[1]].push_back(x[0]);
        }
        
        ll l=accumulate(c, c+n, 0ll);
        ll h=1e18, ans=-1;
        while(l<=h){
            ll m=l+(h-l)/2;
            if(fun(s, -1, m, c)){
                ans=m;
                h=m-1;
            }else{
                l=m+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends