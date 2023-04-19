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
string s, t;

void solve(int idx) {
  string tmp = "";
  for (int i = 0; i < t.length(); i++) {
    if (t[i] == s[idx]) {
      continue;
    }
    tmp += t[i];
  }
  tmp += s[idx];
  t = tmp;
  return;
}

int main() {
  cin >> n >> s;

  for (int i = 0; i < n; i++) {
    solve(i);
  }
  cout << t << endl;
  return 0;
}