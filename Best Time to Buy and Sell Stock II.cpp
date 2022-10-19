class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int Total_Profit=0;
        for(int i=1;i<prices.size();i++)
        {
            if(prices[i]-prices[i-1]>0) Total_Profit+=prices[i]-prices[i-1];
        }
        return Total_Profit;
    }
};