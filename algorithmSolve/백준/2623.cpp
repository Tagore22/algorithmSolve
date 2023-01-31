#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

//���ҵ鰣�� ������ �߿��� �������� �����̴�.
//�� ���Һ��� ���� ���Ұ� �����ִ�(�ռ� �ִ� ������ ����)���� �����ϴ� link�� ����Ѵ�.
//����, ���ÿ� �ڱ� �ڽ� �ڿ����� ������ ����� 2���� �迭 seq�� �����Ѵ�.
//�� ��, BFS�� ��ȸ�ϸ� link[K]�� 0�� ������ answer�� ��Ƴ��� �Ǵµ�, ��Ƴ����� ���� ���� K�ڿ� �ִ� ��� ������ �����ִ� ������ 1�� 
//�پ���� ������ �ȵȴ�. 

//ó���� Ǯ������ ���� ���Ҽ� ���� ��찡 2,3 3,2 ���� ���ۿ� ������ �˰� seq[board[i][j]]�� board[i][iter]�� ������ ���� ��츸
//0�� ���������, �׷��� �ʰ� 1,2 2,3 3,1 ���� ��쵵 ������� �Ǿ� ���� ���Ҽ� ������.
//�� ��� ���¸� ��� �˼� �ִ� �������� ����� BFS���� link[K]�� 0�� ������ ������ answer�� ��Ƶε�, que�� ��ȸ�� ��������
//answer�� ������ Ȯ���ϴ� ���̴�. N�� �ƴ϶�� �ᱹ ���� ���Ҽ� �������Ƿ� 0�� ����ϸ� �ȴ�.

vector<vector<int>> board, seq;
vector<int> link;
int N, M;

void MakeSeq()
{
    seq.resize(N + 1, vector<int>());
    link.resize(N + 1, 0);

    for (int i = 0; i < board.size(); ++i)
    {
        if (board[i].size() >= 2)
            for (int j = 1; j < board[i].size(); ++j)
                for (int iter = 0; iter < j; ++iter)
                {
                    seq[board[i][iter]].push_back(board[i][j]);
                    ++link[board[i][j]];
                }
    }
}

void BFS()
{
    queue<int> que;
    vector<int> answer;

    for (int i = 1; i <= N; ++i)
        if (link[i] == 0)
            que.push(i);

    while (!que.empty())
    {
        int here = que.front();
        que.pop();

        for (int i = 0; i < seq[here].size(); ++i)
        {
            int there = seq[here][i];
            --link[there];
            if (link[there] == 0)
                que.push(there);
        }
        answer.push_back(here);
    }
    if (answer.size() != N)
        cout << 0 << '\n';
    else
        for (int i = 0; i < answer.size(); ++i)
            cout << answer[i] << '\n';
}

void MakeAnswer()
{
    MakeSeq();
    BFS();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    board.resize(M, vector<int>());

    int t, num;
    for (int i = 0; i < M; ++i)
    {
        cin >> t;
        for (int j = 0; j < t; ++j)
        {
            cin >> num;
            board[i].push_back(num);
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}