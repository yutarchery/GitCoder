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
int n, cnt;

int main() {
  cin >> s;
  n = s.length();
  for (int i = 0; i < n; i++) {
    if ('A' <= s[i] && s[i] <= 'Z') {
      cnt++;
    }
  }

  if (cnt < (n - cnt)) {
    for (int i = 0; i < n; i++) {
      if ('A' <= s[i] && s[i] <= 'Z') {
        s[i] = s[i] - 'A' + 'a';
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      if ('a' <= s[i] && s[i] <= 'z') {
        s[i] = s[i] - 'a' + 'A';
      }
    }
  }
  cout << s << endl;

  return 0;
}
