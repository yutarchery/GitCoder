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

bool ans[int(1e6 + 5)], flag = false;
int start = 0;

int main() {
  cin >> n;
  cin >> s;

  fill(ans, ans + n, true);
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == '/' && s[i + 1] == '*' && !flag) {
      flag = true;
      start = i;
      i++;
      continue;
    }
    if (s[i] == '*' && s[i + 1] == '/' && flag) {
      flag = false;
      fill(ans + start, ans + i + 2, false);
      i++;
      continue;
    }
  }

  for (int i = 0; i < n; i++) {
    if (ans[i]) {
      cout << s[i];
    }
  }
  cout << endl;

  return 0;
}
