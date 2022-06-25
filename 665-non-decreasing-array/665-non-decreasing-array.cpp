bool cmp(int a, int b){
    return a<b;
}

class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        
        if(a.size()==1)return true;
        for(int i=1;i<a.size();i++){
            if(a[i]<a[i-1]){
                int temp=a[i-1];
                a[i-1]=a[i];
                
                if(is_sorted(a.begin(), a.end(), cmp)){
                    return true;
                }else{
                    a[i-1]=a[i]=temp;
                    if(is_sorted(a.begin(), a.end(), cmp))return true;
                    else{
                        return false;
                    }
                }
            }
        }
        return true;
    }
};