// # Maximum Subarray Sum of Size **k**

// ## 🧠 Problem

// Given an array `arr` and an integer `k`, find the **maximum possible sum
// of any contiguous subarray of length `k`**.

// ------------------------------------------------------------------------

// ## 💡 Intuition

// A subarray of length `k` means:

//     arr[i], arr[i+1], ..., arr[i+k-1]

// Instead of recomputing the sum every time, we use a **sliding window**:

// 1.  Compute the sum of the first `k` elements.
// 2.  Slide one step:
//     -   Remove the element leaving the window.
//     -   Add the new element entering the window.
// 3.  Track the maximum sum throughout.

// ------------------------------------------------------------------------

// ## 🧭 Approach (Sliding Window)

// 1.  Compute sum of first `k` elements → `windowSum`.
// 2.  Initialize `ans = windowSum`.
// 3.  From index `k` to `n-1`:
//     -   Add `arr[i]`
//     -   Subtract `arr[i-k]`
//     -   Update `ans`.
// 4.  Return `ans`.

// ------------------------------------------------------------------------

// ## ⏱ Time & Space Complexity

//   Metric   Complexity
//   -------- ------------
//   Time     **O(n)**
//   Space    **O(1)**

// ------------------------------------------------------------------------

// ## 🧾 Code (C++)

class Solution {
public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        if (k > n) return 0;   // Edge case

        int windowSum = 0;

        // Sum of first k elements
        for (int i = 0; i < k; i++)
            windowSum += arr[i];

        int ans = windowSum;

        // Slide the window
        for (int i = k; i < n; i++) {
            windowSum += arr[i];        // add new element
            windowSum -= arr[i - k];    // remove old element
            ans = max(ans, windowSum);
        }

        return ans;
    }
// };

