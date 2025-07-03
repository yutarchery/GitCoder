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

int n, q, op, p;
string s;

pair<int, string> b[int(2e5 + 5)];
int ans, pc[int(2e5 + 5)];

string solve(int idx) {
  if (idx == 0) {
    return "";
  }

  return solve(b[idx].first) + b[idx].second;
}

int main() {
  cin >> n >> q;
  for (int i = 1; i <= q; i++) {
    cin >> op;
    if (op == 1) {
      cin >> p;
      pc[p] = ans;
    } else if (op == 2) {
      cin >> p >> s;
      b[i] = {pc[p], s};
      pc[p] = i;
    } else {
      cin >> p;
      ans = pc[p];
    }
  }

  cout << solve(ans) << endl;

  return 0;
}
