#pragma once
#include <vector>
#include <iostream>
#include <map>
class Solution {
public:
	/*第一题 两数之和 2020.4.1
	*/
	std::vector<int> twoSum(std::vector<int>& nums, int target, int method) {   
		short length = nums.size();
		std::vector<int> result;
		result.reserve(2);
		if (method == 0) //暴力解决法
		{
			for (size_t i = 0; i < length - 1; i++)
			{
				for (size_t j = i + 1; j < length; j++)
				{
					if ((nums[i] + nums[j]) == target) {
						result.push_back(i);
						result.push_back(j);
						return result;
					}
				}
			}
		}
		else   //hash
		{
			std::map<int, int> m;
			for (size_t i = 0; i < length; i++)
			{
				m.insert(std::pair<int, int>(nums[i], i));
			}
			for (size_t i = 0; i < length; i++) {
				int temp = target - nums[i];
				auto iter = m.find(temp);
				if (iter != m.end() && m[temp] != i)
				{
					result.push_back(i+1);
					result.push_back(m[temp]+1);
					return result;
				}
			}
		}
		std::cout << "no result" << std::endl;
		return result;
	}
};