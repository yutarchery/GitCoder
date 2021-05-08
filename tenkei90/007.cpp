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

int N, Q, B;
int A[int(3e5 + 5)];

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> A[i];
  sort(A + 1, A + N + 1);

  cin >> Q;
  for (int i = 1; i <= Q; i++){
    cin >> B;
    if (B >= A[N]){
      cout << B - A[N] << endl;
      continue;
    }else if (B <= A[1]){
      cout << A[1] - B << endl;
      continue;
    }

    int L = 0, R = N;
    while (R - L > 1){
      int mid = (L + R) / 2;
      if (B < A[mid]) R = mid;
      else L = mid;
    }

    cout << min(abs(A[L] - B), abs(A[R] - B)) << endl;
  }
  
  return 0;
}