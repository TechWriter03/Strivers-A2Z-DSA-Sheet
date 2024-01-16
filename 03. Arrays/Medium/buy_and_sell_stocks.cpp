// Input: 
// prices = [7,1,5,3,6,4]
// Output: 
// 5
// Explanation: 
// Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

int maxProfit(vector<int>& prices) 
{
    int mini=prices[0],maxi=0;
    for(int i=0;i<prices.size();i++)
    {
        mini=min(mini,prices[i]);
        maxi=max(maxi,prices[i]-mini);
    }
    return maxi;
}
