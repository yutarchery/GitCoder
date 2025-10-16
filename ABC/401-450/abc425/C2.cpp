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

int n, q;
ll a[int(4e5 + 5)];
int op, c, l, r;

ll sum[int(4e5 + 5)];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
  }
  for (int i = n + 1; i <= 2 * n; i++) {
    a[i] = a[i - n];
    sum[i] = sum[i - 1] + a[i];
  }

  int head_idx = 0;
  for (int i = 1; i <= q; i++) {
    cin >> op;
    if (op == 1) {
      cin >> c;
      head_idx = (head_idx + c) % n;
    } else {
      cin >> l >> r;
      int now_l = l + head_idx, now_r = r + head_idx;
      cout << sum[now_r] - sum[now_l - 1] << endl;
    }
  }

  return 0;
}
