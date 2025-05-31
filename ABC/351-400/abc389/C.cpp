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

int q, num, l, k;

int h = 0, b = 0;
ll a[int(3e5 + 5)], sum[int(3e5 + 5)];

int main() {
  cin >> q;
  while (q--) {
    cin >> num;

    if (num == 1) {
      cin >> l;
      b++;
      a[b] = l;
      sum[b] = sum[b - 1] + l;
    } else if (num == 2) {
      h++;
    } else {
      cin >> k;
      cout << sum[h + k - 1] - sum[h] << endl;
    }
  }

  return 0;
}
