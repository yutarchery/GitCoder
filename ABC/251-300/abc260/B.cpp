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

int n, x, y, z, a[1005], b[1005];

bool visited[1005];
priority_queue<Pii> math, eng, sum;

int main() {
  cin >> n >> x >> y >> z;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    math.push({a[i], -1 * i});
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
    eng.push({b[i], -1 * i});
    sum.push({a[i] + b[i], -1 * i});
  }

  while (x > 0) {
    Pii q = math.top();
    math.pop();
    if (visited[-1 * q.second]) {
      continue;
    } else {
      visited[-1 * q.second] = true;
      x--;
    }
  }
  while (y > 0) {
    Pii q = eng.top();
    eng.pop();
    if (visited[-1 * q.second]) {
      continue;
    } else {
      visited[-1 * q.second] = true;
      y--;
    }
  }
  while (z > 0) {
    Pii q = sum.top();
    sum.pop();
    if (visited[-1 * q.second]) {
      continue;
    } else {
      visited[-1 * q.second] = true;
      z--;
    }
  }

  for (int i = 1; i <= n; i++) {
    if (visited[i]) {
      cout << i << endl;
    }
  }

  return 0;
}
