#include <bits/stdc++.h>
using namespace std;
//BOJ 1753 최단거리(다익스트라 알고리즘, 힙을 이용한 풀이)
int V, E, S;
vector<pair<int, int> > graph[20001];
int INF = 2147483647;
int dis[20001];

void dij() {
	priority_queue<pair<int, int>> pq;
	fill(dis, dis + V + 1, INF);
	dis[S] = 0;
	pq.push({ 0,S });

	while (!pq.empty()) {
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();		
		
		for (int i = 0; i < graph[here].size(); i++) {
			int next = graph[here][i].first;
			int nextcost = graph[here][i].second;

			if (dis[next] > dis[here] + nextcost) {
				dis[next] = dis[here] + nextcost;
				pq.push({ -dis[next], next });
			}
			
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> V >> E;
	cin >> S;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v,w });
	}

	dij();
	for (int i = 1; i <= V; i++) {
		if (dis[i] == INF) {
			cout << "INF" << '\n';
		}
		else {
			cout << dis[i] << '\n';
		}
	}
	return 0;
}