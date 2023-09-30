// while checking for the next greater element (NGE) of num
// we are also checking the NGE of elements that comes after num and are <= num
// we store the elements in minStack and set all their values as NGE once we find the NGE

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> res(n, -1);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[nums1[i]] = i;
        }

        stack<int> minStack;
        for(auto& num : nums2){
            while(minStack.size() && num > minStack.top()){
                int ind = mp[minStack.top()];
                res[ind] = num;
                minStack.pop();
            }
            if(mp.find(num) != mp.end()){
                minStack.push(num);
            }
        }
        return res;
    }
};