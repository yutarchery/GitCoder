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
int C[int(1e5 + 5)];
vector <int> graph[int(1e5 + 5)];

vector <int> ans;
bool visited[int(1e5 + 5)];
int usedColor[int(1e5 + 5)];

int solve(int nowNode){

  if (usedColor[C[nowNode]] == 0){
    ans.push_back(nowNode);
  }
  usedColor[C[nowNode]]++;

  for (int nextNode : graph[nowNode]){
    if (visited[nextNode]) continue;
    visited[nextNode] = true;
    solve(nextNode);
  }
  usedColor[C[nowNode]]--;

  return 0;
}

int main(){
  cin >> N;
  for (int i = 1; i <= N; i++) cin >> C[i];
  for (int i = 0; i < N - 1; i++){
    int A, B; cin >> A >> B;
    graph[A].push_back(B);
    graph[B].push_back(A);
  }
  visited[1] = true;
  solve(1);
  sort(ans.begin(), ans.end());
  for (int ansNode : ans){
    cout << ansNode << endl;
  }

  return 0;
}