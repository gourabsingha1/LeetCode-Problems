class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        priority_queue<pair<int, char>> pq;
        pq.push({a, 'a'}), pq.push({b, 'b'}), pq.push({c, 'c'});
        while(1){
            auto [freq1, ch1] = pq.top();
            pq.pop();
            int x = min(2, freq1);
            res += string(x, ch1);
            freq1 -= x;

            auto [freq2, ch2] = pq.top();
            pq.pop();
            if(!freq2) {
                break;
            }
            
            int y = min(2, freq2);
            if(freq1 < freq2) {
                res += string(y, ch2);
                freq2 -= y;
            }
            else {
                res += ch2;
                freq2--;
            }
            pq.push({freq1, ch1});
            pq.push({freq2, ch2});
        } 
        return res;
    }
};