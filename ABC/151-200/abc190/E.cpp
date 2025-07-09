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

int n, m, a[int(1e5 + 5)], b[int(1e5 + 5)], k, c[20];
vector<int> graph[int(1e5 + 5)];

ll dist[20][20], dp[int(1 << 17)][20];
int now_dist[int(1e5 + 5)];

void calc_dist(int start, int idx) {
  fill(now_dist + 1, now_dist + n + 1, -1);
  queue<int> que;
  que.push(start);
  now_dist[start] = 0;

  while (!que.empty()) {
    int q = que.front();
    que.pop();
    for (int next : graph[q]) {
      if (now_dist[next] < 0) {
        now_dist[next] = now_dist[q] + 1;
        que.push(next);
      }
    }
  }

  for (int j = 0; j < k; j++) {
    dist[idx][j] = now_dist[c[j]];
  }
  return;
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i] >> b[i];
    graph[a[i]].push_back(b[i]);
    graph[b[i]].push_back(a[i]);
  }
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> c[i];
  }

  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j < k; j++) {
      dp[i][j] = 1e16;
    }
  }

  for (int i = 0; i < k; i++) {
    calc_dist(c[i], i);
    dp[(1 << i)][i] = 1;
  }

  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      if (dist[i][j] < 0) {
        cout << -1 << endl;
        return 0;
      }
    }
  }

  for (int i = 0; i < (1 << k); i++) {
    for (int j = 0; j < k; j++) {
      if ((i & (1 << j)) == 0) {
        continue;
      }

      for (int l = 0; l < k; l++) {
        int next = i | (1 << l);
        if (next == i) {
          continue;
        }
        dp[next][l] = min(dp[next][l], dp[i][j] + dist[j][l]);
      }
    }
  }

  ll ans = 1e16;
  for (int j = 0; j < k; j++) {
    ans = min(ans, dp[(1 << k) - 1][j]);
  }
  cout << ans << endl;

  return 0;
}
