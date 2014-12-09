/*
A peak element is an element that is greater than its neighbors.
“峰值元素”指的是该元素比它的两个邻居元素都大。
Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
该题目的要求：输入为一个各个元素都不相同的数组，要求找到一个峰值元素并返回它的索引值。
The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
一个数组中可能包含多个“峰值”，这种情况下返回任意一个峰值元素的索引即可。
You may imagine that num[-1] = num[n] = -∞.
可以做出假设：num[-1] = num[n] = -∞。
For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.

！！注意：算法的时间复杂度应该达到对数时间复杂度——O(logN)
*/
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(const vector<int> &num){
	int len = num.size();
	int low = 0;
	int high = len-1;

	while(low <= high){
		int mid = (low + high)/2;
		//设置num[mid]的左右邻居的值
		int left,right;
		if(mid-1 == -1)
			left = INT_MIN;
		else
			left = num[mid - 1];
		if(mid+1 == len)
			right = INT_MIN;
		else
			right = num[mid+1];

		// 判断num[mid]是否满足条件（注意第二个else if判断是基于第一个的短路判断）
		if(num[mid]>left && num[mid]>right)
			return mid;
		else if(num[mid]<right)
			low = mid + 1;
		else
			high = mid - 1;
	}
	return 0;
}


int main()
{
	vector<int> num;
	//1、num[0]或者num[len-1]为最小值时，例如：[-2147483648，-2147483648]
	//num.push_back(-2147483648);
	//num.push_back(-2147483647);
	//2、数组只有一个元素为最小值时，例如：[-2147483648]
	//num.push_back(-2147483648);
	//3、常规例子
	num.push_back(1);
	num.push_back(2);
	num.push_back(3);
	num.push_back(1);
	int res = findPeakElement(num);
	cout << "The Peak Element is " << res <<endl;
	return 0;
}
