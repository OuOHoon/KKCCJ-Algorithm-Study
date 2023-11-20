#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 55

using namespace std;
const int INF = 1e9;
vector <pair<int, int>> edge[MAX];

vector<int> dijkstra(int n) {
    vector<int> dist(n + 1, INF);
    dist[1] = 0;

    priority_queue<pair <int, int>> pq;
    pq.push({ 0, 1 });

    while (!pq.empty()) {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < cost) continue;
        for (int i = 0; i < edge[here].size(); i++) {
            int next = edge[here][i].first;
            int nextcost = edge[here][i].second;

            if (dist[next] > dist[here] + nextcost) {
                dist[next] = dist[here] + nextcost;
                pq.push({ -dist[next], next });
            }
        }
    }

    return dist;
}


int solution(int n, vector<vector<int>> road, int k) {
    int answer = 0;

    for (int i = 0; i < road.size(); i++) {
        edge[road[i][0]].push_back({ road[i][1], road[i][2] });
        edge[road[i][1]].push_back({ road[i][0], road[i][2] });
    }

    vector<int> dist = dijkstra(n);

    for (int i = 1; i <= n; i++) {
        if (dist[i] <= k) answer++;
    }

    return answer;
}
