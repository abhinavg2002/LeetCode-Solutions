class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(), [](vector<int>&a, vector<int>&b){
            if(a[1]==b[1]){
                return a[0]>b[0];
            }
            return a[1]<b[1]; 
        });
        priority_queue<int> p;
        int ct=0; int time=0;
        for(auto &x:courses){
            if(time+x[0]<=x[1]){
                time+=x[0];
                ct++;
                p.push(x[0]);
            }else{
                if(p.size()){
                    int v=p.top();
                    if(x[0]<v){
                        time-=v;
                        time+=x[0];
                        p.pop();
                        p.push(x[0]);
                    }
                }
            }
        }
        return ct;
    }
};