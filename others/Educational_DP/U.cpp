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

int n;
ll a[16][16], dp[1 << 16], group[1 << 16];
bool visited[1 << 16];

ll solve(int idx) {
  if (visited[idx]) {
    return dp[idx];
  }

  visited[idx] = true;
  ll ans = 0;

  for (int t = idx; t >= 0; t--) {
    t &= idx;
    if (t == idx) {
      continue;
    }
    ans = max(ans, solve(t) + group[idx - t]);
  }

  return dp[idx] = ans;
}

void prepare(int idx) {
  vector<int> member;
  int rest = idx;
  for (int i = 0; i < n; i++) {
    if (rest % 2 == 1) {
      member.push_back(i);
    }
    rest /= 2;
  }
  for (int i = 0; i < member.size(); i++) {
    for (int j = i + 1; j < member.size(); j++) {
      group[idx] += a[member[i]][member[j]];
    }
  }

  return;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 0; i < (1 << n); i++) {
    prepare(i);
  }
  cout << solve((1 << n) - 1) << endl;

  return 0;
}
