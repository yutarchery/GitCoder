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
  int a[5];
  for (int i = 0; i < 5; i++) {
    cin >> a[i];
  }

  for (int i = 0; i + 1 < 5; i++) {
    swap(a[i], a[i + 1]);

    bool flag = true;
    for (int j = 0; j + 1 < 5; j++) {
      if (a[j] > a[j + 1]) {
        flag = false;
      }
    }

    swap(a[i], a[i + 1]);

    if (flag) {
      Yes();
      return 0;
    }
  }

  No();

  return 0;
}
