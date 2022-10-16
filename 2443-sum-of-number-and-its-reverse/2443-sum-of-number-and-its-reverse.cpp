class Solution {
public:
    bool sumOfNumberAndReverse(int num) {
        for (int i = 0; i <= num; i++)
        {
            int x = i, y = 0;
            while(x){
                y = y*10 + x%10;
                x /= 10;
            }
            if(y+i == num){
                return 1;
            }
        }
        return 0;
    }
};