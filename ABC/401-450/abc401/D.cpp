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

int n, k;
string s;

vector<int> questions;

int main() {
  cin >> n >> k;
  cin >> s;

  for (int i = 0; i < n; i++) {
    if (s[i] == 'o') {
      k--;
      if (i - 1 >= 0) {
        s[i - 1] = '.';
      }
      if (i + 1 < n) {
        s[i + 1] = '.';
      }
    }
  }

  if (k == 0) {
    for (int i = 0; i < n; i++) {
      if (s[i] == '?') {
        s[i] = '.';
      }
    }
    cout << s << endl;
    return 0;
  }

  int cnt = 0, sum = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      cnt++;
    } else if (cnt > 0) {
      questions.push_back(cnt);
      sum += (cnt + 1) / 2;
      cnt = 0;
    }
  }
  if (cnt > 0) {
    questions.push_back(cnt);
    sum += (cnt + 1) / 2;
    cnt = 0;
  }

  if (sum > k) {
    cout << s << endl;
    return 0;
  }

  int idx = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != '?') {
      continue;
    }
    if (questions[idx] % 2 == 0) {
      i += questions[idx] - 1;
      idx++;
    } else {
      for (int j = 0; j < questions[idx]; j++) {
        if (j % 2 == 0) {
          s[i + j] = 'o';
        } else {
          s[i + j] = '.';
        }
      }
      idx++;
    }
  }
  cout << s << endl;

  return 0;
}
