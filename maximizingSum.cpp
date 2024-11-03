#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<long long, long long> pll;
typedef vector<pair<int,int>> vpi;
typedef vector<vector<int>> adjList;

const int INF = 10001;

int main() {
    int n; cin >> n;
    int bestSum = 0;
    int finalSub = INF;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        if (x > 0){
            bestSum += x;
        }
        if (x % 2 && abs(x) < finalSub){
            finalSub = abs(x);
        }
    }
    bestSum = bestSum % 2 ? bestSum : bestSum - finalSub;
    cout << bestSum;
    return 0;
}