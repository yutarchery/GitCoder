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

int n, l, r;
char s[int(5e5 + 5)];

vector<int> idx[26];

ll solve(char c, int num) {
  int ok = 0, ng = idx[c - 'a'].size() - 1;
  if (idx[c - 'a'][ng] <= num) {
    return idx[c - 'a'].size();
  }

  while (ng - ok > 1) {
    int mid = (ok + ng) / 2;

    if (idx[c - 'a'][mid] <= num) {
      ok = mid;
    } else {
      ng = mid;
    }
  }

  return ok + 1;
}

int main() {
  // cin の高速化
  std::cin.tie(nullptr);
  ios::sync_with_stdio(false);

  cin >> n >> l >> r;
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    idx[s[i] - 'a'].emplace_back(i);
  }

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += solve(s[i], i + r) - solve(s[i], i + l - 1);
  }
  cout << ans << '\n';

  return 0;
}
