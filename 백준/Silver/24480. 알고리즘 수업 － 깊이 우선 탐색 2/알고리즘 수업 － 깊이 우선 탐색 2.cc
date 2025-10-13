#include <bits/stdc++.h>
using namespace std;

int N, M, R;
vector<vector<int>> adj;
vector<int> ord;
vector<char> vis;

void dfs_iter() {
    stack<int> st;
    st.push(R);
    int cnt = 1;

    while (!st.empty()) {
        int u = st.top(); st.pop();

        if (vis[u]) continue;          // pop 시 방문 처리만 허용
        vis[u] = 1;
        ord[u] = cnt++;

        // 인접정점은 "내림차순"이므로, push는 역순(=오름차순)으로
        for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
            int v = *it;
            if (!vis[v]) st.push(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> R;
    adj.assign(N + 1, {});
    ord.assign(N + 1, 0);
    vis.assign(N + 1, 0);

    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    // 24480 규칙: 인접 정점 내림차순
    for (int i = 1; i <= N; ++i)
        sort(adj[i].begin(), adj[i].end(), greater<int>());

    dfs_iter();

    for (int i = 1; i <= N; ++i) cout << ord[i] << '\n';
}
