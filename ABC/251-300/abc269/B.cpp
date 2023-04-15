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
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

string s[10];
int a = 10, b = 1, c = 10, d = 1;
int main() {
  for (int i = 0; i < 10; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      if (s[i][j] == '#') {
        a = min(a, i + 1);
        b = max(b, i + 1);
        c = min(c, j + 1);
        d = max(d, j + 1);
      }
    }
  }

  cout << a << " " << b << endl;
  cout << c << " " << d << endl;

  return 0;
}