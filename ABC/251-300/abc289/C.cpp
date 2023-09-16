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

int n, m, c[15], a[15][15], ans;

bool check(int num) {
  bool visited[15] = {};
  for (int i = 0; i < m; i++) {
    if (num % 2 != 0) {
      for (int j = 0; j < c[i]; j++) {
        visited[a[i][j]] = true;
      }
    }
    num /= 2;
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      return false;
    }
  }

  return true;
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> c[i];
    for (int j = 0; j < c[i]; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i < (1 << m); i++) {
    if (check(i)) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}