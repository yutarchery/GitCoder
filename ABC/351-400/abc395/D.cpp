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

int n, q, op, a, b;
int p_b[int(1e6 + 5)], b_l[int(1e6 + 5)], l_b[int(1e6 + 5)];

int main() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    p_b[i] = i;
    b_l[i] = i;
    l_b[i] = i;
  }

  while (q--) {
    cin >> op;
    if (op == 1) {
      cin >> a >> b;
      p_b[a] = l_b[b];
    } else if (op == 2) {
      cin >> a >> b;
      swap(b_l[l_b[a]], b_l[l_b[b]]);
      swap(l_b[a], l_b[b]);
    } else {
      cin >> a;
      cout << b_l[p_b[a]] << endl;
    }
  }

  return 0;
}
