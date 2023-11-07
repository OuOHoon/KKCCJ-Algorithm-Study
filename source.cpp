#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#define MAX 1001
#define FIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define f(g, h) for (int i = g; i < h; i++)
typedef long long ll;
using namespace std;

int n, dp[MAX] = {0, 0, 1, 0,};

// 상근이가 이기는 경우 1, 지는 경우 0
int main() {

    FIO;

    cin >> n;
    
    for (int i = 4; i <= n; i++) {
        // i - 1, i - 3번째 턴이 찬영이인 경우 상근이 승리
        if (!dp[i - 1] || !dp[i - 3]) dp[i] = 1;
        else dp[i] = 0;
    }
        
    if (dp[n]) cout << "SK";
    else cout << "CY";
   
}