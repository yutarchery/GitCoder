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

string s[9];
vector<Pii> p;

pair<int, Pii> node(int i, int j) {
  int di = abs(p[i].first - p[j].first), dj = abs(p[i].second - p[j].second);
  if (di > dj) {
    return {di * di + dj * dj, {di, dj}};
  } else {
    return {di * di + dj * dj, {dj, di}};
  }
}

bool judge(int i, int j, int k, int l) {
  vector<pair<int, Pii>> now;
  now.push_back(node(i, j));
  now.push_back(node(i, k));
  now.push_back(node(i, l));
  now.push_back(node(j, k));
  now.push_back(node(j, l));
  now.push_back(node(k, l));
  sort(now.begin(), now.end());

  if (now[4] == now[5]) {
    for (int idx = 0; idx + 1 < 4; idx++) {
      if (now[idx] != now[idx + 1]) {
        return false;
      }
    }
    return true;
  }
  return false;
}

int main() {
  for (int i = 0; i < 9; i++) {
    cin >> s[i];
    for (int j = 0; j < 9; j++) {
      if (s[i][j] == '#') {
        p.push_back({i, j});
      }
    }
  }

  int ans = 0, n = p.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        for (int l = k + 1; l < n; l++) {
          if (judge(i, j, k, l)) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;

  return 0;
}