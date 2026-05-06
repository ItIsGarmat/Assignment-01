class Solution {
public:
    int maxSum(string s) {
        
        int n = s.size();
        string t = s + s;

        vector<int> freq(26, 0);

        int left = 0;
        int currSum = 0;
        int maxSum = 0;

        for (int right = 0; right < 2 * n; right++) {

            int idx = t[right] - 'a';

            currSum += (idx + 1);
            freq[idx]++;

            while (freq[idx] > 1 || (right - left + 1) > n) {

                freq[t[left] - 'a']--;
                currSum -= (t[left] - 'a' + 1);

                left++;
            }

            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
