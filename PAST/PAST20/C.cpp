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
int cnt = 0;
vector<char> ans[3];

int main() {
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == 'X') {
      cnt++;
      continue;
    }
    ans[cnt].push_back(s[i]);
  }
  reverse(ans[1].begin(), ans[1].end());

  for (int i = 0; i < 3; i++) {
    for (char c : ans[i]) {
      cout << c;
    }
  }
  cout << endl;

  return 0;
}
