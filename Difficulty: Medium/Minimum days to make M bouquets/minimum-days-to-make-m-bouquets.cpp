class Solution {
public:
    bool possible(vector<int>& arr, int mid, int m, int k) {
        int count = 0;
        int fools = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= mid) {
                count++;
            } else {
                fools += (count / k);
                count = 0;
            }
        }
        fools += (count / k);
        return fools >= m;
    }

   int minDaysBloom(vector<int>& bloomDay, int k, int m) {
        long long val = 1LL * m * 1LL * k;
        if (val > bloomDay.size())
            return -1;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int i = 0; i < bloomDay.size(); i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }
        int low = mini;
        int high = maxi;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (possible(bloomDay, mid, m, k)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};