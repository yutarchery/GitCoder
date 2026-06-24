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

int n, k, l[int(2e5 + 5)], r[int(2e5 + 5)];
Pii rl[int(2e5 + 5)];

int solve(int val) {
  int ans = 1;
  int now_r = rl[1].first;

  for (int i = 2; i <= n; i++) {
    if (now_r + val <= rl[i].second) {
      ans++;
      now_r = rl[i].first;
    }
  }

  return ans;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
    rl[i] = {r[i], l[i]};
  }
  sort(rl + 1, rl + n + 1);

  int ok = 0, ng = int(1e9 + 5);
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;
    if (solve(mid) >= k) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  cout << (ok > 0 ? ok : -1) << '\n';

  return 0;
}
