class Solution:
    def maxKDistinct(self, nums: list[int], k: int) -> list[int]:
        nums.sort(reverse=True)
        st = set()
        for i in nums:
            st.add(i)
            if len(st)==k:
                break
        st = list(st)
        return sorted(st, reverse=True)