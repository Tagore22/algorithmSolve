#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Ǯ��
// LIS�����̴�. �־��� ������ ��ȸ�ϸ鼭 ������ ���� ���ǽ��� �޴´�.

// 1. ������ �迭 answer�� ����ְų� answer�� ���� ū��(back()��)���� ���� board[i]���� ũ�ٸ� answer�� �ڿ� board[i]�� �ִ´�.
// 2. �׷��� �ʴٸ� board[i]�� ��ġ�� �ľ��Ͽ� ���� answer[]���� ��ü�Ѵ�.

// N���� ��ȸ�� �������� answer�ȿ� ����ִ� ���� ���� LIS�� ���� ����.

vector<int> board, answer;
int N;

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
    {
        if (answer.empty() || answer.back() < board[i])
        {
            answer.push_back(board[i]);
        }
        else
        {
            int dis = lower_bound(answer.begin(), answer.end(), board[i]) - answer.begin();
            answer[dis] = board[i];
        }
    }

    cout << answer.size() << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    board.resize(N, 0);
    for (int i = 0; i < N; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}