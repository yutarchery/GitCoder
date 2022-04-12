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
const ll mod = 1e9 + 7;
const ll mod2 = 998244353;
const ll mod3 = 1812447359;
const ll inf = 1ll << 62;
const double pi = 2 * asin(1);
void yes() { printf("yes\n"); }
void no() { printf("no\n"); }
void Yes() { printf("Yes\n"); }
void No() { printf("No\n"); }
void YES() { printf("YES\n"); }
void NO() { printf("NO\n"); }

const int n = 1 << 20;
int q;
int edge[(1 << 20)];
ll ans[(1 << 20)];

int add(int idx, ll score) {

  int start = idx;
  while (idx != edge[idx]) {
    idx = edge[idx];
  }

  ans[idx] = score;

  if (idx == n - 1) {
    edge[idx] = 0;
  } else {
    edge[idx] = idx + 1;
  }

  while (start != idx) {
    int next = edge[start];
    edge[start] = idx + 1;
    start = next;
  }

  return 0;
}

int main() {

  for (int i = 0; i < n; i++) {
    edge[i] = i;
    ans[i] = -1;
  }

  cin >> q;

  for (int i = 0; i < q; i++) {
    int t;
    ll x;
    cin >> t >> x;
    ll idx = x % n;

    if (t == 1) {
      add(idx, x);
    } else {
      cout << ans[idx] << endl;
    }
  }

  return 0;
}