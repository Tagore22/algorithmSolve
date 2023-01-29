#include <iostream>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

//Ǯ��
//�־����� ���ۼ� from���� ������ to���� �ڸ��� 4���� �ϳ��� �ٲ㳪����. �ٸ�, �̹� �����ߴ� ���� �����ϴ� ��쿡�� ���ѷ����� ��찡 �Ǳ⿡
//���� bool�迭�� �����ذ��� ������ �����Ѵ�.

bool board[10000], check[10000];
int T, from, to;

void Era() //�����佺�׳׽��� ü.
{
    board[0] = board[1] = false;
    for (int i = 2; i <= 100; ++i)
        if (board[i])
        {
            for (int j = i * i; j <= 9999; j += i)
                board[j] = false;
        }
}

void BFS()
{
    memset(check, false, sizeof(check)); //�׽�Ʈ���̽��� �������� �̰����� �Ź� �湮�� ���� ���θ� �ʱ�ȭ���־���Ѵ�.
    queue<pair<int, int>> que;
    que.push(make_pair(from, 0)); //�ʱⰪ�� �������� 0(������ Ƚ��).
    check[from] = true;
    while (!que.empty())
    {
        int now = que.front().first;
        int num = que.front().second;
        que.pop();

        if (now == to)
        {
            cout << num << '\n';
            return;
        }

        for (int i = 0; i < 4; ++i)       //�ڸ��� 4���� �ϳ��� 0~9�� �ٲپ��ش�. ����� ���� �̹� �����߰ų�, 1000~9999�� ������ ����ų�,
            for (int j = 0; j < 10; ++j)  //�Ҽ��� �ƴ϶�� �����ϰ� �� �̿ܿ��� ť�� �ִ´�.
            {
                string str = to_string(now);
                str[i] = j + '0';
                int next = stoi(str);

                if (check[next] || !board[next] || next < 1000 || 10000 <= next)
                    continue;

                check[next] = true;
                que.push(make_pair(next, num + 1));
            }
    }
    cout << "Impossible" << '\n';
}

void MakeAnswer()
{
    Era();
    for (int i = 0; i < T; ++i)
    {
        cin >> from >> to;
        BFS();
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(board, true, sizeof(board));

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}