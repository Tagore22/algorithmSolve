#include <iostream>

using namespace std;

// 풀이.
// 머리가 안돌아간다. 일찍 자야겠다. DP문제지만 일반적인 DP와는 조금 다르다.
// 기존에는 최소값이나 최대값을 구해서 DP값을 반환하지만 이번에 DP는 해당 연산이 실행되었는지의 여부만 따진다.
// 또한, 굳이 DP를 써야하나 의문이었다. DP는 중복을 방지하기 위함인데 중복연산이 되는 상황이 떠오르질 않았기 때문이다.
// 하지만 잘 생각해보면 반드시 존재했는데 예를 들어 AAAABBBBCCCC를 이용할때 어느 순간 맨 마지막이 B, C 형태가 되는
// 조합은 굉장히 많을 것이다. 이 모든 순간들이 중복이 된다. 맨 뒤 2개를 제외하곤 연산에 사용되지 않기 때문이다.
// 그렇기 때문에 반드시 DP를 써야만 했다.

// 자세한 설명은 주석으로 남긴다.

int board[3];
bool dp[51][51][51][3][3] = { false, };
char ans[51];
string str;

// DFS 함수. 각 a, b, c에 사용된 수들과 이전이전 값, 이전 값.
bool DFS(int a, int b, int c, int pp, int p)
{
    // 모두 사용되었다면 성공을 반환한다.
    if (a == board[0] && b == board[1] && c == board[2])
        return true;

    // 처음 연산시에 cur은 false상태이며 연산 시작시 true가 된다. 이 이후 중복이 된다면
    // 무시하기 위해 false를 반환하고 탈출한다.
    bool& cur = dp[a][b][c][pp][p];
    if (cur)
        return false;
    cur = true;

    if (a + 1 <= board[0] && DFS(a + 1, b, c, p, 0))
    {
        ans[a + b + c] = 'A';
        return true;
    }
    // B부터는 기존의 사용된 알파벳까지 확인해야 한다.
    if (b + 1 <= board[1] && p != 1 && DFS(a, b + 1, c, p, 1))
    {
        ans[a + b + c] = 'B';
        return true;
    }
    if (c + 1 <= board[2] && pp != 2 && p != 2 && DFS(a, b, c + 1, p, 2))
    {
        ans[a + b + c] = 'C';
        return true;
    }
    return false;
}

void MakeAnswer()
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'A')
            ++board[0];
        else if (str[i] == 'B')
            ++board[1];
        else
            ++board[2];
    }
    if (DFS(0, 0, 0, -1, -1))
    {
        for (int i = 0; i < str.size(); ++i)
            cout << ans[i];
        cout << '\n';
    }
    else
    {
        cout << -1 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> str;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}