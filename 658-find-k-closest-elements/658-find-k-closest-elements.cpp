class Solution {
public:
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
        int i=-1, j=-1;
        int n=a.size();
        vector<int> v;
        if(binary_search(a.begin(), a.end(), x)){
            i=lower_bound(a.begin(), a.end(), x)-a.begin();
            j=i+1;
        }else{
            i=lower_bound(a.begin(), a.end(), x)-a.begin()-1;
            j=i+1;
        }
        
        while(i>=0 and j<n and v.size()!=k){
            if(abs(a[i]-x)<abs(a[j]-x)){
                v.push_back(a[i]);
                i--;
            }
            else if(abs(a[i]-x)>abs(a[j]-x)){
                v.push_back(a[j]);
                j++;
            }else{
                if(a[i]<=a[j]){
                    v.push_back(a[i]);
                    i--;
                }else{
                    v.push_back(a[j]);
                    j++;
                }
            }
        }
        
        while(i>=0 and v.size()!=k){
            v.push_back(a[i]);
            i--;
        }
        while(j<n and v.size()!=k){
            v.push_back(a[j]);j++;
        }
        
        sort(v.begin(), v.end());
        return v;
        
    }
};