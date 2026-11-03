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

ll n, x[int(5e5 + 5)], y[int(5e5 + 5)];
map<Pii, bool> visited;

bool judge(ll a, ll b, ll c) {
  int cnt = 0;

  for (int i = 1; i <= n; i++) {
    if (a * x[i] + b * y[i] + c == 0) {
      cnt++;
    }
  }

  return (n + 1) / 2 <= cnt;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  ll cnt = 0;
  while (cnt <= min(100ll, n * (n - 1) / 2)) {
    int i = rand() % n + 1, j = rand() % n + 1;
    if (i == j) {
      continue;
    }
    if (i > j) {
      swap(i, j);
    }
    if (visited[{i, j}]) {
      continue;
    }

    ll a = y[i] - y[j], b = x[j] - x[i], c = x[i] * y[j] - x[j] * y[i];

    if (judge(a, b, c)) {
      Yes();
      cout << a << " " << b << " " << c << '\n';
      return 0;
    }

    cnt++;
  }
  No();

  return 0;
}
