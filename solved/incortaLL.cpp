#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

class LinkedListNode{
public:
    LinkedListNode *next;
    int v;

    LinkedListNode() {
        next = NULL;
        v = 0;
    }
    LinkedListNode(int _v) {
        next = NULL;
        v = _v;
    }
};

LinkedListNode* _insert_node_into_singlylinkedlist(LinkedListNode *head, int v){
    LinkedListNode* node;
    if(head == NULL) {
        node = new LinkedListNode(v);
    }
    else {
        LinkedListNode* n;
        n = head;
        while (n->next != NULL) {
            n = n->next;
        }
        node = new LinkedListNode(v);
        n->next = node;
    }
    return node;
}

/*
 * Complete the function below.
 */
/*
For your reference:
LinkedListNode {
    LinkedListNode *next;
};
*/

typedef vector<vector<int>> vi2d;
typedef vector<int> vi;
const int MAX_SIZE = 10001;

bool contains(vi& v, int value) {
    return find(v.begin(), v.end(), value) != v.end();
}

LinkedListNode* filter(LinkedListNode* L) {
    LinkedListNode* currentNode = L;
    vi2d path(MAX_SIZE);
    int lastValue = currentNode->v;
    int maxLoopValidity = 0;
    int loopValidity = 0;
    int nodesCount = 0;
    while (true) {
        currentNode = currentNode->next;
        int currentValue = currentNode->v;
        if (path[currentValue].empty()){
            path[lastValue].push_back(currentValue);
            nodesCount++;
            loopValidity = 0;
        }else if (contains(path[lastValue],currentValue){
            loopValidity++;
        }
    }
    return nullptr;
}

int main(){
    ofstream fout(getenv("OUTPUT_PATH"));
    int n;
    cin >> n;
    LinkedListNode* nodes[n];

    LinkedListNode* head=NULL;
    LinkedListNode* prev=NULL;
    for(int i=0; i<n; i++){
        int v;
        cin >> v;
        nodes[i] = _insert_node_into_singlylinkedlist(prev, v);
        if(head == NULL) head = nodes[i];
        prev = nodes[i];
    }

    int loopIndex;
    cin >> loopIndex;
    nodes[n-1]->next = nodes[loopIndex];

    LinkedListNode* loopStart = filter(head);
    fout << loopStart->v << endl;

    fout.close();
    return 0;
}
43131966 Argentina
1359800 Bahrain
10315244 Benin
3791622 Bosnia and Herzegovina
18450494 Burkina Faso
1371590000 China
43131966 Argentina
1359800 Bahrain
10315244 Benin
3791622 Bosnia and Herzegovina
18450494 Burkina Faso
1371590000 China
43131966 Argentina
1359800 Bahrain
10315244 Benin
3791622 Bosnia and Herzegovina
18450494 Burkina Faso
1371590000 China
43131966 Argentina
1359800 Bahrain
10315244 Benin
3791622 Bosnia and Herzegovina