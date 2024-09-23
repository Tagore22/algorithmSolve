#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �״��� ����� ������ �ƴϾ���. 2���� �κ����� ������� �ߴµ� ������ ����.
// 1. ��ĭ���� 3���� ��� O�� ä��� �Լ�.
// 2. 3���� O�� ã������ �� �������� �þ߸� Ȯ���ϴ� �Լ�.

// N��ü�� �ϴ� �۱� ������ ���� �δ㵵 ������ ������. ����, �� ĭ�� Ȯ���Ҷ�
// ��� ���� �ƴ� �ϳ��� ���� N���� ����Ͽ� �����ߴ��� ���Ҵ��� ����.

// �ڼ��� ������ �ּ����� �����.

char board[6][6];
vector<int> teacher;
int N;

// 3���� O�� ������� �� �������� �þ߸� Ȯ���ϴ� �Լ�.
bool CheckSight()
{
    // ��� �������� ��ȸ�Ѵ�.
    for (auto& t : teacher)
    {
        // ����Ͽ��� �ϳ��� �ε������� N���� ����Ͽ� ��� ���� �˾Ƴ��� �ִ�.
        int y = t / N;
        int x = t % N;

        // �Ʒ��� �þ� Ȯ��.
        for (int i = y; i < N; ++i)
        {
            // ���� ��ֹ��� �����Ѵٸ� ���̻� Ȯ���� �ʿ䰡 ����.
            if (board[i][x] == 'O')
                break;
            // Ȥ�� �л��� �߰��ߴٸ� false�� ��ȯ�Ͽ� ���и� �˸���.
            else if (board[i][x] == 'S')
                return false;
        }
        // ���� �þ� Ȯ��.
        for (int i = y; i >= 0; --i)
        {
            if (board[i][x] == 'O')
                break;
            else if (board[i][x] == 'S')
                return false;
        }
        // ������ �þ� Ȯ��.
        for (int i = x; i < N; ++i)
        {
            if (board[y][i] == 'O')
                break;
            else if (board[y][i] == 'S')
                return false;
        }
        // ���� �þ� Ȯ��.
        for (int i = x; i >= 0; --i)
        {
            if (board[y][i] == 'O')
                break;
            else if (board[y][i] == 'S')
                return false;
        }
    }
    // ������� �����ߴٸ� ������ �þ߿��� ���̻� �л��� �߰ߵ��� �ʾҴ�.
    return true;
}

// 3���� O�� ã�� ��� ��츦 ã�� �Լ�.
void FindO(int idx, int num)
{
    // 3���� O�� �߰��ߴٸ� �� ���¿��� ��� �������� �þ߸� ������ �ִ��� Ȯ���غ���.
    if (num == 3)
    {
        // ������ �ִٸ� YES�� ����� ���α׷��� �����Ѵ�.
        if (CheckSight())
        {
            cout << "YES" << '\n';
            exit(0);
        }
        // �׷��� �ʴٸ� Ż���Ͽ� �ٸ� ��츦 ã�´�.
        return;
    }

    // ���� ��ġ���� ��� ĭ�� ��ȸ�ϸ� Ȯ���Ѵ�.
    for (int i = idx; i < N * N; ++i)
    {
        int y = i / N;
        int x = i % N;
        if (board[y][x] == 'X')
        {
            // ã�� ��ĭ�� O�� ä��� ���ȣ���Ѵ�.
            board[y][x] = 'O';
            FindO(i, num + 1);
            // �ݵ�� ������� �������Ѿ��Ѵ�.
            board[y][x] = 'X';
        }
    }
}

void MakeAnswer()
{
    FindO(0, 0);
    // FindO()���� ��� ��츦 ã�ƺôµ��� ã�� ���ߴٸ�
    // �� � ��쿡�� �Ұ����ϱ⿡ NO�� ����Ѵ�.
    cout << "NO" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'T')
                teacher.push_back(i * N + j);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}