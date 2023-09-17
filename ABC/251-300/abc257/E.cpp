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

int n, c[15], m = 1e9, l;

int main() {
  cin >> n;
  for (int i = 1; i <= 9; i++) {
    cin >> c[i];
    m = min(m, c[i]);
  }
  l = n / m;

  int rest = n;
  for (int i = l - 1; i >= 0; i--) {
    for (int j = 9; j >= 1; j--) {
      if (rest - c[j] >= i * m) {
        rest -= c[j];
        cout << j;
        break;
      }
    }
  }
  cout << endl;

  return 0;
}