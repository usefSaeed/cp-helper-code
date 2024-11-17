#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
typedef vector<vector<int>> adjList;

const vpi redPoints = {
    {1, 1},
    {2, 1},
    {2, 2},
    {4, 1},
    {4, 4},
    {5, 1},
    {5, 2},
    {5, 4},
    {5, 5}
};

int isPairRed(pi pt) {
    for (const auto& validPair : redPoints) {
        if (validPair == pt) {
            return 1;
        }
    }
    return 0; 
}

int pointColor(pi pt){
    pt.first -= int(pt.first / 6) * 6;
    pt.second -= int(pt.first / 6) * 6;
    cout << "NEW " << pt.first << " " << pt.second << "\n";
    return isPairRed(pt);
}

int main() {
    int T; 
    cin >> T;

    while (T--) {
        pi point;
        cin >> point.first >> point.second;
        cout << pointColor(point) << "\n";
    }
    return 0;
}