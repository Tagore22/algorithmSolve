#include <iostream>
#include <vector>

using namespace std;

// Ǯ��.
// �����س��� ���� �������� �����س��� ���ؼ� ��ư� Ǯ���� ������. ó������ ���� �������� ��ȸ�� �ߴ�.
// �翬�� que�� �ʹ� ���� ������ ����Ǿ� �޸� �ʰ��� ����. ������ ������ ��ȸ�ϴ� ���̴�. ���ø� �ߺ���
// �� ������ ����� ���� �ö󰡸鼭 �� ������ �������� ���� ��ȣ ����� �����Ҽ� �ִ�. �̰��� ��Ʈ��ŷ������
// �����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

vector<int> vec;
char board[10][10];
int N;
string str;

// ���� �� ���� �ùٸ��� Ȯ���ϴ� �Լ�.
bool CheckTrack(int idx)
{
    int sum = 0;

    // �� ������ ����� �ö󰡸� �Ǵ� �� �� ���ں��� ������ ��ȸ�ϸ� ��ȣ ��İ� ���� ���� ��ġ���� Ȯ���Ѵ�.
    for (int i = idx; i >= 0; --i)
    {
        // ���� i�� ������� ��.
        sum += vec[i];

        // ���� ��ȣ�� ���� �ٸ��ٸ� false�� ��ȯ�Ͽ� ���� ������ �˸���.
        if (board[i][idx] == '+' && sum <= 0)
            return false;
        if (board[i][idx] == '-' && sum >= 0)
            return false;
        if (board[i][idx] == '0' && sum != 0)
            return false;
    }
    // ���������� ��ȸ�� ���� �����Ͽ����� true�� ��ȯ�Ͽ� �˸���.
    return true;
}

// ��� ��츦 Ȯ���ϴ� ��Ʈ��ŷ �Լ�.
void BackTrack(int idx)
{
    // ���������� �����Ͽ��ٸ� ���Ϳ� �� ������ ����ϰ� ���α׷��� �����Ѵ�.
    if (idx == N)
    {
        for (auto& num : vec)
            cout << num << ' ';
        cout << '\n';
        exit(0);
    }

    // ��� ���� ������ -10 ~ 10���� ��ȸ�غ���.
    for (int i = -10; i <= 10; ++i)
    {
        // �ݵ�� ���⼭ ���� ���Ϳ� �־�� �Ѵ�. �׷��� �ٷ� �Ʒ� CheckTrack()�� ���簪�� �ݿ��Ǳ� �����̴�.
        vec.push_back(i);
        if (CheckTrack(idx))
            BackTrack(idx + 1);
        // ���簪�� ������ ���������� �ǵ�����.
        vec.pop_back();
    }
}

void MakeAnswer()
{
    BackTrack(0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> str;
    int idx = -1;
    for (int i = 0; i < N; ++i)
        for (int j = i; j < N; ++j)
            board[i][j] = str[++idx];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}