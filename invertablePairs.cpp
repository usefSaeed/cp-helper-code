#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
typedef vector<vector<int>> adjList;


long long kadane(const vector<long long>& arr) {
    long long max_sum = LLONG_MIN;
    long long current_sum = 0;
    
    for (long long num : arr) {
        current_sum += num;
        max_sum = max(max_sum, current_sum);
        if (current_sum < 0) {
            current_sum = 0;
        }
    }
    
    return max_sum;
}

long long maxSubarraySumAfterOperations(int n, vector<long long>& arr) {
    int total_configs = 1 << (n / 2);
    long long max_subarray_sum = LLONG_MIN;

    for (int config = 0; config < total_configs; ++config) {
        vector<long long> modified_arr = arr; 
        
        for (int k = 0; k < n / 2; ++k) {
            if (config & (1 << k)) {
                modified_arr[2 * k] *= -1; 
                modified_arr[2 * k + 1] *= -1; 
            }
        }

        long long max_sum = kadane(modified_arr);
        max_subarray_sum = max(max_subarray_sum, max_sum);
    }
    
    return max_subarray_sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;

    while (T--) {
        int N; 
        cin >> N;
        vector<long long> arr(N);
        
        for (int i = 0; i < N; ++i) {
            cin >> arr[i]; 
        }

        long long result = maxSubarraySumAfterOperations(N, arr);
        cout << result << '\n'; 
    }
    return 0;
}