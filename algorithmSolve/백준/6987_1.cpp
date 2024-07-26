#include <iostream>

using namespace std;

// 6987���� ���� ���� Ǯ��.
// ���� Ǯ�̴� ������ ��� ��츦 ������ ������ ���귮�� 3�� 15�����̾���.
// ������ ������ ���� ������ - ��Ű�� ������ �ϸ� ����ġ�⸦ �� ���� �Ҽ� �ִ�.
// �� ����� ���ϸ� �ξ� �� ���� Ǯ�� �ִ�. ������ ���� Ǯ�̴� 280ms�̾�����
// �� Ǯ�̴� 0ms����.

// �ڼ��� ������ �ּ����� �����.

int w[6], d[6], l[6];
int sum;
bool isFind;

// 0���� �ö󰡴� ������ �ƴ� ���翡�� �������� �������� ��ȸ�ϴ� ��Ʈ��ŷ �Լ�.
void BackTrack(int first, int second)
{
    // first�� 0�� �Ǿ��ٴ� ���� 5���� �����ϴ� ��ȸ���� ������ ���ƴٴ� ���̹Ƿ�
    // �迭�� ��ġ���� ����.
    if (first == 6)
    {
        isFind = true;
        return;
    }

    // second�� 6�̶�� ���� first�� 5������ ��⸦ ������ �������� ���ϹǷ�
    // �������� first�� �Ǿ� ��ȸ�ؾ����� ����.
    else if (second == 6)
    {
        BackTrack(first + 1, first + 2);
    }

    // ���� first�� �����ϴ� ��ȸ�� ���� ������ �ʾ����Ƿ� ��� ��ȸ�� �ؾ����� ����.
    else
    {
        // first�� �̱� ���.
        // ����Ͽ��� 0���� ä������ ��ȸ�� �ƴ� ���簪���� �������� ��ȸ�̹Ƿ�
        // �� ���� ����ġ�⸦ �Ҽ� �ִ�.
        --w[first];
        --l[second];
        // �� if���� �ٷ� �� ����ġ���ε� �������� 0���� �۴ٸ� ������ �Ұ����� ��Ȳ�̱� �����̴�.
        if (w[first] >= 0 && l[second] >= 0)
            BackTrack(first, second + 1);
        ++w[first];
        ++l[second];

        // ��� ���.
        --d[first];
        --d[second];
        if (d[first] >= 0 && d[second] >= 0)
            BackTrack(first, second + 1);
        ++d[first];
        ++d[second];

        // second�� �̱� ���.
        --l[first];
        --w[second];
        if (l[first] >= 0 && w[second] >= 0)
            BackTrack(first, second + 1);
        ++l[first];
        ++w[second];
    }
}

void MakeAnswer()
{
    for (int iter = 0; iter < 4; ++iter)
    {
        sum = 0;
        isFind = false;
        for (int i = 0; i < 6; ++i)
        {
            cin >> w[i] >> d[i] >> l[i];
            sum += w[i] + d[i] + l[i];
        }

        // ù��° ����ġ��. ����� ���� 15ȸ�̱� ������ ��� ������� ���� ������ 30�� �Ǿ�߸� �Ѵ�.
        if (sum != 30)
        {
            cout << 0 << '\n';
            continue;
        }
        BackTrack(0, 1);
        if (isFind)
            cout << 1 << '\n';
        else
            cout << 0 << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}