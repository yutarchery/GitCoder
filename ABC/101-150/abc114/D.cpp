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
int cnt[105], ans = 0;

void prepare(int num) {
  for (int i = 2; i <= n; i++) {
    while (num % i == 0) {
      cnt[i]++;
      num /= i;
    }
  }
  return;
}

void solve(int now = 2, int rest = 75) {
  if (rest == 1) {
    ans++;
    return;
  }
  if (now > n) {
    return;
  }

  for (int i = 1; i <= min(cnt[now], rest - 1); i++) {
    if (rest % (i + 1) == 0) {
      solve(now + 1, rest / (i + 1));
    }
  }

  solve(now + 1, rest);
  return;
}

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    prepare(i);
  }
  solve();
  cout << ans << endl;

  return 0;
}
