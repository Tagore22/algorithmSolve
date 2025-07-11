#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 풀이.
// 처음에는 어렵게 생각했다. 최대 문자열의 길이가 500이고 각각 N과 M이 10000이기 때문에
// 최대 연산량은 500억에 달했다. 트라이를 염두했으나 그것보다 더 간단한 풀이가 있었다.
// 애시당초에 부분 문자열인지 확인하는 문자열을 찾을 때 맨 앞에서부터 순회하지 않고
// lower_bound()를 통해서 이분 탐색을 실행하면 연산량이 확 줄어들기 때문이다.

vector<string> board;
int N, M;

void Solve()
{
    sort(board.begin(), board.end());
    int answer = 0;
    for (int i = 0; i < M; ++i)
    {
        string str;
        cin >> str;

        auto iter = lower_bound(board.begin(), board.end(), str);
        if (iter->substr(0, str.size()) == str)
            ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        board.push_back(str);
    }
}

int main()
{
    Input();
    Solve();
    return 0;
}