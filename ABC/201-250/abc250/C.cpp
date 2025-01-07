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

int n, q, x[int(2e5 + 5)];
int order[int(2e5 + 5)], loc[int(2e5 + 5)];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    order[i] = i;
    loc[i] = i;
  }

  for (int i = 1; i <= q; i++) {
    cin >> x[i];

    int next_loc = loc[x[i]] + 1;
    if (next_loc == n + 1) {
      next_loc = n - 1;
    }

    int next = order[next_loc];

    swap(order[loc[x[i]]], order[loc[next]]);
    swap(loc[x[i]], loc[next]);
  }

  for (int i = 1; i <= n; i++) {
    cout << order[i];
    if (i == n) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  return 0;
}
