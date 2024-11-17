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

int gcdSumCount(vi arr, int l, int r, vpi2d &gcdSum){
    // cout << "l: " << l << " r: " << r << " Start"<< endl; 
    if ( l >= r){
        // cout << "OutOfBound " << 0 << endl;
        return 0;
    }
    if (gcdSum[l][r].first != NOT_VISITED){
        // cout << "Visited " << 0 << endl;
        return 0;
    }
    int score = gcdSumCount(arr,l,r-1,gcdSum);
    // cout << "l: " << l << " r: " << r << " LeftScore: " << score; 
    int gcd = getGCD(arr[r],gcdSum[l][r-1].first);
    int sum = gcdSum[l][r-1].second + arr[r];
    // cout << " gcd: " << gcd << " sum: " << sum; 
    if (gcd <= sum){
        score += 1;
        // cout << " scored! " << score << endl;;
    }
    score += gcdSumCount(arr,l+1,r,gcdSum);
    // cout << "l: " << l << " r: " << r << " Final Score: " << score << endl; 
    gcdSum[l][r] = make_pair(gcd, sum);
    return score;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vi nums(N+1);
    
    for (int i = 1; i <= N; ++i) {
        cin >> nums[i]; 
    }

    vpi2d gcdSum(N + 1, vpi(N + 1, make_pair(NOT_VISITED,NOT_VISITED)));  

    cout << gcdSumCount(nums, 1, N, gcdSum); 

    return 0;
}