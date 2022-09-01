#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int N;
pair<int, int> board[10000];

//1781���� �ſ� ����� �����̴�. Ǯ�̱��� �Ȱ����� ���� �ٸ����̶�� �̹������� day��� ������ ���ؼ� ������ ��¥��
//������ ������ Ǯ������, 1781�������� ť�� ũ��� ��ü�ߴٴ� ���̴�. ������ day�� ���������� ť�� ���ԵǴ� ù��°
//if�������� �����ؾ� ������ �Ѵ� �ٸ��ٰ� ���ٴ� ���̴�.

void MakeAnswer() //d, p ��
{
    priority_queue<int> que;
    int day = 0;
    sort(board, board + N);
    for (int i = 0; i < N; ++i)
    {
        if (board[i].first > day)
        {
            que.push(-board[i].second);
            ++day;
        }
        else
        {
            if (board[i].second > -que.top())
            {
                que.pop();
                que.push(-board[i].second);
            }
        }
    }
    int answer = 0;
    while (!que.empty())
    {
        answer += -que.top();
        que.pop();
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        cin >> board[i].second;
        cin >> board[i].first;
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}