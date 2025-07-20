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

int n, p[int(2e5 + 5)];
int now[int(2e5 + 5)], mins[int(2e5 + 5)], maxs[int(2e5 + 5)], order[4];

int tmp_solve() {
  int ans = 0;
  for (int i = 0; i < 4; i++) {
    bool flag = true;
    for (int j = 1; j <= n; j++) {
      if (now[j] != j) {
        flag = false;
      }
    }
    if (flag) {
      return ans;
    }

    ans++;
    if (order[i] == 0) {
      sort(now + 2, now + n + 1);
    } else {
      sort(now + 1, now + n);
    }
  }

  return 1e9;
}

int solve() {
  cin >> n;
  mins[0] = 1e9;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
    mins[i] = min(mins[i - 1], p[i]);
    maxs[i] = max(maxs[i - 1], p[i]);
  }

  int ans = 1e9;
  do {
    for (int i = 1; i <= n; i++) {
      now[i] = p[i];
    }

    ans = min(ans, tmp_solve());
  } while (next_permutation(order, order + 4));

  for (int i = 1; i <= n; i++) {
    if (mins[i] == 1 && maxs[i] == i && p[i] == i) {
      ans = min(ans, 1);
    }
  }

  return ans;
}

int main() {
  int t;
  cin >> t;

  for (int i = 0; i < 4; i++) {
    order[i] = i / 2;
  }

  while (t--) {
    cout << solve() << endl;
  }

  return 0;
}
