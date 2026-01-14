/*
Approach / Intuition:
--------------------
We use the Two Pointer technique.

Idea:
- One pointer (i) will search for the next Police 'P'.
- Another pointer (j) will search for the next Thief 'T'.
- When both are found:
    • If the distance between them |i - j| <= k → Police can catch the Thief.
      So we increase count and move both pointers forward.
    • Else:
        - If Police is behind the Thief (i < j), move Police forward.
        - Otherwise, move Thief forward.

This greedy approach works because:
- Each Police and Thief can be used only once.
- We always try to match the closest possible pair first.
- This guarantees maximum number of catches.

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size();
        int i = 0, j = 0;   // i → Police pointer, j → Thief pointer
        int count = 0;

        while (i < n && j < n) {

            // Move i until we find a Police
            while (i < n && arr[i] != 'P') i++;

            // Move j until we find a Thief
            while (j < n && arr[j] != 'T') j++;

            if (i < n && j < n) {
                // Case 1: Police can catch the Thief
                if (abs(i - j) <= k) {
                    /*
                    Dry Run Example:
                    arr = ['P','T','T','P','T'], k = 1

                    i = 0 (P), j = 1 (T)
                    |0 - 1| = 1 <= k  → catch
                    count = 1
                    move both → i = 1, j = 2
                    */

                    count++;
                    i++;
                    j++;
                }
                // Case 2: Police is too far left, move Police forward
                else if (i < j) {
                    /*
                    Example:
                    P at index 0, T at index 3, k = 1
                    |0 - 3| = 3 > k
                    Police is too far → move i
                    */
                    i++;
                }
                // Case 3: Thief is too far left, move Thief forward
                else {
                    /*
                    Example:
                    T at index 1, P at index 4, k = 1
                    |4 - 1| = 3 > k
                    Thief is too far → move j
                    */
                    j++;
                }
            }
        }

        return count;
    }
};
