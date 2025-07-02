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
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

int n, q, op, a, b, u, v;
ll x[3005], y[3005];

int group[3005];
ll dist[3005][3005];

priority_queue<pair<ll, Pii>, vector<pair<ll, Pii>>, greater<pair<ll, Pii>>>
    que;

int calc_group(int num) {
  if (group[num] == num) {
    return num;
  }

  int ans = calc_group(group[num]);
  return group[num] = ans;
}

void unite(int u, int v) {
  int gu = calc_group(u), gv = calc_group(v);

  group[max(gu, gv)] = min(gu, gv);
  group[u] = min(gu, gv);
  group[v] = min(gu, gv);

  return;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    group[i] = i;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);

      if (i < j) {
        que.push({dist[i][j], {i, j}});
      }
    }
  }

  while (q--) {
    cin >> op;

    if (op == 1) {
      n++;
      cin >> x[n] >> y[n];
      group[n] = n;

      for (int i = 1; i <= n - 1; i++) {
        dist[i][n] = abs(x[i] - x[n]) + abs(y[i] - y[n]);
        que.push({dist[i][n], {i, n}});
      }
    } else if (op == 2) {
      vector<Pii> now;
      ll now_dist = -1;
      while (!que.empty()) {
        pair<ll, Pii> q = que.top();
        que.pop();

        int i = q.second.first, j = q.second.second;
        if (calc_group(i) == calc_group(j)) {
          continue;
        }

        if (now.empty()) {
          now.push_back(q.second);
          now_dist = q.first;
        } else if (now_dist == q.first) {
          now.push_back(q.second);
        } else {
          que.push(q);
          break;
        }
      }

      cout << now_dist << endl;
      for (Pii p : now) {
        unite(p.first, p.second);
      }
    } else {
      cin >> u >> v;
      if (calc_group(u) == calc_group(v)) {
        Yes();
      } else {
        No();
      }
    }
  }

  return 0;
}
