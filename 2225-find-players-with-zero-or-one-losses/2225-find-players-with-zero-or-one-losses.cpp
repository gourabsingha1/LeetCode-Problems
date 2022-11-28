class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> ml;
        vector<int> answer0, answer1;
        vector<vector<int>> ans;
                priority_queue<int, vector<int>, greater<int>> pq0, pq1;
        for (auto &x : matches){
            ml[x[1]]++;
        }
        for(auto &x : ml){
            if(x.second==1){
                pq1.push(x.first);
            }
        }
        for(auto &x : matches){
            if(ml[x[0]]==0){
                pq0.push(x[0]);
                ml[x[0]] = 1;
            }
        }
        while(!pq0.empty()){
            answer0.push_back(pq0.top());
            pq0.pop();
        }
        while(!pq1.empty()){
            answer1.push_back(pq1.top());
            pq1.pop();
        }
        ans.push_back(answer0);
        ans.push_back(answer1);
        return ans;
    }
};