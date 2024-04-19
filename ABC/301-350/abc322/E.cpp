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

int n, k, p;
ll c[105];
int a[105][10];
ll dp[105][8000];

int calc_index(int from_idx, int i) {
  int now[k] = {};
  for (int j = 0; j < k; j++) {
    now[j] = from_idx % 6;
    from_idx /= 6;
  }
  int to_idx = 0, num = 1;
  for (int j = 0; j < k; j++) {
    now[j] = min(now[j] + a[i][j], p);
    to_idx += now[j] * num;
    num *= 6;
  }
  return to_idx;
}

int max_index() {
  int ans = 0, num = 1;
  for (int i = 0; i < k; i++) {
    ans += num * p;
    num *= 6;
  }
  return ans;
}

int main() {
  cin >> n >> k >> p;
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    for (int j = 0; j < k; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i <= n; i++) {
    for (int j = 0; j < 8000; j++) {
      dp[i][j] = 1e16;
    }
  }
  dp[0][0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 8000; j++) {
      if (dp[i][j] == 1e16) {
        continue;
      }

      dp[i + 1][j] = min(dp[i][j], dp[i + 1][j]);
      int next = calc_index(j, i + 1);
      dp[i + 1][next] = min(dp[i][j] + c[i + 1], dp[i + 1][next]);
    }
  }

  int ans_index = max_index();
  if (dp[n][ans_index] == 1e16) {
    cout << -1 << endl;
  } else {
    cout << dp[n][ans_index] << endl;
  }

  return 0;
}
