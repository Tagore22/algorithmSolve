#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 풀이.
// 22862의 두번째 풀이. 홀수인 원소들의 위치값만을
// 이용하여 푼 풀이이다. 처음 로직을 구상할 때에는 상술한대로
// 첫번째 풀이처럼 일일이 1씩 증가하며 순회하지 않기 때문에
// 더 빠를 줄 알았으나 전부 홀수거나 전부 짝수일 때에는 딱히
// 그러지 않기에 속도는 비슷했다. 다만 벡터를 사용할 때
// reserve를 잊었었는데 그렇기 때문에 벡터의 특성상 메모리가
// 괴랄하게 증가하였었다. 주의하자.

int N, K;
vector<int> board;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    board.reserve(N);
    for (int i = 0; i < N; ++i)
    {
        int num;
        cin >> num;
        if (num % 2 != 0)
            board.push_back(i);
    }

    int from = 0, answer = 0;
    for (int i = K; i < board.size(); ++i)
    {
        answer = max(answer, board[i] - from - K);
        from = board[i - K] + 1;
    }

    int minus = lower_bound(board.begin(), board.end(), from) - board.begin();
    int bsize = board.size();
    answer = max(answer, N - from - bsize - minus);
    cout << answer << '\n';
    return 0;
}