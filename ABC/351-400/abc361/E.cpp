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

int n, a[int(2e5 + 5)], b[int(2e5 + 5)];
ll c[int(2e5 + 5)];

ll ans = 0;
bool visited[int(2e5 + 5)];
ll dp[int(2e5 + 5)];
vector<Pil> graph[int(2e5 + 5)];
vector<ll> dist;

ll calc_dist(int now) {
  if (visited[now]) {
    return dp[now];
  }

  visited[now] = true;
  ll res = 0;
  vector<ll> now_dists;
  for (Pil next : graph[now]) {
    if (visited[next.first]) {
      continue;
    }

    res = max(res, calc_dist(next.first) + next.second);
    now_dists.push_back(dp[next.first] + next.second);
  }

  sort(now_dists.begin(), now_dists.end(), greater<ll>());
  if (now_dists.size() >= 1) {
    dist.push_back(now_dists[0]);
  }
  if (now_dists.size() >= 2) {
    dist.push_back(now_dists[0] + now_dists[1]);
  }

  return dp[now] = res;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n - 1; i++) {
    cin >> a[i] >> b[i] >> c[i];
    graph[a[i]].push_back({b[i], c[i]});
    graph[b[i]].push_back({a[i], c[i]});
    ans += c[i] * 2;
  }

  dist.push_back(0);
  calc_dist(1);
  sort(dist.begin(), dist.end(), greater<ll>());

  ans -= dist[0];
  cout << ans << endl;

  return 0;
}
