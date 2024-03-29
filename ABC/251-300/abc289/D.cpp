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

int n, m, a[15], b, x;
bool walkable[int(1e5 + 5)], unavailable[int(1e5 + 5)];

int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> b;
    unavailable[b] = true;
  }
  cin >> x;

  walkable[0] = true;
  for (int i = 0; i <= x; i++) {
    if (!walkable[i]) {
      continue;
    }

    for (int j = 1; j <= n; j++) {
      if (i + a[j] <= x && !unavailable[i + a[j]]) {
        walkable[i + a[j]] = true;
      }
    }
  }

  if (walkable[x]) {
    Yes();
  } else {
    No();
  }

  return 0;
}