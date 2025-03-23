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

string s;
int n, v[30], val[30];
char c[30];

int main() {
  cin >> s;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> c[i] >> v[i];
    val[c[i] - 'a'] = v[i];
  }

  int ans = 0;
  if ('a' <= s[0] && s[0] <= 'z') {
    ans = val[s[0] - 'a'];
  } else {
    ans = s[0] - '0';
  }

  for (int i = 2; i < s.length(); i += 2) {
    int now = s[i] - '0';
    if ('a' <= s[i] && s[i] <= 'z') {
      now = val[s[i] - 'a'];
    }

    if (s[i - 1] == '+') {
      ans += now;
    } else {
      ans -= now;
    }
  }

  cout << ans << endl;

  return 0;
}
