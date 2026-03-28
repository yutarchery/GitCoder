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

string s;

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> s;

  int a = 0, b = 0, c = 0;
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == 'C') {
      c++;
    } else if (s[i] == 'B') {
      if (b + 1 <= c) {
        b++;
      }
    } else {
      if (b >= 1 && c >= 1) {
        a++;
        b--;
        c--;
      }
    }
  }
  cout << a << endl;

  return 0;
}
