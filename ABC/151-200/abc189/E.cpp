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
void yes() { cout << "yes\n"; }
void no() { cout << "no\n"; }
void Yes() { cout << "Yes\n"; }
void No() { cout << "No\n"; }
void YES() { cout << "YES\n"; }
void NO() { cout << "NO\n"; }

int n, m, q, op[int(2e5 + 5)], p[int(2e5 + 5)];
ll x[int(2e5 + 5)], y[int(2e5 + 5)], a[int(2e5 + 5)], b[int(2e5 + 5)];

ll mats[int(2e5 + 5)][3][3];

void prepare() {
  mats[0][0][0] = 1;
  mats[0][1][1] = 1;
  mats[0][2][2] = 1;

  return;
}

void mat_calc(int idx, vector<vector<ll>> now) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int k = 0; k < 3; k++) {
        mats[idx][i][j] += now[i][k] * mats[idx - 1][k][j];
      }
    }
  }

  return;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  prepare();

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> y[i];
  }

  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> op[i];

    if (op[i] == 1) {
      mat_calc(i, {{0, 1, 0}, {-1, 0, 0}, {0, 0, 1}});
    } else if (op[i] == 2) {
      mat_calc(i, {{0, -1, 0}, {1, 0, 0}, {0, 0, 1}});
    } else if (op[i] == 3) {
      cin >> p[i];
      mat_calc(i, {{-1, 0, p[i] * 2}, {0, 1, 0}, {0, 0, 1}});
    } else {
      cin >> p[i];
      mat_calc(i, {{1, 0, 0}, {0, -1, p[i] * 2}, {0, 0, 1}});
    }
  }

  cin >> q;
  for (int i = 1; i <= q; i++) {
    cin >> a[i] >> b[i];

    vector<ll> now = {x[b[i]], y[b[i]], 1};

    ll ans_x = 0, ans_y = 0;
    for (int j = 0; j < 3; j++) {
      ans_x += mats[a[i]][0][j] * now[j];
      ans_y += mats[a[i]][1][j] * now[j];
    }

    cout << ans_x << " " << ans_y << '\n';
  }

  return 0;
}
