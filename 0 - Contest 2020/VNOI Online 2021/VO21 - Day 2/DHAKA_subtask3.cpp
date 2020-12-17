struct State {
    int u, w; bool ok;
    State (int _u = 0, int _w = INF, bool _ok = 0) {
        u = _u; w = _w; ok = _ok;
    }
    bool operator< (const State& other) const { return w > other.w || (w == other.w && ok < other.ok); }
};

priority_queue <State> pq;
for (int i=1; i<=n; i++) {
    d[i] = INF;
    f[i] = INF;
}

d[1] = 0; pq.push(State(1, 0, 0));
if (s[1][0]) {
    f[1] = 0;
    pq.push(State(1, 0, 1));
}

while (pq.size()) {
    int u = pq.top().u, du = pq.top().w; 
    bool ok = pq.top().ok; pq.pop();

    if (!ok) {
        if (du != d[u]) continue;
        for (ii e: adj[u]) {
            int v = e.first, uv = e.second;
            if (s[v][0]) {
                if (minimize(f[v], du + uv)) pq.push(State(v, f[v], 1));
            } else {
                if (minimize(d[v], du + uv)) pq.push(State(v, d[v], 0));
            }
        }
    } else {
        if (du != f[u]) continue;
        for (ii e: adj[u]) {
            int v = e.first, uv = e.second;
            if (minimize(f[v], du + uv)) pq.push(State(v, f[v], ok));
        }
    }
}

if (f[n] == INF) f[n] = -1;
Write(f[n]);
exit(0);