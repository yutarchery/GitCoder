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

int n, x, v[5005], a[5005], c[5005], dp[5005][5005];

vector<Pii> cal[3];

void prepare(int idx) {
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (v[i] == idx && j + c[i] <= x) {
        dp[i][j + c[i]] = max(dp[i][j + c[i]], dp[i - 1][j] + a[i]);
      }
    }
  }

  cal[idx - 1].push_back({0, 0});
  int now = 0;
  for (int j = 1; j <= x; j++) {
    if (dp[n][j] > now) {
      cal[idx - 1].push_back({dp[n][j], j});
      now = dp[n][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= x; j++) {
      dp[i][j] = 0;
    }
  }

  return;
}

int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> v[i] >> a[i] >> c[i];
  }
  for (int i = 1; i <= 3; i++) {
    prepare(i);
  }

  int ok = 0, ng = int(1e9 + 5);
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;

    int sum = 0;
    for (int i = 0; i < 3; i++) {
      int l = 0, r = cal[i].size() - 1;

      if (cal[i][r].first < mid) {
        sum += x + 1;
        continue;
      }

      while (r - l > 1) {
        int now = (l + r) / 2;
        if (mid <= cal[i][now].first) {
          r = now;
        } else {
          l = now;
        }
      }
      sum += cal[i][r].second;
    }

    if (sum <= x) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  cout << ok << endl;

  return 0;
}
