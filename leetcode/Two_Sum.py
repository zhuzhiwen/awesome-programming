#!/usr/bin/python
class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        if not nums:
            return None
            
        d = {}
        for i, item in enumerate(nums):
            tmp  = target - item
            
            for key, value in d.items():
                if value == tmp:
                    return [key, i]
            
            d[i] = item
            
        return None

l = [2, 7, 11, 15]
s = Solution().twoSum(l, 4)
print(s)
