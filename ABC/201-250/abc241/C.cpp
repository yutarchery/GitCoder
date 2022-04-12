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

int n, rest[1005][1005];
string s[1005];

int search(int startI, int startJ) {

  int ans = 6;

  if (startI + 5 < n) {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
      if (s[startI + i][startJ] == '.')
        cnt++;
    }
    ans = min(ans, cnt);
  }

  if (startJ + 5 < n) {
    int cnt = 0;
    for (int j = 0; j < 6; j++) {
      if (s[startI][startJ + j] == '.')
        cnt++;
    }

    ans = min(ans, cnt);
  }

  if (startI + 5 < n && startJ + 5 < n) {
    int cnt = 0;
    for (int k = 0; k < 6; k++) {
      if (s[startI + k][startJ + k] == '.')
        cnt++;
    }
    ans = min(ans, cnt);
  }

  if (startI + 5 < n && startJ - 5 >= 0) {
    int cnt = 0;
    for (int k = 0; k < 6; k++) {
      if (s[startI + k][startJ - k] == '.')
        cnt++;
    }
    ans = min(ans, cnt);
  }

  rest[startI][startJ] = ans;

  return 0;
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      search(i, j);

      if (rest[i][j] <= 2) {
        Yes();
        return 0;
      }
    }
  }
  No();

  return 0;
}