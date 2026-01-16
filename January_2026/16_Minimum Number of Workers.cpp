class Solution {
public:
    int minPeople(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> intervals;

        // Step 1: Build intervals
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int L = max(0, i - arr[i]);
                int R = min(n - 1, i + arr[i]);
                intervals.push_back({L, R});
            }
        }

        // If no one can work
        if (intervals.empty()) return -1;

        // Step 2: Sort by starting point
        sort(intervals.begin(), intervals.end());

        int currEnd = 0;
        int i = 0;
        int count = 0;

        // Step 3: Greedy covering
        while (currEnd < n) {
            int farthest = currEnd;

            // Try all intervals that can start before or at currEnd
            while (i < intervals.size() && intervals[i].first <= currEnd) {
                farthest = max(farthest, intervals[i].second + 1);
                i++;
            }

            // If we couldn't extend coverage
            if (farthest == currEnd) return -1;

            count++;
            currEnd = farthest;
        }

        return count;
    }
};
