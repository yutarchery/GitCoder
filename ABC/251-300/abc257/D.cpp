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
ll x[205], y[205], p[205], dist[205][205];
bool visited[205];

bool is_able(int start, ll s) {
  fill(visited, visited + n + 1, false);

  queue<int> que;
  que.push(start);
  visited[start] = true;

  while (!que.empty()) {
    int q = que.front();
    que.pop();

    for (int j = 1; j <= n; j++) {
      if (visited[j]) {
        continue;
      }

      if (p[q] * s >= dist[q][j]) {
        visited[j] = true;
        que.push(j);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      return false;
    }
  }

  return true;
}

bool check(ll s) {
  for (int i = 1; i <= n; i++) {
    if (is_able(i, s)) {
      return true;
    }
  }
  return false;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i] >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
    }
  }

  ll l = 0, r = ll(1e10 + 5);
  while (r - l > 1) {
    ll mid = (l + r) / 2;
    if (check(mid)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  cout << r << endl;

  return 0;
}