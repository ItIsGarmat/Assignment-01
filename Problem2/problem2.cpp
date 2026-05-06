#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    long long minimumOperations(vector<int>& A, int K) {

        int n = A.size();

        // Check if transformation is possible
        for (int i = 1; i < n; i++) {
            if ((A[i] - A[0]) % K != 0) {
                return -1;
            }
        }

        // Sort array to find median
        sort(A.begin(), A.end());

        int median = A[n / 2];

        long long operations = 0;

        // Count operations
        for (int x : A) {
            operations += abs(x - median) / K;
        }

        return operations;
    }
};

int main() {

    int N;
    cin >> N;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int K;
    cin >> K;

    Solution obj;

    cout << obj.minimumOperations(A, K) << endl;

    return 0;
}