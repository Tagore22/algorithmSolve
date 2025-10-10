#include <iostream>

using namespace std;

// 풀이.
// 문제가 영 애매했었다. 예를 들어 1, 2, 3, 4, 5일때 5 2라면 단순히 5번을 2번위치로 이동시키는
// 거라고 생각했는데 그게 아니라 기준이 되는 큐 1, 2, 3, 4, 5가 있고 정답이 되는 텅빈 큐가 있어서
// 5번째 자리를 2로 지정해두고 나머지 원소들을 앞에서부터 차례대로 집어넣는 방식이었다.
// 문제가 너무 애매해서 한참 걸렸다.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;
    string answer[20], board[20];
    bool isvisit[20];
    for (int iter = 0; iter < T; ++iter)
    {
        int M, N;
        cin >> M >> N;
        for (int i = 0; i < M; ++i)
        {
            cin >> board[i];
            answer[i] = "";
            isvisit[i] = false;
        }
        for (int i = 0; i < N; ++i)
        {
            int from, to;
            cin >> from >> to;
            answer[to - 1] = board[from - 1];
            isvisit[from - 1] = true;
        }
        for (int i = 0; i < M; ++i)
        {
            if (answer[i] == "")
            {
                for (int j = 0; j < M; ++j)
                {
                    if (!isvisit[j])
                    {
                        answer[i] = board[j];
                        isvisit[j] = true;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < M; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
    }
    return 0;
}