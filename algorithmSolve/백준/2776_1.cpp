#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2776���� �� ���� Ǯ��.
// �迭�� Ư�� ������ �����ϴ����� Ȯ���ϰ� ���������� ���⿡ ���� set�� ������� �ʰ�
// �迭�� ũ�⸸ŭ ��ȸ���� �ʾƵ� �̺� Ž���� Ȱ���ϸ� �� ������ �����Ҽ� �ִ�.
// ���� lower_bound Ȥ�� upper_bound�� �̿��ϸ� �Ǵµ� �ӵ��� ����ϱ⿡ �ƹ��ų� ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> board;
int T, N, M;

void MakeAnswer()
{
    for (int k = 0; k < T; ++k)
    {
        // �Ź� �迭�� ���ų� �ʱ�ȭ�ؾ��ϱ⿡ �׳� vector�� ����Ͽ���.
        board.clear();
        cin >> N;
        int num;
        for (int i = 0; i < N; ++i)
        {
            cin >> num;
            board.push_back(num);
        }
        // lower_bound Ȥ�� upper_bound�� ����ϱ� ���� ����.
        sort(board.begin(), board.end());
        cin >> M;
        for (int i = 0; i < M; ++i)
        {
            cin >> num;
            // ���� ���� num�� ���ų� �� ū ���� ���� ���� ��ġ�� ã�´�.
            auto iter = lower_bound(board.begin(), board.end(), num);
            // �׷� ���� �������� �ʾƼ� ��ġ�� board.end()��� 0�� ����ϰ� for���� �ݺ��Ѵ�.
            if (iter == board.end())
            {
                cout << 0 << '\n';
                continue;
            }
            // �����Ѵٸ� �� ���� num�� ���ٸ� 1�� �׷��� �ʴٸ� 0�� ����Ѵ�.
            cout << (*iter == num ? 1 : 0) << '\n';
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