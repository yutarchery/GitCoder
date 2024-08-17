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
ll a[85];

map<ll, bool> visited;
map<ll, int> idx;
vector<int> diff;

vector<int> graph[85][6405];
ll dp[85][6405][85];
ll ans[85];

ll fac[85], nCr[85][85];

ll my_pow(ll a, ll n) {
  if (n == 0) {
    return 1;
  }
  if (n % 2 == 0) {
    return my_pow(a * a % MOD2, n / 2);
  } else {
    return a * my_pow(a, n - 1) % MOD2;
  }
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (ll i = 1; i <= n; i++) {
    nCr[i][0] = 1;
    for (ll j = 1; j <= i; j++) {
      nCr[i][j] = nCr[i][j - 1] * (i - j + 1) % MOD2;
      nCr[i][j] *= my_pow(j, MOD2 - 2);
      nCr[i][j] %= MOD2;
    }
  }

  visited[0] = true;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (!visited[a[j] - a[i]]) {
        visited[a[j] - a[i]] = true;
        diff.push_back(a[j] - a[i]);
      }
    }
  }
  sort(diff.begin(), diff.end());

  for (int i = 0; i < diff.size(); i++) {
    idx[diff[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (a[i] != a[j]) {
        graph[i][idx[a[j] - a[i]]].push_back(j);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < diff.size(); j++) {
      dp[i][j][1] = 1;
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < diff.size(); j++) {
        if (dp[i][j][k] == 0) {
          continue;
        }

        for (int l : graph[i][j]) {
          dp[l][j][k + 1] += dp[i][j][k];
          dp[l][j][k + 1] %= MOD2;
        }
      }
    }
  }

  for (int k = 2; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < diff.size(); j++) {
        ans[k] += dp[i][j][k];
        ans[k] %= MOD2;
      }
    }
  }

  sort(a + 1, a + n + 1);
  int now = 1;
  for (int i = 2; i <= n + 1; i++) {
    if (a[i] == a[i - 1]) {
      now++;
      continue;
    } else {
      for (int j = 1; j <= now; j++) {
        ans[j] += nCr[now][j];
        ans[j] %= MOD2;
      }
      now = 1;
    }
  }

  cout << ans[1];
  for (int k = 2; k <= n; k++) {
    cout << " " << ans[k];
  }
  cout << endl;

  return 0;
}
