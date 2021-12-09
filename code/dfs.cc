#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<bool> visited(5, false);

void dfs(std::vector<std::vector<int>>& graph, int top) {
    visited[top] = true;
    for (int next_node : graph[top]){
        cout << top << next_node << endl;

        if (!visited[next_node]) {
            dfs(graph, next_node);
        }
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
    dfs(mymap, 0);

    // for_each(result.begin(), result.end(), [](pair<int, int> x){cout << x.first << " " << x.second << endl;});

    return 0;

}