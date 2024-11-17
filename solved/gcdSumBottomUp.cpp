#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vector<int>> vi2d;
typedef vector<vector<pi>> vpi2d;

const int NOT_VISITED = -1;
const int NEG_INF = -1;

int getGCD(int a, int b){
    int mini = min(a,b);
    int maxi = max(a,b);
    while (mini) {
        int temp = mini;
        mini = maxi % mini;
        maxi = temp;
    }
    return maxi;
}

int gcdSumCount(vi arr, int l, int r, vpi &gcdSum){
    int iterations = r - l;
    int arraysCount = 0;
    for (int k = 1; k <= iterations; k++){
        // cout << "K: " << k << endl;
        int cur_l = l; int cur_r;
        while(true){
            cur_r = cur_l + k;
            if (cur_r > r){
                break;
            }
            gcdSum[cur_l].first = getGCD(arr[cur_r], gcdSum[cur_l].first);
            gcdSum[cur_l].second = arr[cur_r] + gcdSum[cur_l].second;
            if (gcdSum[cur_l].first <= gcdSum[cur_l].second){
                arraysCount++;
            }
            cur_l++;
        }
    }
    return arraysCount;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vi nums(N+1);
    
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i]; 
    }

    vpi gcdSum(N + 1,make_pair(1,0));  

    cout << gcdSumCount(nums, 1, N, gcdSum); 

    return 0;
}