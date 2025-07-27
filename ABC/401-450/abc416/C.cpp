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

int n, k, x;
string s[10];

vector<string> ans;

void solve(int turn = 0, string now = "") {
  if (turn == k) {
    ans.push_back(now);
    return;
  }

  for (int i = 0; i < n; i++) {
    solve(turn + 1, now + s[i]);
  }
  return;
}

int main() {
  cin >> n >> k >> x;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }
  solve();
  sort(ans.begin(), ans.end());
  cout << ans[x - 1] << endl;

  return 0;
}
