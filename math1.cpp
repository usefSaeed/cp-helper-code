#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
typedef vector<vector<int>> adjList;

vpi countingSort(vpi v, int maxNum){
    int N = v.size();
    int K = maxNum;
    vi C(K);
    for (int i = 1; i < N; i++){
        int value = v[i].second;
        C[value]++;
    }

    // printVec(C,"C Version 1");

    for (int i = 1; i < K; i++){
        C[i] += C[i-1];
    }

    // printVec(C,"C Version 2");

    vpi stableSortedV(N);
    for (int i = N - 1; i >= 1; i--){
        int value = v[i].second;
        int stableIndex = C[value];
        C[value]--;
        stableSortedV[stableIndex] = v[i];
    }
    return stableSortedV;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; 
    cin >> N;
    vpi a(N + 1);
    
    for (int i = 1; i <= N; ++i) {
        a[i].first = i;
        cin >> a[i].second; 
    }

    vpi out = countingSort(a, N + 1);

    for (int i = 1; i < N; ++i) {
        cout << out[i].first << " "; 
    }
    cout << out[N].first; 

    return 0;
}