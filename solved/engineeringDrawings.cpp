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

bool checkDrawing(vi2d drawing){
    int n = drawing.size();
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            int requiredSum = drawing[i][j];
            if (requiredSum == 1) continue;
            // cout <<             "Searching for [" << i << "][" << j << "] = " << requiredSum << endl;
            bool found = false;
            for (int k = 0; k < n; k++){
                if (k == i) continue;
                int rowValue = drawing[k][j];
                // cout <<        "Trying        [" << k << "][" << j << "] = " << rowValue << endl;
                for (int v = 0; v < n; v++){
                    if (v == j) continue;
                    int colValue = drawing[i][v];
                    // cout <<     "With          [" << i << "][" << v << "] = " << colValue << endl;
                    if (rowValue + colValue == requiredSum){
                        // cout << "Found match   [" << i << "][" << j << "] = " << requiredSum << endl;
                        found = true;
                        break;
                    }
                }
            }
            if (!found){
                // cout <<         "No match for  [" << i << "][" << j << "] = " << requiredSum << endl;
                return false;
            }
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vi2d drawing(N,vi(N));
    
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; j++){
            cin >> drawing[i][j]; 
        }
    }

    checkDrawing(drawing) ? cout << "Yes" : cout << "No"; 

    return 0;
}