# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode):
        ptrA, ptrB = headA, headB

        itr = 0

        while(ptrA!=ptrB) and itr<100000:
            ptrA = ptrA.next
            ptrB = ptrB.next
            if ptrA==None:
                ptrA = headB
            if ptrB==None:
                ptrB = headA
            itr += 1

        if ptrA==ptrB:
            return ptrA
        
        return None