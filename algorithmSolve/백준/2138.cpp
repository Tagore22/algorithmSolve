#include <iostream>

using namespace std;

// Ǯ��.
// ���� �ƽ����� ������. idx�� ���ؼ� idx + 1��° ����ġ�� �ǵ帮�°� ���� �˾����� 0�� ����ġ�� ����
// �޶����⿡ ���� ����� Ǫ�°� ������. �������� 37�ۿ� �ش��ϴ� �ϳ� ������� ������ �׷�����.
// ���� ���� ������ ����. �׷��� �������� ���� ���ݾ��̳��� ���ư���.

// �ڼ��� ������ �ּ����� �����.

int N, answer = 987654321;
string from, to, temp;

// idx��° ����ġ�� ������ �Լ�.
void PushSwit(int idx)
{
    // idx��° ���ڰ� ��������.
    temp[idx] = temp[idx] == '0' ? '1' : '0';
    // 0���� ũ�ٸ� �ٷ� �� ���ڵ� ��������.
    if (idx > 0)
        temp[idx - 1] = temp[idx - 1] == '0' ? '1' : '0';
    // N - 1���� �۴ٸ� �ٷ� �� ���ڵ� ��������.
    if (idx < N - 1)
        temp[idx + 1] = temp[idx + 1] == '0' ? '1' : '0';
}

// ��� ���ڿ����� ��ȸ�Ͽ� �ּҰ��� ���ϴ� �Լ�. �ٸ� �� �� ����ġ�� �������� �ȴ������Ŀ�
// ���� ������.
void CalMin(bool IsFirst)
{
    temp = from;
    int ans = 0;
    // �� �� ����ġ�� �����ٰ� �����Ѵ�. ���� �տ��� 2���� ���ڰ� �������� ����ġ�� ���� ���� 1 �����Ѵ�.
    if (IsFirst)
    {
        ++ans;
        temp[0] = temp[0] == '0' ? '1' : '0';
        temp[1] = temp[1] == '0' ? '1' : '0';
    }

    // �� �ڷ� ���ڿ��� ��ȸ�Ͽ� ���� ���ڰ� �ٸ��ٸ� �� ���� ����ġ�� ��������.
    for (int i = 1; i < N; ++i)
    {
        if (temp[i - 1] != to[i - 1])
        {
            PushSwit(i);
            ++ans;
        }
    }
    // ���ڿ��� �����ϴٸ� ���� ����ġ�� �������� �������� ���غ���.
    if (temp == to)
        answer = min(answer, ans);
}

void MakeAnswer()
{
    CalMin(false);
    CalMin(true);
    answer = answer == 987654321 ? -1 : answer;
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> from >> to;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}