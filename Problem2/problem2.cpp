class Solution {
public:
    long long minimumOperations(vector<int>& A, int K) {

        int n = A.size();

        for (int i = 1; i < n; i++) {
            if ((A[i] - A[0]) % K != 0) {
                return -1;
            }
        }

        sort(A.begin(), A.end());

        int median = A[n / 2];

        long long operations = 0;

        for (int x : A) {
            operations += abs(x - median) / K;
        }

        return operations;
    }
};
