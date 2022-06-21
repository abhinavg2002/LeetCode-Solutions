class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) {
        priority_queue<int> p;
        int i=0;
        int n=h.size();
        for(;i<n-1;i++){
            int dif=h[i+1]-h[i];
            if(dif<=0)continue;
            if(dif<=b){
                b-=dif;
                p.push(dif);
            }else if(l>0){
                if(p.size()>0 and p.top()>=dif){
                    b+=p.top();
                    p.pop();
                    b-=dif;
                    p.push(dif);
                }
                    l--;
            }else{
                break;
            }
        }
        return i;
    }
};