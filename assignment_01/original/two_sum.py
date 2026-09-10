class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        given arr nums, int target
        go through nums, save diff to map of idxes
        return idxes if it = target - num
        """
        idxes = {}
        for i in range(len(nums)):
            num = nums[i]
            diff = target - num
            if diff in idxes:
                return [i, idxes[diff]]
            idxes[num] = i
