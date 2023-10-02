class Solution {
public:
    bool winnerOfGame(string colors) {
        int a = 0, b = 0, i = 0, n = colors.size();
        while(i < n) {
            int cnt = 0;
            while(i < n && colors[i] == 'A') {
                i++, cnt++;
            }
            a += max(0, cnt - 2);
            cnt = 0;
            while(i < n && colors[i] == 'B') {
                i++, cnt++;
            }
            b += max(0, cnt - 2);
        }
        cout<<a<<' '<<b<<endl;
        return a > b;
    }
};