class Solution {
public:
    int mi = INT_MAX;
    int a = 0, b = 0;
    void divCount(int n){
        for (int i = 1; i <= sqrt(n); i++)
        {
            if(n%i == 0){
                if(n/i - i < mi){
                    mi = n/i - i;
                    a = i, b = n/i;
                }
            }
        }
    }
    vector<int> closestDivisors(int num) {
        divCount(num+1);
        divCount(num+2);
        return {a, b};
    }
};