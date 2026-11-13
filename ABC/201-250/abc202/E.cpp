#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector<vector<ll>> Mat;
#define fi first
#define se second
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, p[int(2e5 + 5)];
int q, u, d;

vector<int> graph[int(2e5 + 5)];
int dist[int(2e5 + 5)], ins[int(2e5 + 5)], outs[int(2e5 + 5)];
vector<Pii> ups[int(2e5 + 5)];

int now = 1;

void prepare(int node = 1) {
  ins[node] = now;
  now++;
  for (int nxt : graph[node]) {
    dist[nxt] = dist[node] + 1;
    prepare(nxt);
  }

  outs[node] = now;
  now++;

  ups[dist[node]].push_back({ins[node], node});
  return;
}

int solve(int d, int val) {
  if (ups[d].size() == 0) {
    return 0;
  }

  if (val < ups[d][0].first) {
    return 0;
  }

  int ok = 0, ng = ups[d].size();
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;

    if (ups[d][mid].first <= val) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return ok + 1;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> p[i];
    graph[p[i]].emplace_back(i);
  }
  prepare();

  for (int i = 0; i <= n; i++) {
    sort(ups[i].begin(), ups[i].end());
  }

  cin >> q;
  while (q--) {
    cin >> u >> d;
    cout << solve(d, outs[u]) - solve(d, ins[u] - 1) << '\n';
  }

  return 0;
}
