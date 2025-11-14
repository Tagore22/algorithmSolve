#include <iostream>
#include <deque>

using namespace std;

// 11003번의 덱을 이용한 풀이.
// 덱의 push, pop은 1인 상수 시간이기에 훨씬 더 빠를 줄 알았는데
// 딱히 그렇지는 않았다. 다만 주의할 점은 앞이 작고 뒤가 크다는
// 형태를 유지하는 것이다.

// 자세한 설명은 주석으로 남긴다.

int board[5000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, L;
    cin >> N >> L;
    for (int i = 0; i < N; ++i)
        cin >> board[i + 1];
    deque<pair<int, int>> deq;
    for (int i = 1; i <= N; ++i)
    {
        // 기존에는 두 while문을 합쳤었다. 다만 상술하였듯 앞이 작고 뒤가 큰 
        // 형태를 유지해야하기 때문에 각각 앞에서와 뒤에서 두 부분으로 나누어
        // 기존값을 삭제한다.

        // 현재 값보다 큰 값들은 삭제한다.
        while (!deq.empty() && deq.back().second > board[i])
        {
            deq.pop_back();
        }
        // 현재 값보다 작은 것들중 범위값을 벗어난 것들을 삭제한다.
        while (!deq.empty() && deq.front().first < i - L + 1)
        {
            deq.pop_front();
        }
        deq.push_back(make_pair(i, board[i]));
        cout << deq.front().second << ' ';
    }
    return 0;
}