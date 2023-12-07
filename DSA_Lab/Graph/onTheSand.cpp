#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> onTheSand(vector<vector<int>>& matrix) {
    // STUDENT ANSWER
    int m = matrix.size(), n = matrix[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    queue<pair<int, int>> q;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            if(matrix[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }
    vector<vector<int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    while(!q.empty()) {
        pair<int, int> p = q.front(); q.pop();
        int x = p.first, y = p.second;
        for(auto& dir : dirs) {
            int nx = x + dir[0], ny = y + dir[1];
            if(nx >= 0 && nx < m && ny >= 0 && ny < n && dist[nx][ny] > dist[x][y] + 1) {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
    return dist;
}