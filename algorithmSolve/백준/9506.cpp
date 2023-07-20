#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �̸��� ����� ������ ������ ��������.
// �Ź� �־����� N�� ������� ��� ���� N���� �ƴ��� Ȯ���ϴ� �����ε�
// �� �״�� N�� �Ź� �޶����� ������ dp ���� ������ �������� ������.
// ���� �Ź� 1 ~ N - 1���� ��ȸ�ϸ� ��� ������� ���� ������ ���ϴ� ���ۿ� ������.
// ���� �������� �־��� ��� ���°� �ſ� �����Ҵ�. ������ ����� ������ �����ϸ� �ѹ��� Ǯ�� �ִ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> board;
int N;

// 1 ~ N - 1���� ��ȸ�ϸ� ������� ��� ���غ��� N�� ���ϴ� �Լ�.
bool MakeSum()
{
    // ������� �����ص� ���͸� �ʱ�ȭ�ؾ��Ѵ�.
    board.clear();
    int ans = 0;
    for (int i = 1; i < N; ++i)
        if (N % i == 0)
        {
            ans += i;
            // Ȥ���� ���� ������� ���� N�� �Ѿ�ٸ� �� �̻��� ��ȸ�� ���ǹ��ϹǷ� �ٷ� false�� ��ȯ�ϸ� Ż���Ѵ�.
            if (ans > N)
                return false;
            board.push_back(i);
        }
    return ans == N;
}

void MakeAnswer()
{
    while (true)
    {
        cin >> N;
        if (N == -1)
            break;

        // ���⼭ ���� ���� N�� ���Ѵ�.
        bool answer = MakeSum();

        if (answer)
        {
            cout << N << " = ";
            for (int i = 0; i < board.size() - 1; ++i)
                cout << board[i] << " + ";
            cout << board[board.size() - 1] << '\n';
        }
        else
        {
            cout << N << " is NOT perfect." << '\n';
        }
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}