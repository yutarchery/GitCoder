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

int h, w, n, q;
int r[int(3e5 + 5)], c[int(3e5 + 5)];
int op, u, d;

vector<int> rs, cs;
map<int, bool> r_visited, c_visited;
map<int, int> r_idx, c_idx;
int r_sum[int(3e5 + 5)], c_sum[int(3e5 + 5)];

void prepare() {
  for (int i = 1; i <= n; i++) {
    if (!r_visited[r[i]]) {
      rs.emplace_back(r[i]);
      r_visited[r[i]] = true;
    }

    if (!c_visited[c[i]]) {
      cs.emplace_back(c[i]);
      c_visited[c[i]] = true;
    }
  }

  rs.emplace_back(0);
  rs.emplace_back(int(2e9));
  sort(rs.begin(), rs.end());
  for (int i = 0; i < rs.size(); i++) {
    r_idx[rs[i]] = i;
  }

  cs.emplace_back(0);
  cs.emplace_back(int(2e9));
  sort(cs.begin(), cs.end());
  for (int i = 0; i < cs.size(); i++) {
    c_idx[cs[i]] = i;
  }

  for (int i = 1; i <= n; i++) {
    r_sum[r_idx[r[i]]]++;
    c_sum[c_idx[c[i]]]++;
  }

  for (int i = 1; i <= n; i++) {
    r_sum[i] += r_sum[i - 1];
    c_sum[i] += c_sum[i - 1];
  }

  return;
}

int count_r(int num) {
  int ok = 0, ng = rs.size();
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;

    if (rs[mid] <= num) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return r_sum[ok];
}

int count_c(int num) {
  int ok = 0, ng = cs.size();
  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;

    if (cs[mid] <= num) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return c_sum[ok];
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> h >> w >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> r[i] >> c[i];
  }

  prepare();

  while (q--) {
    cin >> op >> u >> d;

    if (op == 1) {
      cout << count_r(d) - count_r(u - 1) << '\n';
    } else {
      cout << count_c(d) - count_c(u - 1) << '\n';
    }
  }

  return 0;
}
