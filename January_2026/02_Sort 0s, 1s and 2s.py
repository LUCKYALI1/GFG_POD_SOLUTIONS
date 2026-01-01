class Solution:
    def sort012(self, arr):
        l = 0
        mid = 0
        h = len(arr) - 1
        
        while mid <= h:
            if arr[mid] == 0:
                arr[l], arr[mid] = arr[mid], arr[l]
                l += 1
                mid += 1
            
            elif arr[mid] == 1:
                mid += 1
            
            else:  # arr[mid] == 2
                arr[mid], arr[h] = arr[h], arr[mid]
                h -= 1
