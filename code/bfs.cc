#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

vector<bool> visited(5, false);
queue<int> q; 

void bfs(std::vector<std::vector<int>>& graph) {
    while(!q.empty()) {
        // cout << top << " " << q.front() << endl;
        visited[q.front()] = true;
        for (auto next: graph[q.front()]) {
            cout << q.front() << " " << next << endl;
            if (!visited[next]) q.push(next);
        }
        q.pop();
    }
}

// 1-2-3-4-5
// 1-4
int main() {

    vector<vector<int>> dislikes = {{1,2}, {2,3}, {3,4}, {4,5}, {1,4}};

    // 建表
    std::vector<std::vector<int>> mymap(5);

    for (auto i : dislikes) {
        mymap[i[0]-1].push_back(i[1]-1);
        // mymap[i[1]-1].push_back(i[0]-1);
    }
    q.push(0);
    bfs(mymap);

    // for_each(result.begin(), result.end(), [](pair<int, int> x){cout << x.first << " " << x.second << endl;});

    return 0;

}