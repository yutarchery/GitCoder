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

int n;
char s[int(2e5 + 5)];
set<int> st_a, st_b;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 0; i <= n; i++) {
    cin >> s[i];

    if (s[i] == 'A') {
      st_a.insert(i);
    } else {
      st_b.insert(i);
    }
  }

  for (int i = 1; i <= n; i++) {
    if (st_a.empty()) {
      cout << "Bob" << '\n';
      continue;
    }
    if (st_b.empty()) {
      cout << "Alice" << '\n';
      continue;
    }

    if (i % 2 == 1) {
      auto iter = st_b.begin();
      st_b.erase(iter);
    } else {
      auto iter = st_a.begin();
      st_a.erase(iter);
    }

    if (st_a.empty()) {
      cout << "Bob" << '\n';
      continue;
    }
    if (st_b.empty()) {
      cout << "Alice" << '\n';
      continue;
    }

    auto a = st_a.begin(), b = st_b.begin();
    cout << ((*a) <= (*b) ? "Alice" : "Bob") << '\n';
  }

  return 0;
}
