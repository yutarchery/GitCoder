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

ll n, l[int(5e5 + 5)], r[int(5e5 + 5)];
ll cnt = 0;

int main() {
  cin >> n;

  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i];
  }
  sort(l + 1, l + n + 1);

  for (int i = 1; i <= n; i++) {
    if (l[n] <= r[i]) {
      continue;
    }

    int now_l = 0, now_r = n;
    while (now_r - now_l > 1) {
      int mid = (now_l + now_r) / 2;
      if (l[mid] <= r[i]) {
        now_l = mid;
      } else {
        now_r = mid;
      }
    }

    cnt += n - now_l;
  }
  cout << n * (n - 1) / 2 - cnt << endl;

  return 0;
}
