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

ll n;
char s[int(2e5 + 5)];

int a[int(2e5 + 5)], b[int(2e5 + 5)], c[int(2e5 + 5)];

map<int, ll> ab, bc, ca;
map<Pii, ll> abc;

ll ans_ab, ans_bc, ans_ca, ans_abc;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i] == 'A') {
      a[i]++;
    } else if (s[i] == 'B') {
      b[i]++;
    } else {
      c[i]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
    b[i] += b[i - 1];
    c[i] += c[i - 1];
  }
  for (int i = 0; i <= n; i++) {
    ab[a[i] - b[i]]++;
    bc[b[i] - c[i]]++;
    ca[c[i] - a[i]]++;
    abc[{a[i] - b[i], b[i] - c[i]}]++;
  }

  for (int i = 1; i <= n; i++) {
    ans_ab += ab[a[i] - b[i]] - 1;
    ans_bc += bc[b[i] - c[i]] - 1;
    ans_ca += ca[c[i] - a[i]] - 1;
    ans_abc += abc[{a[i] - b[i], b[i] - c[i]}] - 1;

    ab[a[i] - b[i]]--;
    bc[b[i] - c[i]]--;
    ca[c[i] - a[i]]--;
    abc[{a[i] - b[i], b[i] - c[i]}]--;
  }

  ll ans = n * (n + 1) / 2 - (ans_ab + ans_bc + ans_ca) + 2 * ans_abc;
  cout << ans << '\n';

  return 0;
}
