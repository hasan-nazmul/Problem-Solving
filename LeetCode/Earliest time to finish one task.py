class Solution:
    def earliestTime(self, tasks: list[list[int]]) -> int:
        tli = [x+y for x,y in tasks]
        tli = sorted(tli)
        return tli[0]