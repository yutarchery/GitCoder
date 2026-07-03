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
string s[int(2e4 + 5)];

map<string, bool> used;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];

    string t = "";
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '0') {
        t += '1';
      } else {
        t += '0';
      }
    }

    used[t] = true;
  }

  for (int i = 0; i <= n; i++) {
    string now = "";
    int rest = i;

    for (int j = 0; j < m; j++) {
      if (rest % 2 == 1) {
        now += '1';
      } else {
        now += '0';
      }

      rest /= 2;
    }

    if (!used[now]) {
      Yes();
      cout << now << '\n';
      return 0;
    }
  }

  No();

  return 0;
}
