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

int w, h, n, p[int(2e5 + 5)], q[int(2e5 + 5)];
int ca, cb, a[int(2e5 + 5)], b[int(2e5 + 5)];

int p_idx[int(2e5 + 5)], q_idx[int(2e5 + 5)];
map<Pii, int> cnt;

int main() {
  cin >> w >> h;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i] >> q[i];
  }
  cin >> ca;
  for (int i = 1; i <= ca; i++) {
    cin >> a[i];
  }
  a[ca + 1] = w;
  cin >> cb;
  for (int i = 1; i <= cb; i++) {
    cin >> b[i];
  }
  b[cb + 1] = h;

  for (int i = 1; i <= n; i++) {
    int la = 0, ra = ca + 1;
    while (ra - la > 1) {
      int mid = (la + ra) / 2;
      if (a[mid] <= p[i]) {
        la = mid;
      } else {
        ra = mid;
      }
    }
    p_idx[i] = la;

    int lb = 0, rb = cb + 1;
    while (rb - lb > 1) {
      int mid = (lb + rb) / 2;
      if (b[mid] <= q[i]) {
        lb = mid;
      } else {
        rb = mid;
      }
    }
    q_idx[i] = lb;

    cnt[{p_idx[i], q_idx[i]}]++;
  }

  int ans_min = 1e9, ans_max = 0;
  for (int i = 1; i <= n; i++) {
    ans_min = min(ans_min, cnt[{p_idx[i], q_idx[i]}]);
    ans_max = max(ans_max, cnt[{p_idx[i], q_idx[i]}]);
  }
  for (int i = 0; i <= ca; i++) {
    for (int j = 0; j <= cb; j++) {
      if (cnt[{i, j}] == 0) {
        cout << 0 << " " << ans_max << endl;
        return 0;
      }
    }
  }

  cout << ans_min << " " << ans_max << endl;

  return 0;
}
