class Solution {
public:
    bool find132pattern(vector<int>& a) {
        stack<int> s;
        int n=a.size();
        int x=INT_MIN;
        for(int i=n-1;i>=0;i--){
            if(a[i]<x){
                return true;
            }else{
                while(!s.empty() and a[i]>s.top()){
                    x=s.top();
                    s.pop();
                }
                s.push(a[i]);
            }
        }
        return false;
    }
    
};