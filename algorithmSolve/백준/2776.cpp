#include <iostream>
#include <set>

using namespace std;

// 풀이.
// 많은 정수들이 저장된 배열에서 특정 정수가 존재하는지 찾는 문제이다.
// 특정 정수를 찾는 것이기에 중복되는 정수는 없으므로 multiset이 아닌 set을 사용하였다.
// set안에 해당 정수가 존재한다면 1을, 존재하지 않는다면 0을 출력하면 된다.
// 다만 코드는 짧지만 관련 컨테이너를 사용하기 때문에 굉장히 느리다.

// 자세한 설명은 주석으로 남긴다.

set<int> board;
int T, N, M;

void MakeAnswer()
{
    for (int k = 0; k < T; ++k)
    {
        // 매 테스트 케이스마다 비워둬야 한다.
        board.clear();
        cin >> N;
        int num;
        // N개의 정수를 set에 저장한다.
        for (int i = 0; i < N; ++i)
        {
            cin >> num;
            board.insert(num);
        }
        cin >> M;
        // M번의 순회.
        for (int i = 0; i < M; ++i)
        {
            cin >> num;
            // 해당 정수가 존재한다면 1을, 존재하지 않으면 0을 출력한다.
            cout << (board.find(num) != board.end() ? 1 : 0) << '\n';
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}