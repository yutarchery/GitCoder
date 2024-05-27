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

int n, t, a[int(2e5 + 5)];
int cnt_r[2005], cnt_c[2005], cnt_1, cnt_2;

int main() {
  cin >> n >> t;
  for (int i = 1; i <= t; i++) {
    cin >> a[i];
    a[i]--;
  }

  for (int i = 1; i <= t; i++) {
    int r = a[i] / n, c = a[i] % n;

    cnt_r[r]++;
    cnt_c[c]++;

    if (cnt_r[r] == n || cnt_c[c] == n) {
      cout << i << endl;
      return 0;
    }

    if (r == c) {
      cnt_1++;
      if (cnt_1 == n) {
        cout << i << endl;
        return 0;
      }
    }

    if (r + c == n - 1) {
      cnt_2++;
      if (cnt_2 == n) {
        cout << i << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;

  return 0;
}
