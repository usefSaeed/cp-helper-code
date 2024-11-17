#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pair<int,int>> vpi;
typedef vector<vector<int>> adjList;


int bfs(int start, adjList &adj, vi &ratings) {
    cout << "BFS: " << start << endl;
    int N = adj.size();
    vi citiesCount(N, -1);
    queue<pi> q; 
    q.push({start, ratings[start]});
    citiesCount[start] = 1;

    int maxCitiesCount = 1;

    while (!q.empty()) {
        int node = q.front().first;
        int maxRatingEncountered = q.front().second;
        cout << "Popped: city: " << node << " maxRating: " << maxRatingEncountered << endl;
        q.pop();
        
        for (int neighbor : adj[node]) {
            if (citiesCount[neighbor] == -1) {
                if (ratings[neighbor] > maxRatingEncountered) {
                    cout << "HIGHER:Pushed: city: " << neighbor << " maxRating: " << ratings[neighbor] << endl;
                    citiesCount[neighbor] = citiesCount[node] + 1;
                    q.push({neighbor, ratings[neighbor]}); 
                } else {
                    cout << "LOWER:Pushed: city: " << neighbor << " maxRating: " << maxRatingEncountered << endl;
                    citiesCount[neighbor] = citiesCount[node];
                    q.push({neighbor, maxRatingEncountered}); 
                }
                if (citiesCount[neighbor] > maxCitiesCount) {
                    cout << "IN: max cities count: " << citiesCount[neighbor] << endl;
                    maxCitiesCount = citiesCount[neighbor];
                }
            }
        }
    }
    return maxCitiesCount;
}

int getMaxFood(adjList &adj, vi &ratings) {
    int maxCitiesCount = -1;
    for (int i=1; i<ratings.size();i++){
        maxCitiesCount = max(bfs(i, adj, ratings),maxCitiesCount); 
    }
    return maxCitiesCount;
}

int main() {
    int N;
    cin >> N;
    
    vi ratings(N+1);
    for (int i = 1; i <= N; i++) {
        cin >> ratings[i];
    }

    adjList adj(N+1);

    for (int i = 1; i <= N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    cout << getMaxFood(adj, ratings) << endl;

    return 0;
}