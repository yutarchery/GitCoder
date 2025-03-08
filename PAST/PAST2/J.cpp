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

string s, ans[1005];

int main() {
  cin >> s;
  int cnt = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      cnt++;
    } else if (s[i] == ')') {
      ans[cnt - 1] += ans[cnt];
      for (int j = ans[cnt].length() - 1; j >= 0; j--) {
        ans[cnt - 1] += ans[cnt][j];
      }
      ans[cnt] = "";
      cnt--;
    } else {
      ans[cnt] += s[i];
    }
  }

  cout << ans[0] << endl;

  return 0;
}
