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

int n, m;
char s[int(1e6 + 5)], t[int(1e6 + 5)], last_t;
int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= m; i++) {
    cin >> t[i];
  }
  last_t = t[m];
  sort(t + 1, t + m + 1, greater<char>());

  int now = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = now; j <= n; j++) {
      now = j;
      if (s[j] < t[i]) {
        s[j] = t[i];
        break;
      }
    }
  }

  bool used_last = false;
  for (int i = 1; i <= n; i++) {
    if (s[i] == last_t) {
      used_last = true;
    }
  }
  if (!used_last) {
    s[n] = last_t;
  }

  for (int i = 1; i <= n; i++) {
    cout << s[i];
  }
  cout << '\n';

  return 0;
}
