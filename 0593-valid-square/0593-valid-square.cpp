class Solution {
public:
    double dist(vector<int>& p1, vector<int>& p2){
        return sqrt((p1[0]-p2[0])*(p1[0]-p2[0]) + (p1[1]-p2[1])*(p1[1]-p2[1]));
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<double> s;
        s.insert({dist(p1,p2), dist(p1,p3), dist(p1,p4), dist(p2,p3), dist(p2,p4), dist(p3,p4)});
        for(auto &x : s){
            if(!x){
                return 0;
            }
        }
        return s.size()==2;
    }
};