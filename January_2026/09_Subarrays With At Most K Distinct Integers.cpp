class Solution {
  public:
    int countSubarrays(vector<int>& arr, int k) {
        unordered_map<int, int> freq;
        int left = 0;
        int distinct = 0;
        int count = 0;

        for (int right = 0; right < arr.size(); right++) {
            // include current element
            if (freq[arr[right]] == 0) {
                distinct++;
            }
            freq[arr[right]]++;

            // shrink window if distinct > k
            while (distinct > k) {
                freq[arr[left]]--;
                if (freq[arr[left]] == 0) {
                    distinct--;
                }
                left++;
            }

            // count valid subarrays ending at right
            count += (right - left + 1);
        }

        return count;
    }
};
