#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 2개의 배열을 사용하여 두개의 수들을 길이가 2가 될때까지 합쳐주면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board[2];
string a, b;
int cur = 0;

int main()
{
    cin >> a >> b;
    // 2개의 번호를 하나로 합쳐준다.
    for (int i = 0; i < 8; ++i)
    {
        board[cur].push_back(a[i] - '0');
        board[cur].push_back(b[i] - '0');
    }

    // 합친 결과의 크기가 2일때까지 반복.
    while (board[cur].size() > 2)
    {
        // 비트마스크 연산으로 다음번 인덱스를 얻는다.
        int next = cur ^ 1;
        // 새로 집어넣을 배열을 비운다.
        board[next].clear();
        // 기존의 배열들값을 계산하여 새로운 배열에 넣는다.
        for (int i = 0; i < board[cur].size() - 1; ++i)
            board[next].push_back((board[cur][i] + board[cur][i + 1]) % 10);
        // 현재 인덱스를 갱신한다.
        cur = next;
    }
    for (auto a : board[cur])
        cout << a;
    cout << '\n';
    return 0;
}