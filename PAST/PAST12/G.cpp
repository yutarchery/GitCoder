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

int n, l, k, ans;
string s[1005];

bool visited[10];

int solve() {
  int res = 0;
  map<string, int> used;
  for (int i = 1; i <= n; i++) {
    string t = "";
    for (int j = 0; j < l; j++) {
      if (visited[j]) {
        t += '?';
      } else {
        t += s[i][j];
      }
    }
    used[t]++;
    res = max(res, used[t]);
  }
  return res;
}

void make_visited(int idx, int cnt) {
  if (idx == l) {
    if (cnt == k) {
      ans = max(ans, solve());
    }
    return;
  }

  visited[idx] = true;
  make_visited(idx + 1, cnt + 1);

  visited[idx] = false;
  make_visited(idx + 1, cnt);

  return;
}

int main() {
  cin >> n >> l >> k;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
  }

  make_visited(0, 0);
  cout << ans << endl;

  return 0;
}