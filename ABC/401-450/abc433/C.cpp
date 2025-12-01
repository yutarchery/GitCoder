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

int n;
string s;
vector<pair<char, int>> v;

int ans = 0;

int main() {
  cin >> s;
  n = s.length();

  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (s[i] == s[i - 1]) {
      cnt++;
    } else {
      v.push_back({s[i - 1], cnt});
      cnt = 1;
    }
  }
  v.push_back({s[n - 1], cnt});

  for (int i = 0; i < v.size() - 1; i++) {
    if (v[i].first + 1 == v[i + 1].first) {
      ans += min(v[i].second, v[i + 1].second);
    }
  }
  cout << ans << endl;

  return 0;
}
