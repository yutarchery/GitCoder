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

int main() {
  int m;
  cin >> m;
  if (m <= 5000) {
    printf("%02d\n", m / 100);
  } else if (m <= 30000) {
    printf("%02d\n", m / 1000 + 50);
  } else if (m <= 70000) {
    printf("%02d\n", (m / 1000 - 30) / 5 + 80);
  } else {
    cout << 89 << endl;
  }

  return 0;
}
