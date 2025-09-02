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

ll rt, ct, ra, ca;
ll n, m, l;
char s[int(1e5 + 5)], t[int(1e5 + 5)];
ll a[int(1e5 + 5)], b[int(1e5 + 5)];

const char dir[4] = {'U', 'D', 'L', 'R'};
const ll di[4] = {-1, 1, 0, 0}, dj[4] = {0, 0, -1, 1};

int main() {
  cin >> rt >> ct >> ra >> ca;
  cin >> n >> m >> l;
  for (int i = 1; i <= m; i++) {
    cin >> s[i] >> a[i];
  }
  for (int i = 1; i <= l; i++) {
    cin >> t[i] >> b[i];
  }

  ll ans = 0, rest = n;
  int t_idx = 1, a_idx = 1;
  while (rest > 0) {
    ll now = min(a[t_idx], b[a_idx]);
    rest -= now;

    int kt = 0, ka = 0;
    for (int k = 0; k < 4; k++) {
      if (s[t_idx] == dir[k]) {
        kt = k;
      }
      if (t[a_idx] == dir[k]) {
        ka = k;
      }
    }

    ll x, y, px, py;
    bool visited_x = false, visited_y = false;
    if (di[kt] != di[ka]) {
      visited_x = true;
      x = (ra - rt) / (di[kt] - di[ka]);
      px = (ra - rt) % (di[kt] - di[ka]);
    }
    if (dj[kt] != dj[ka]) {
      visited_y = true;
      y = (ca - ct) / (dj[kt] - dj[ka]);
      py = (ca - ct) % (dj[kt] - dj[ka]);
    }

    if (!visited_x && !visited_y) {
      if (rt == ra && ct == ca) {
        ans += now;
      }
    } else if (visited_x && visited_y) {
      if (x == y && px == 0 && py == 0 && 1 <= x && x <= now) {
        ans++;
      }
    } else if (visited_x && !visited_y) {
      if (px == 0 && 1 <= x && x <= now && ct == ca) {
        ans++;
      }
    } else {
      if (py == 0 && 1 <= y && y <= now && rt == ra) {
        ans++;
      }
    }

    rt = rt + di[kt] * now, ct = ct + dj[kt] * now;
    ra = ra + di[ka] * now, ca = ca + dj[ka] * now;

    a[t_idx] -= now;
    if (a[t_idx] == 0) {
      t_idx++;
    }

    b[a_idx] -= now;
    if (b[a_idx] == 0) {
      a_idx++;
    }
  }

  cout << ans << endl;

  return 0;
}
