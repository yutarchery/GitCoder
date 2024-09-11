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

int n;
ll d, x[int(2e5 + 5)], y[int(2e5 + 5)];

const ll offset = ll(2e6 + 5);
ll dist_x[int(6e6 + 5)], dist_y[int(6e6 + 5)];

int main() {
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    x[i] += offset;
    y[i] += offset;
  }
  sort(x + 1, x + n + 1);
  sort(y + 1, y + n + 1);

  for (int i = 1; i <= n; i++) {
    dist_x[0] += x[i];
    dist_y[0] += y[i];
  }

  int now_x = 0, now_y = 0;
  for (int i = 1; i <= offset * 2; i++) {
    dist_x[i] = dist_x[i - 1] - (n - now_x) + now_x;

    while (now_x < n && x[now_x + 1] <= i) {
      now_x++;
    }

    dist_y[i] = dist_y[i - 1] - n + 2 * now_y;
    while (now_y < n && y[now_y + 1] <= i) {
      now_y++;
    }
  }
  sort(dist_x, dist_x + offset * 2 + 1);
  sort(dist_y, dist_y + offset * 2 + 1);

  ll ans = 0;
  for (int i = 0; i <= offset * 2; i++) {
    if (dist_x[i] + dist_y[0] > d) {
      break;
    }

    int l = 0, r = offset * 2;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (dist_x[i] + dist_y[mid] <= d) {
        l = mid;
      } else {
        r = mid;
      }
    }

    ans += r;
  }
  cout << ans << endl;

  return 0;
}
