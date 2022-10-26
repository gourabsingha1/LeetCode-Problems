class Solution {
public:
    int calc(vector<int>& nums1, vector<int>& nums2){
        int res = 0;
        unordered_map<long long int,int> m;
        for (int i = 0; i < nums2.size(); i++)
        {
            for (int j = i+1; j < nums2.size(); j++)
            {
                m[(long long int)nums2[i]*nums2[j]]++;
            }
        }
        
        for (int i = 0; i < nums1.size(); i++)
        {
            if(m[(long long int)nums1[i]*nums1[i]]){
                res += m[(long long int)nums1[i]*nums1[i]];
            }
        }
        return res;
    }

    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return calc(nums1, nums2) + calc(nums2, nums1);
    }
};