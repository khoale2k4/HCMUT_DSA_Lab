#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void DFS(int node, vector<vector<int>>& edges, unordered_set<int>& visited) {
    visited.insert(node);

    for (int neighbor : edges[node]) {
        if (visited.find(neighbor) == visited.end()) {
            DFS(neighbor, edges, visited);
        }
    }
}

int connectedComponents(vector<vector<int>>& edges) {
    int n = edges.size();
    unordered_set<int> visited;
    int components = 0;

    for (int i = 0; i < n; ++i) {
        if (visited.find(i) == visited.end()) {
            DFS(i, edges, visited);
            components++;
        }
    }

    return components;
}

int main(){

}