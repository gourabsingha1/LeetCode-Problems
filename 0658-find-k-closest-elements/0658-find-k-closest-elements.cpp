class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        int n = arr.size();
        int l = 0, h = n-1;
        while(l <= h){
            int m = (l+h)/2;
            if(arr[m] == x){
                l = m;
                break;
            }
            else if(arr[m] < x){
                l = m + 1;
            }
            else{
                h = m - 1;
            }
        }

        int i = l-1, j = l;
        while(res.size() != k)
        {
            if(j<n && i>=0 && abs(arr[i] - x) > abs(arr[j] - x)){
                res.push_back(arr[j++]);
            }
            else if(i >= 0){
                res.push_back(arr[i--]);
            }
            else{
                res.push_back(arr[j++]);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};