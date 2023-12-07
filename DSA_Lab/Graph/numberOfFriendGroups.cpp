#include <iostream>
#include <vector>

using namespace std;

void dfs(int u, vector<vector<int>>& friends, vector<bool>& visited) {
    visited[u] = true;
    for (int v : friends[u]) {
        if (!visited[v]) {
            dfs(v, friends, visited);
        }
    }
}

int numberOfFriendGroups(vector<vector<int>>& friends) {
    // STUDENT ANSWER
    int n = friends.size();
    vector<bool> visited(n, false);
    int groups = 0;
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i, friends, visited);
            ++groups;
        }
    }
    return groups;
}

int main(){
    
}