//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    int ans=0;
            int n=s.size();
            int mf=0;
            unordered_map<char, int> m;
            for(int i=0;i<n;i++){
                m[s[i]]++;
                // mf maintain max freq of char in window to usko rakh ke hm baaki char ko change 
                // karenge to wo check karenge agr wo dif k se km hai to hm ans ko bada denge
                mf=max(mf, m[s[i]]);
                if(ans-mf<k){
                    ans++;
                }else{
                    m[s[i-ans]]--;
                }
            }
            return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends