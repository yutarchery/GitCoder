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

int h, w;
vector<int> a[int(1e5 + 5)];

int main() {
  cin >> h >> w;
  for (int i = 1; i <= h; i++) {
    a[i].resize(w + 1);
    for (int j = 1; j <= w; j++) {
      cin >> a[i][j];
    }
  }

  for (int j = 1; j <= w; j++) {
    for (int i = 1; i <= h; i++) {
      cout << a[i][j];
      if (i == h) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }

  return 0;
}
