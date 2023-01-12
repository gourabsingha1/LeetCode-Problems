class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0, bob = 0, a = 0, b = 0;
        for(auto &x : colors){
            if(x == 'A'){
                b = 0;
                a++;
                if(a > 2) alice++;
            }
            else{
                a = 0;
                b++;
                if(b > 2) bob++;
            }
        }
        return alice > bob;
    }
};