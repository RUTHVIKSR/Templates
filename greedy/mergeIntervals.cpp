class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[0] < b[0];
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        int n = intervals.size();
        if(n == 0)
            return ans;

        sort(intervals.begin(), intervals.end(), cmp);
        int start = intervals[0][0];
        int end = intervals[0][1];

        for(int i=1;i<n;i++){
            if(end >= intervals[i][0])
                end = max(end, intervals[i][1]);
            else{
                ans.push_back({start, end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        ans.push_back({start, temp});

        return ans;
    }
};
