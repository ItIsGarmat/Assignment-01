#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSum(string s) {

        int n = s.size();
        string t = s + s;

        vector<int> freq(26, 0);

        int left = 0;
        int currSum = 0;
        int ans = 0;

        for (int right = 0; right < 2 * n; right++) {

            int idx = t[right] - 'a';

            currSum += (idx + 1);
            freq[idx]++;

            while (freq[idx] > 1 || (right - left + 1) > n) {

                freq[t[left] - 'a']--;
                currSum -= (t[left] - 'a' + 1);

                left++;
            }

            ans = max(ans, currSum);
        }

        return ans;
    }
};

int main() {

    string s;
    cin >> s;

    Solution obj;

    cout << obj.maxSum(s) << endl;

    return 0;
}