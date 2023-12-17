#include <iostream>
#include <set>

using namespace std;

// Ǯ��.
// ���� �������� ����� �迭���� Ư�� ������ �����ϴ��� ã�� �����̴�.
// Ư�� ������ ã�� ���̱⿡ �ߺ��Ǵ� ������ �����Ƿ� multiset�� �ƴ� set�� ����Ͽ���.
// set�ȿ� �ش� ������ �����Ѵٸ� 1��, �������� �ʴ´ٸ� 0�� ����ϸ� �ȴ�.
// �ٸ� �ڵ�� ª���� ���� �����̳ʸ� ����ϱ� ������ ������ ������.

// �ڼ��� ������ �ּ����� �����.

set<int> board;
int T, N, M;

void MakeAnswer()
{
    for (int k = 0; k < T; ++k)
    {
        // �� �׽�Ʈ ���̽����� ����־� �Ѵ�.
        board.clear();
        cin >> N;
        int num;
        // N���� ������ set�� �����Ѵ�.
        for (int i = 0; i < N; ++i)
        {
            cin >> num;
            board.insert(num);
        }
        cin >> M;
        // M���� ��ȸ.
        for (int i = 0; i < M; ++i)
        {
            cin >> num;
            // �ش� ������ �����Ѵٸ� 1��, �������� ������ 0�� ����Ѵ�.
            cout << (board.find(num) != board.end() ? 1 : 0) << '\n';
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