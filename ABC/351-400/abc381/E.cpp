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

int n, q, l, r;
char s[int(2e5 + 5)];

int cnt_1[int(2e5 + 5)], cnt_2[int(2e5 + 5)];
vector<int> slash;

int search_l(int l, int r, int num) {
  if (cnt_1[r] < num + cnt_1[l - 1]) {
    return r + 1;
  }

  int now_l = l - 1, now_r = r;
  while (now_r - now_l > 1) {
    int mid = (now_l + now_r) / 2;
    if (cnt_1[mid] - cnt_1[l - 1] >= num) {
      now_r = mid;
    } else {
      now_l = mid;
    }
  }
  return now_r;
}

int search_r(int l, int r, int num) {
  if (cnt_2[l] - cnt_2[r + 1] < num) {
    return l - 1;
  }

  int now_l = l, now_r = r;
  while (now_r - now_l > 1) {
    int mid = (now_l + now_r) / 2;
    if (cnt_2[mid] - cnt_2[r + 1] >= num) {
      now_l = mid;
    } else {
      now_r = mid;
    }
  }

  return now_l;
}

bool have_slash(int l_idx, int r_idx) {
  int now_l = 0, now_r = slash.size() - 1;
  while (now_r - now_l > 1) {
    int mid = (now_l + now_r) / 2;
    if (slash[mid] < l_idx) {
      now_l = mid;
    } else {
      now_r = mid;
    }
  }

  if (slash[now_r] <= r_idx) {
    return true;
  } else {
    return false;
  }
}

int solve(int l, int r) {
  if (!have_slash(l, r)) {
    return 0;
  }

  int now_l = 0, now_r = r - l + 1;
  while (now_r - now_l > 1) {
    int mid = (now_l + now_r) / 2;
    int l_idx = search_l(l, r, mid), r_idx = search_r(l, r, mid);

    if (l_idx > r_idx) {
      now_r = mid;
      continue;
    }

    if (have_slash(l_idx, r_idx)) {
      now_l = mid;
    } else {
      now_r = mid;
    }
  }

  return now_l * 2 + 1;
}

int main() {
  cin >> n >> q;
  slash.push_back(0);
  for (int i = 1; i <= n; i++) {
    cin >> s[i];
    if (s[i] == '/') {
      slash.push_back(i);
    }
  }
  slash.push_back(n + 1);
  for (int i = 1; i <= n; i++) {
    cnt_1[i] = cnt_1[i - 1];
    if (s[i] == '1') {
      cnt_1[i]++;
    }
  }
  cnt_1[n + 1] = cnt_1[n];

  for (int i = n; i >= 1; i--) {
    cnt_2[i] = cnt_2[i + 1];
    if (s[i] == '2') {
      cnt_2[i]++;
    }
  }
  cnt_2[0] = cnt_2[1];

  while (q--) {
    cin >> l >> r;
    cout << solve(l, r) << endl;
  }

  return 0;
}
