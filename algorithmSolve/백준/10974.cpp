#include <iostream>
#include <cstring>

using namespace std;

// Ǯ��.
// ��Ʈ��ŷ�� ����Ͽ� ����� �ִ� ��� ������ ����� �����̴�.
// bool �迭�� �̿��Ͽ� ���� ���Ұ� ������ ���Ǿ����� Ȯ���ذ��� ��� ���ҵ���
// ��ȸ�ϸ� �ȴ�.

// �ӵ��� ���� �������� ���� �ʾ� �ٸ� Ǯ�̵��� Ȯ���غ��Ҵµ�
// �Ȱ����� �ӵ��� 4, 28 �̷��Գ� ���̰� ����. Ǯ�̸� �ƿ� ���� �ٿ��ֱ�� �ص� 
// ���̰� ����. ������ ���� ����� ���̳��� �� ����. ���� ��û ũ�� �ʴٸ�
// �Ű澲�� ����.

// �ڼ��� ������ �ּ����� �����.

int answer[8];
bool check[8];
int N;

// ��Ʈ��ŷ���� ��� ����� ��ȸ�ϴ� �Լ�.
void BackTrack(int idx)
{
    // N - 1���� ���Ұ��� ��� ��Ҵٸ� ���� ������ ������� Ż���Ѵ�.
    if (idx == N)
    {
        for (int i = 0; i < N; ++i)
            cout << answer[i] << ' ';
        cout << '\n';
        return;
    }

    // ��� ���Ұ��� ������������ ��ȸ�ϸ� ���� ������� ���� ���ҵ��� 
    // ������ ���Խ��ѳ�����.
    for (int i = 1; i <= N; ++i)
    {
        if (check[i - 1])
            continue;

        check[i - 1] = true;
        answer[idx] = i;
        BackTrack(idx + 1);
        check[i - 1] = false;
    }
}

void MakeAnswer()
{
    memset(check, false, sizeof(check));
    BackTrack(0);
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}