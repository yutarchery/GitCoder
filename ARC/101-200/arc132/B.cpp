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

int n, p[int(1e5 + 5)];

int ans[int(1e5 + 5)][2];
bool visited[int(1e5 + 5)][2];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }

  ans[1][0] = 0;
  visited[1][0] = true;

  queue<Pii> que;
  que.push({1, 0});

  while (!que.empty()) {
    Pii q = que.front();
    que.pop();

    int l = q.first + 1;
    if (l > n) {
      l = 1;
    }
    if (!visited[l][q.second]) {
      visited[l][q.second] = true;
      ans[l][q.second] = ans[q.first][q.second] + 1;
      que.push({l, q.second});
    }

    int r = (n + 1) - q.first;
    if (!visited[r][1 - q.second]) {
      visited[r][1 - q.second] = true;
      ans[r][1 - q.second] = ans[q.first][q.second] + 1;
      que.push({r, 1 - q.second});
    }
  }

  for (int i = 1; i <= n; i++) {
    if (p[i] == 1) {
      if (p[i - 1] == n || p[i + 1] == 2) {
        cout << ans[i][0] << '\n';
      } else {
        cout << ans[i][1] << '\n';
      }
    }
  }

  return 0;
}
