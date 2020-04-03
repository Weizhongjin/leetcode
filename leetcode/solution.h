#pragma once
#include <vector>
#include <iostream>
#include <map>
class Solution {
public:
	/*��һ�� ����֮�� 2020.4.1
	*/
	std::vector<int> twoSum(std::vector<int>& nums, int target, int method) {   
		short length = nums.size();
		std::vector<int> result;
		result.reserve(2);
		if (method == 0) //���������
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

	int removeDuplicates(std::vector<int>& nums) { //�Ѿ�����õ�
		/*
		����˼·:˫ָ��
		j��Ϊһ��ָ�룬���Ϻ��ƣ�iֻ��¼���ظ���Ԫ�أ�ÿ��ǰ����ͬʱ���ὲjָ���Ӧ�ļ�¼��iָ���λ�ã����Һ���iָ�롣����++i ��ʹ����iֵ�Ժ󣬶�i����+1
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