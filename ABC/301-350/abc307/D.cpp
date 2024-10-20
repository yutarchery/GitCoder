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

int n, now_idx = 0;
string s;
vector<char> ans[int(2e5 + 5)];

int main() {
  cin >> n;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == ')') {
      if (now_idx >= 1) {
        ans[now_idx] = {};
        now_idx--;
        continue;
      }
    }
    if (s[i] == '(') {
      now_idx++;
    }
    ans[now_idx].push_back(s[i]);
  }

  for (int i = 0; i <= n; i++) {
    for (char c : ans[i]) {
      cout << c;
    }
  }
  cout << endl;

  return 0;
}
