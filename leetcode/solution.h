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

	int removeDuplicates(std::vector<int>& nums) { //已经排序好的
		/*
		解题思路:双指针
		j作为一个指针，不断后移，i只记录不重复的元素，每当前后不相同时，会讲j指针对应的记录到i指针的位置，并且后移i指针。其中++i 是使用完i值以后，对i进行+1
		*/
		int length = nums.size();
		if (length == 0)
		{
			return 0;
		}
		int i = 0;
		int j = 0;
		while (j < length) {
			if (nums[i] != nums[j])
			{
				nums[++i] = nums[j];
			}
			j++;
		}
		return i + 1;
	}
};