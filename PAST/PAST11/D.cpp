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

int n, par[26];
string s, t;

int find(int a) {
  if (par[a] == a) {
    return a;
  } else {
    return par[a] = find(par[a]);
  }
}

void unite(int a, int b) {
  int pa = find(a), pb = find(b);
  par[max(pa, pb)] = min(pa, pb);
}

int main() {
  for (int i = 0; i < 26; i++) {
    par[i] = i;
  }

  cin >> n;
  for (int i = 0; i < n; i++) {
    char a, b;
    cin >> a >> b;
    unite(a - 'a', b - 'a');
  }
  for (int i = 0; i < 26; i++) {
    find(i);
  }

  cin >> s >> t;
  for (int i = 0; i < s.length(); i++) {
    s[i] = 'a' + par[s[i] - 'a'];
    t[i] = 'a' + par[t[i] - 'a'];
  }

  if (s == t) {
    Yes();
  } else {
    No();
  }

  return 0;
}