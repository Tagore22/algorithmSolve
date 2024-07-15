#include <iostream>

using namespace std;

// 풀이.
// 원리를 전혀 잘못 이해했다. lcs를 이용하는 건 알았으나 뭐... 정답은 lcs의 원리를 이용하여
// 약간 다른 방법으로 lcs를 구현하는 것이다. 먼저 lcs를 설명하자면 두 문자열을 2중 배열을 사용하여
// 각 위치에서 얻을 수 있는 최장 공통 분모를 찾는 것이다. 이 부분에서 조금 다르게 손을 보면 된다.

// 자세한 설명은 주석으로 남긴다.

int board[1001][1001] = { 0, };
string str1, str2;

void MakeAnswer()
{
    // 원래 lcs는 맨 위와 맨 왼쪽은 0으로 초기화한다. 문자열이 ""일때 공통되는 부분이 있을수 없기 때문이다.
    // 하지만 이번에는 각 문자열의 길이로 한다. 마찬가지로 문자열이 ""일때 그 문자열을 만들기 위해서는
    // 삭제 혹은 추가로 문자열의 길이만큼 수정해야 하기 때문이다.
    for (int i = 0; i <= str1.size(); ++i)
        board[i][0] = i;
    for (int i = 0; i <= str2.size(); ++i)
        board[0][i] = i;
    // lcs 순회 시작.
    for (int i = 0; i < str1.size(); ++i)
        for (int j = 0; j < str2.size(); ++j)
        {
            // 현재 문자들이 같다면 두 문자를 사용하지 않았을때와 같다.
            if (str1[i] == str2[j])
                board[i + 1][j + 1] = board[i][j];
            // 두 문자가 다르다면 최소값을 위해 그 이전 3개의 값과 비교하여 가장 작은수 + 1을 한다.
            else
                board[i + 1][j + 1] = min(board[i][j + 1], min(board[i + 1][j], board[i][j])) + 1;
        }
    // 맨 마지막의 경우를 출력한다.
    cout << board[str1.size()][str2.size()] << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> str1 >> str2;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}