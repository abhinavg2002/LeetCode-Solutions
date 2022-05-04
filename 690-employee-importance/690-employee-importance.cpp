/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    map<int, Employee*> m;
    int fun(int i){
        int ans=m[i]->importance;
        for(auto x:m[i]->subordinates){
            ans+=fun(x);
        }
        return ans;
    }
    int getImportance(vector<Employee*> e, int id) {
        for(auto x:e){
            m[x->id]=x;
        }
        return fun(id);
    }
};