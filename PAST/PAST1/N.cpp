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

int n, w, c;
int l[int(1e5 + 5)], r[int(1e5 + 5)];
ll p[int(1e5 + 5)], sum, ans;

ll sum_l[int(2e5 + 5)], sum_r[int(2e5 + 5)];

vector<int> locations;
map<int, bool> visited;
map<int, int> idx;

void prepare() {
  cin >> n >> w >> c;

  visited[0] = true;
  locations.push_back(0);
  locations.push_back(-1);
  locations.push_back(2e9 + 5);
  for (int i = 1; i <= n; i++) {
    cin >> l[i] >> r[i] >> p[i];
    sum += p[i];

    if (!visited[l[i]]) {
      visited[l[i]] = true;
      locations.push_back(l[i]);
    }
    if (!visited[r[i]]) {
      visited[r[i]] = true;
      locations.push_back(r[i]);
    }
  }
  ans = sum;
  sort(locations.begin(), locations.end());
  for (int i = 0; i < locations.size(); i++) {
    idx[locations[i]] = i;
  }

  for (int i = 1; i <= n; i++) {
    sum_l[idx[l[i]]] += p[i];
    sum_r[idx[r[i]]] += p[i];
  }
  for (int i = 1; i < locations.size(); i++) {
    sum_l[i] += sum_l[i - 1];
    sum_r[i] += sum_r[i - 1];
  }

  return;
}

void solve(int now) {
  if (now + c > w) {
    return;
  }

  ll sum_now = 0;
  int l_min = 0, l_max = locations.size() - 1;
  while (l_max - l_min > 1) {
    int mid = (l_min + l_max) / 2;
    if (now + c <= locations[mid]) {
      l_max = mid;
    } else {
      l_min = mid;
    }
  }
  sum_now += sum - sum_l[l_min];

  int r_min = 0, r_max = locations.size() - 1;
  while (r_max - r_min > 1) {
    int mid = (r_min + r_max) / 2;
    if (locations[mid] <= now) {
      r_min = mid;
    } else {
      r_max = mid;
    }
  }
  sum_now += sum_r[r_min];

  ans = min(ans, sum - sum_now);

  return;
}

int main() {
  prepare();
  solve(0);
  for (int i = 1; i <= n; i++) {
    solve(l[i]);
    solve(r[i]);
  }
  cout << ans << endl;

  return 0;
}
