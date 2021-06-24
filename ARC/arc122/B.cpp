#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> Pii;
typedef pair<int, ll> Pil;
typedef pair<ll, ll> Pll;
typedef pair<ll, int> Pli;
typedef vector < vector<ll> > Mat;
#define fi first
#define se second 
const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll MOD3 = 1812447359;
const ll INF = 1ll << 62;
const double PI = 2 * asin(1);
void yes() {printf("yes\n");}
void no() {printf("no\n");}
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int N;
double A[int(1e5 + 5)];

double calc(double num){
  double ans = 0;
  for (int i = 0; i < N; i++){
    ans += max(A[i] - num, num);
  }
  return ans / N;
}

int main(){
  cin >> N;
  for (int i = 0; i < N; i++) cin >> A[i];

  double L = 0, R = 1e9;
  while (R - L > 1e-6){
    double xL = (L * 2 + R) / 3;
    double xR = (L + R * 2) / 3;

    if (calc(xL) <= calc(xR)) R = xR;
    else L = xL;
  }

  cout << setprecision(32) << calc(L) << endl;

  return 0;
}