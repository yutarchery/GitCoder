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

int n, m, l[105], x[105][105];

bool visited[105];
int ans[105];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> l[i];
    for (int j = 1; j <= l[i]; j++) {
      cin >> x[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= l[i]; j++) {
      if (!visited[x[i][j]]) {
        visited[x[i][j]] = true;
        ans[i] = x[i][j];
        break;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << ans[i] << '\n';
  }

  return 0;
}
