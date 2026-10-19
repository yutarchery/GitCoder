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

char s[2][2];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      cin >> s[i][j];
    }
  }

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      if (s[i][j] == 'A') {
        if (s[1 - i][1 - j] == 'D') {
          No();
        } else {
          Yes();
        }

        return 0;
      }
    }
  }

  return 0;
}
