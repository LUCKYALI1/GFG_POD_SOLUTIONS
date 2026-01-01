'''
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

'''
class Solution:
    def intersectPoint(self, head1, head2):
        if not head1 or not head2:
            return None
        
        a = head1
        b = head2
        
    
        while a != b:
            a = head2 if a is None else a.next
            b = head1 if b is None else b.next
        
        return a  
