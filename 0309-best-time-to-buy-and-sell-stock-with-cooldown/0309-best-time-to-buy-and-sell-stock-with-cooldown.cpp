class Solution {
public:
    int maxProfit(vector<int> &prices)
    {
        int buy = INT_MIN, sell = 0, prev_sell = 0, prev_buy;
        for (int &x : prices)
        {
            prev_buy = buy;
            buy = max(prev_sell - x, buy);
            prev_sell = sell;
            sell = max(prev_buy + x, sell);
        }
        return sell;
    }
};