class Solution {
public:
    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        int n = chargeTimes.size();
        
        int res = 0;
        int i=0;
        int j=0;
        
        deque<int> dq;
        long long sum = 0;
        long long cost = 0;
        
        while(j<n){
            sum += runningCosts[j];
            while(!dq.empty() && dq.back() < chargeTimes[j]) dq.pop_back();
            
            dq.push_back(chargeTimes[j]);
            cost = sum*(j-i+1) + dq.front();
            
            if(cost <= budget) res = max(res, j-i+1);
            else{
                while(cost > budget){
                    sum -= runningCosts[i];
                    if(dq.front() == chargeTimes[i]) dq.pop_front();
                    i++;
                
                    cost = sum*(j-i+1) + dq.front();
                }
            }
            j++;
        }
        return res;
    }
};