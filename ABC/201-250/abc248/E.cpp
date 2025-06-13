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

int n, k;
ll x[305], y[305];

bool visited[305][305];

int ans = 0;

void solve(int i, int j) {
  if (visited[i][j]) {
    return;
  }

  vector<int> now;
  for (int l = 1; l <= n; l++) {
    ll sum1 = (x[j] - x[i]) * (y[l] - y[i]);
    ll sum2 = (y[j] - y[i]) * (x[l] - x[i]);

    if (sum1 == sum2) {
      now.push_back(l);
    }
  }

  if (now.size() >= k) {
    ans++;
  }

  for (int i1 : now) {
    for (int j1 : now) {
      visited[i1][j1] = true;
    }
  }

  return;
}

int main() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  if (k == 1) {
    cout << "Infinity" << endl;
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      solve(i, j);
    }
  }
  cout << ans << endl;

  return 0;
}
