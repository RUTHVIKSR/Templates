class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
        int n = gas.size();
        int sumG = 0;
        int sumC = 0;
        for(int i=0;i<n;i++){
            sumG += gas[i];  
            sumC += cost[i];
        }      
        if(sumC > sumG)
            return -1;

        int total = 0;
        int start = 0;
        for(int i=0;i<n;i++){
            int diff = gas[i] - cost[i];
            total += diff;
            if(total < 0){
                total = 0;
                start = i + 1;
            }
        }

        return start;
    }
};
