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

int mgd(vi arr, int s, int v, vi2d &max2d, vpi2d &sol2d){
    int n = arr.size();
    if (v == 0 || s >= n){
        return 0;
    }
    if (max2d[s][v] != NOT_VISITED){
        return max2d[s][v];
    }
    int maxScore = NEG_INF;
    int zeroScore = mgd(arr, s + 1, v, max2d, sol2d);
    if (v >= arr[s]){
        maxScore = 1 + zeroScore;
        sol2d[s][v] = make_pair(1,v);
    }else{
        int oneScore = 1 + mgd(arr, s + 1, v - 1, max2d, sol2d);
        if (oneScore >= zeroScore){
            maxScore = oneScore;
            sol2d[s][v] = make_pair(1, v - 1);
        }else{
            maxScore = zeroScore;
            sol2d[s][v] = make_pair(0, v);
        }
    }
    max2d[s][v] = maxScore;
    return maxScore;
}

string extractSolution(vpi2d sol, int n, int v){
    int nextV = v;
    string s;
    for (int i = 1; i <= n; i++){
        s += (char) (sol[i][nextV].first + '0');
        nextV = sol[i][nextV].second;
    }
    return s;
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; 
    cin >> T;

    while (T--) {
        int N; cin >> N;
        int V; cin >> V;

        vi gymDays(N+1);
        
        for (int i = 1; i <= N; ++i) {
            cin >> gymDays[i]; 
        }

        vi2d maxOnes(N + 1, vi(V + 1, NOT_VISITED));    
        vpi2d solution(N + 1, vpi(V + 1, make_pair(0,0)));  

        mgd(gymDays, 1, V, maxOnes, solution);

        string result = extractSolution(solution, N, V);
        cout << result << '\n'; 
    }
    return 0;
}