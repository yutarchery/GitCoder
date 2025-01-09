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

int n, m;
ll sx, sy, x[int(2e5 + 5)], y[int(2e5 + 5)];
char d[int(2e5 + 5)];
ll c[int(2e5 + 5)];

int ans = 0;

map<ll, vector<ll>> vx, vy;
map<ll, set<ll>> house_x, house_y;

map<ll, bool> checked_x, checked_y;

void search_x(ll now_x, ll min_y, ll max_y) {
  auto iter = house_x[now_x].lower_bound(min_y);

  while (iter != house_x[now_x].end()) {
    ll now_y = *iter;
    if (max_y < now_y) {
      break;
    }
    ans++;
    iter++;
    house_x[now_x].erase(now_y);
    house_y[now_y].erase(now_x);
  }

  return;
}

void search_y(ll now_y, ll min_x, ll max_x) {
  auto iter = house_y[now_y].lower_bound(min_x);

  while (iter != house_y[now_y].end()) {
    ll now_x = *iter;
    if (max_x < now_x) {
      break;
    }
    ans++;
    iter++;
    house_y[now_y].erase(now_x);
    house_x[now_x].erase(now_y);
  }

  return;
}

int main() {
  cin >> n >> m >> sx >> sy;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
    house_x[x[i]].insert(y[i]);
    house_y[y[i]].insert(x[i]);
  }

  for (int i = 1; i <= m; i++) {
    cin >> d[i] >> c[i];

    if (!checked_x[sx]) {
      checked_x[sx] = true;
      house_x[sx].insert(-1e16);
      house_x[sx].insert(1e16);
    }

    if (!checked_y[sy]) {
      checked_y[sy] = true;
      house_y[sy].insert(-1e16);
      house_y[sy].insert(1e16);
    }

    if (d[i] == 'U') {
      search_x(sx, sy, sy + c[i]);
      sy += c[i];
    } else if (d[i] == 'D') {
      search_x(sx, sy - c[i], sy);
      sy -= c[i];
    } else if (d[i] == 'L') {
      search_y(sy, sx - c[i], sx);
      sx -= c[i];
    } else {
      search_y(sy, sx, sx + c[i]);
      sx += c[i];
    }
  }

  cout << sx << " " << sy << " " << ans << endl;

  return 0;
}
