//leetcode 4 Median of Two Sorted Arrays
//author:guo chen
//date:2017/03/16

// 时间复杂度 O(log(m+n))
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

double findMedian(vector<int>::const_iterator itea1, int m, vector<int>::const_iterator itea2, int n, int k)
{
	if (m > n)
		return findMedian(itea2, n, itea1, m, k);
	if (m == 0)
		return *(itea2 + k - 1);
	if (k == 1)
		return min(*itea1, *itea2);

	int ak = min(k / 2, m), bk = k - ak;
	if (itea1[ak - 1] < itea2[bk - 1])
	{
		return findMedian(itea1 + ak, m - ak, itea2, n, k - ak);
	}
	else if (itea1[ak - 1] > itea2[bk - 1])
		return findMedian(itea1, m, itea2 + bk, n - bk, k - bk);
	else
		return itea1[ak - 1];
}

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		if (!m || !n)
			return !m ? (n & 0x1 ? nums2[n / 2] : (nums2[n / 2 - 1] + nums2[n / 2]) / 2.0) : (m & 0x1 ? nums1[m / 2] : (nums1[m / 2 - 1] + nums1[m / 2]) / 2.0);
		int k = m + n;
		double result = 0;
		if (k & 0x1)//判断奇偶数
			result = findMedian(nums1.cbegin(), m, nums2.cbegin(), n, k/2+1);
		else
			result = (findMedian(nums1.cbegin(), m, nums2.cbegin(), n, k/2)
				+ findMedian(nums1.cbegin(), m, nums2.cbegin(), n, k/2+1)) / 2.0;
		return result;
	}
};


int main()
{
	vector<int> nums1{ 3 };
	vector<int> nums2{1,2 };
	Solution s;
	cout << s.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}