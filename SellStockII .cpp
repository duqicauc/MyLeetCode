/*题目描述
Say you have an array for which the i(th) element is the price of a given stock on day i.
假设你有一个数组：第i个元素表示给定某支股票在第i天的价格。

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell
one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you 
must sell the stock before you buy again).
要求：设计一个算法，求最大收益值。可以对同一支股票完成多次交易，然而不能同时操作多笔交易

后面的描述更像是迷惑作用：此处只要求出最佳收益值就可以，无需关注何时买卖。

*/

class Solution {
public:
    int maxProfit(vector<int> &prices) {
      if(prices.size()<=1)
		    return 0;
	    int total=0;
	    for(int i=1;i<prices.size();i++){
		    int dist = prices[i]-prices[i-1];
		    if(dist>0)
			    total += dist;
	    }
	    return total;
    }
};
