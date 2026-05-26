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

const vector<char> c[10] = {{},
                            {},
                            {'a', 'b', 'c'},
                            {'d', 'e', 'f'},
                            {'g', 'h', 'i'},
                            {'j', 'k', 'l'},
                            {'m', 'n', 'o'},
                            {'p', 'q', 'r', 's'},
                            {'t', 'u', 'v'},
                            {'w', 'x', 'y', 'z'}};

int n;
string s[15];

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= 9; j++) {
      for (int k = 0; k < c[j].size(); k++) {
        if (s[i][0] == c[j][k]) {
          cout << j;
        }
      }
    }
  }
  cout << '\n';

  return 0;
}
