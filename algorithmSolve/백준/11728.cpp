#include <iostream>
#include <string>

using namespace std;

// Ǯ��.
// ���ĵ� �� �迭�� ���ĵ� ���·� ��ġ�� ������.
// ó������ �� �迭�� �Է»��º��� ���ļ� �ٽ� �����ߴµ� �׷��� ���� ������ �ѹ� ���ؾ��ߴ�.
// �� Ǯ�̴� �� �迭�� �Է¹��� ���¿��� ������ ���� �ʰ� A�� B���� ���� ������ �� ���� ���Ҹ�
// ������ answer�� �߰��ϴ� ����̴�. ����, �������� �� Ǯ��ó�� string�� ������� �ʰ�
// �迭�� ����Ͽ��µ� �װ� �ξ� ���ȴ�. ��������� �ϳ��� ������ ������ string answer�� �߰��Ͽ�
// ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int board_A[1000000], board_B[1000000];
string answer;
int N, M;

void MakeAnswer()
{
    int idx_A = 0, idx_B = 0, idx = 0;
    // �� N + M����ŭ ������ answer�� �߰��Ѵ�.
    for (int iter = 0; iter < N + M; ++iter)
    {
        // A�� ��� ���Ҹ� �߰��Ͽ� N��°�� ����Ű�� �ִٸ�
        // ���̻� A�� ���� �ʿ䵵 ����.
        if (idx_A == N)
        {
            answer += to_string(board_B[idx_B]) + " ";
            ++idx_B;
        }
        // B�� ��� ���Ҹ� �߰��Ͽ� M��°�� ����Ű�� �ִٸ�
        // ���̻� B�� ���� �ʿ䵵 ����.
        else if (idx_B == M)
        {
            answer += to_string(board_A[idx_A]) + " ";
            ++idx_A;
        }
        // �Ѵ� ���� ���� �������� �ʾҴٸ� �� �迭�� ���� ���Ҹ�
        // ���Ѵ�.
        else
        {
            // A�� ���Ұ� �� �۴ٸ� �߰��Ѵ�.
            if (board_A[idx_A] > board_B[idx_B])
            {
                answer += to_string(board_B[idx_B]) + " ";
                ++idx_B;
            }
            // B�� ���Ұ� �� �۴ٸ� �߰��Ѵ�.
            else
            {
                answer += to_string(board_A[idx_A]) + " ";
                ++idx_A;
            }
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        cin >> board_A[i];
    for (int i = 0; i < M; ++i)
        cin >> board_B[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}