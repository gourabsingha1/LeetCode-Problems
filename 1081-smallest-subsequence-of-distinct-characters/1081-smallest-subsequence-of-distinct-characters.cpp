// minStack: to keep strings in smallest lexicographical order
// freq: to check whether a character occurs in future
// seen: to not push duplicate elements

class Solution {
public:
    string smallestSubsequence(string s) {
        string minStack;
        vector<int> freq(26, 0), seen(26, 0);
        for(auto& ch : s) {
            freq[ch - 'a']++;
        }
        for(auto& ch : s) {
            freq[ch - 'a']--;
            if(seen[ch - 'a']) continue;
            
            while(minStack.size() && minStack.back() > ch && freq[minStack.back() - 'a']) {
                seen[minStack.back() - 'a'] = 0;
                minStack.pop_back();
            }
            minStack.push_back(ch);
            seen[ch - 'a'] = 1;
        }
        return minStack;
    }
};