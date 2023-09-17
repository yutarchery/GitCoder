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

int n, k, q, a[205], l;

int main() {
  cin >> n >> k >> q;
  for (int i = 1; i <= k; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= q; i++) {
    cin >> l;

    if (a[l] == n) {
      continue;
    } else if (a[l] + 1 == a[l + 1]) {
      continue;
    } else {
      a[l]++;
    }
  }

  for (int i = 1; i <= k; i++) {
    cout << a[i];
    if (i == k) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}