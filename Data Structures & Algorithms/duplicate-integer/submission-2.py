class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        a = list(set(nums))
        return not (len(a) == len(nums))
        