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

int a[3][6], cnt = 0;

void solve(array<int, 3> v) {
  int res = 1;

  for (int i = 0; i < 3; i++) {
    int now = 0;
    for (int j = 0; j < 6; j++) {
      if (v[i] == a[i][j]) {
        now++;
      }
    }
    res *= now;
  }

  cnt += res;
  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 6; j++) {
      cin >> a[i][j];
    }
  }

  array<int, 3> v = {4, 5, 6};
  do {
    solve(v);
  } while (next_permutation(v.begin(), v.end()));

  cout << fixed << setprecision(10) << double(cnt) / double(6 * 6 * 6) << '\n';

  return 0;
}
