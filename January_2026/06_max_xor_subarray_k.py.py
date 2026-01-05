# ============================================================
#  Max XOR of every subarray of size k — 5 Approaches
# ============================================================
# Problem:
#   Given an array arr[] and an integer k,
#   find the maximum XOR value among ALL subarrays of size exactly k.
#
# ------------------------------------------------------------
# Legend:
#   n = length of array
# ------------------------------------------------------------


# ============================================================
# 1️⃣  BRUTE FORCE — recompute XOR every window
# ============================================================
# Intuition:
#   Try every subarray of size k and compute XOR from scratch.
#
# Why it works:
#   We're literally checking all possible windows.
#
# Complexity:
#   Time  : O(n * k)       -> nested loop
#   Space : O(1)
# ============================================================
def max_xor_bruteforce(arr, k):
    n = len(arr)
    ans = 0

    for i in range(n - k + 1):
        xor_value = 0
        for j in range(i, i + k):
            xor_value ^= arr[j]

        ans = max(ans, xor_value)

    return ans



# ============================================================
# 2️⃣  SLIDING WINDOW XOR — optimal practical solution
# ============================================================
# Intuition:
#   We maintain XOR of the current window.
#
# XOR Trick:
#   To remove an element from XOR window:
#       x ^ a ^ a  =  x
#   So instead of subtracting like sums,
#   we XOR again with the outgoing element.
#
# Complexity:
#   Time  : O(n)
#   Space : O(1)
# ============================================================
def max_xor_sliding_window(arr, k):
    n = len(arr)
    if k > n:
        return 0

    window = 0

    # XOR of first window
    for i in range(k):
        window ^= arr[i]

    ans = window

    # Slide the window
    for i in range(k, n):
        window ^= arr[i]      # add new element
        window ^= arr[i - k]  # remove outgoing element (XOR again)
        ans = max(ans, window)

    return ans



# ============================================================
# 3️⃣  PREFIX XOR
# ============================================================
# Intuition:
#   Prefix XOR allows constant-time range XOR.
#
# Definition:
#   prefix[i] = arr[0] ^ arr[1] ^ ... ^ arr[i]
#
# Then:
#   XOR(l..r) = prefix[r] ^ prefix[l-1]
#
# Why it works:
#   Values cancel because:
#       a ^ b ^ c ^ a ^ b = c
#
# Complexity:
#   Time  : O(n)
#   Space : O(n)
# ============================================================
def max_xor_prefix(arr, k):
    n = len(arr)

    prefix = [0] * n
    prefix[0] = arr[0]

    for i in range(1, n):
        prefix[i] = prefix[i - 1] ^ arr[i]

    ans = 0

    for i in range(n - k + 1):
        r = i + k - 1
        if i == 0:
            xor_value = prefix[r]
        else:
            xor_value = prefix[r] ^ prefix[i - 1]

        ans = max(ans, xor_value)

    return ans

