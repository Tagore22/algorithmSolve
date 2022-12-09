#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//���ı����� �߸���� ���� �ظ̴�. ���������� T^T

//Ǯ��
//ó���� �ڽ����� ������������ �����ϰ� ������ �̿��Ͽ� �տ��� ���� �Ѱ��� �ű�� ���� �����ߴµ� 
//�� �ݷʰ� 3 6 8 9 6 2 4 4 9 9 ����. ���� ���ſ� ���� 9�ϳ��ۿ� �� �ű�⿡ ���� 2�� �ƴ� 3�� ���Ծ���.
//���� ������ �ڽ����� �ű�� �׸���� ������ �� ũ������ ���� �ű�� �ִ� �ڽ��� ���� ���ſ� �ڽ������ �ű�� ���̴�.
//�׷��⿡ �� �迭�� ��� ������������ �����Ͽ� ���� �ִ밪�� ���Ͽ� ���� ��Ȳ�� �����ϰ�, ����ߵ��� ũ���ο��� ���� �ű�� �ִ�
//���� ���ſ� �ڽ��� �ű��. ũ���ε��� ��ȸ�� �ѹ� ������ ���� ���� answer�� 1�� �ű�� ��� ��ȸ�� ������ ����Ѵ�.

vector<int> cranes;
vector<int> board;
int N, M;

void MakeAnswer()
{
    sort(board.begin(), board.end(), greater<>());
    sort(cranes.begin(), cranes.end(), greater<>());

    if (board[0] > cranes[0])
    {
        cout << -1 << '\n';
        return;
    }

    int answer = 0;
    while (!board.empty())
    {
        for (int i = 0; i < N; ++i)
        {
            if (board.empty())
                break;
            for (int j = 0; j < board.size(); ++j)
                if (cranes[i] >= board[j])
                {
                    board.erase(board.begin() + j);
                    break;
                }
        }
        ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        cranes.push_back(num);
    }

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        cin >> num;
        board.push_back(num);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}