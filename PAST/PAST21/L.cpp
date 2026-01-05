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

int n;
ll x[2005], y[2005], p[2005];

bool visited[2005];
priority_queue<pair<double, int>, vector<pair<double, int>>,
               greater<pair<double, int>>>
    que;
double ans = 0;

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    que.push({p[i], i});
  }

  while (!que.empty()) {
    pair<double, int> q = que.top();
    que.pop();
    if (visited[q.second]) {
      continue;
    }

    visited[q.second] = true;
    ans += q.first;

    for (int j = 1; j <= n; j++) {
      if (!visited[j]) {
        que.push({sqrt((x[q.second] - x[j]) * (x[q.second] - x[j]) +
                       (y[q.second] - y[j]) * (y[q.second] - y[j])),
                  j});
      }
    }
  }

  cout << fixed << setprecision(10) << ans << endl;

  return 0;
}
