class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        int a=0, o=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            a^=arr[i];
            o^=(i+1);
        }
        a^=o;
        int res=a&(-a);
        int n1=0, n2=0;
        for(int i=0;i<n;i++){
            if(arr[i]&res){
                n1^=arr[i];
            }else{
                n2^=arr[i];
            }
        }
        for(int i=1;i<=n;i++){
            if(i&res){
                n1^=i;
            }else{
                n2^=i;
            }
        }
        vector<int> ans;
        if(find(arr.begin(), arr.end(), n1)==arr.end()){
            return {n2, n1};
        }
        else{
            return {n1, n2};
        }
    }
};