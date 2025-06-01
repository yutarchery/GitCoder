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

int n, l, a[int(2e5 + 5)];
bool seated[int(4e5 + 5)];

int main() {
  cin >> n >> l;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  int r = 2;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      if (!seated[r] && r <= l) {
        seated[r] = true;
        r += 2;
        continue;
      }
    } else {
      if (!seated[r] && !seated[r + 1] && r + 1 <= l) {
        seated[r] = true;
        seated[r + 1] = true;
        r += 3;
        continue;
      }
    }

    if (a[i] == 2) {
      if (!seated[l] && !seated[l - 1]) {
        seated[l] = true;
        seated[l - 1] = true;
        continue;
      } else {
        No();
        return 0;
      }
    }
  }

  Yes();

  return 0;
}
