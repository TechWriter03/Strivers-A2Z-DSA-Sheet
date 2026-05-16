// Input:
// prices = [7,1,5,3,6,4]
// Output:
// 5
// Explanation:
// Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
// Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

int maxProfit(vector<int>& prices)
{
    int n=prices.size(),mini=INT_MAX,profit=0;
    for(int i=0;i<n;i++)
    {
        profit=max(prices[i]-mini,profit);
        mini=min(prices[i],mini);
    }
    return profit;
}
