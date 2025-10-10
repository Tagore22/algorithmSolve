#include <iostream>

using namespace std;

// Ǯ��.
// ������ �� �ָ��߾���. ���� ��� 1, 2, 3, 4, 5�϶� 5 2��� �ܼ��� 5���� 2����ġ�� �̵���Ű��
// �Ŷ�� �����ߴµ� �װ� �ƴ϶� ������ �Ǵ� ť 1, 2, 3, 4, 5�� �ְ� ������ �Ǵ� �ֺ� ť�� �־
// 5��° �ڸ��� 2�� �����صΰ� ������ ���ҵ��� �տ������� ���ʴ�� ����ִ� ����̾���.
// ������ �ʹ� �ָ��ؼ� ���� �ɷȴ�.

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