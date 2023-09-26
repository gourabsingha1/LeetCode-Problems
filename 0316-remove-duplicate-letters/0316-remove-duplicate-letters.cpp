// minStack: to keep strings in smallest lexicographical order
// freq: to check whether a character occurs in future
// seen: to not push duplicate elements

class Solution {
public:
    string removeDuplicateLetters(string s) {
        string res;
        unordered_map<char, int> freq, seen;
        for(auto& ch : s) {
            freq[ch]++;
        }
        stack<char> minStack;
        for(auto& ch : s) {
            freq[ch]--;
            if(seen[ch]) continue;
            
            while(minStack.size() && minStack.top() > ch && freq[minStack.top()]) {
                seen[minStack.top()] = 0;
                minStack.pop();
            }
            minStack.push(ch);
            seen[ch] = 1;
        }
        while(minStack.size()) {
            res = minStack.top() + res;
            minStack.pop();
        }
        return res;
    }
};