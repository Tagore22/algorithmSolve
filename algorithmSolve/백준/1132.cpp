#include <iostream>
#include <algorithm>

using namespace std;

// Ǯ��.
// ó������ ��Ʈ��ŷ�� ����ؼ� ��� ��츦 ã�ƺþ���. ���ó� �ð��ʰ�����. �׸��� �˰����� ����ؾ� �ߴµ�
// �� ���ڿ����� �Է¹����鼭 ���ĺ��� ������ �ڸ����� üũ�Ѵ�. ���� �ڸ����� �����Ͽ� ���� ū ������ 9 ~ 0��
// �����ָ� �ȴ�. �ٸ�, ���ڿ��� ���� ��ȯ������ 0���� �����ϴ� ���� �����ϸ� �ȵǱ⿡ �� ù��°�� ������ ���ĺ�����
// 0�� �Ǹ� �ȵǱ⿡ �Է½� üũ�صξ��ٰ� �Ŀ� ���ں��� Ȯ���ؾ� �Ѵ�.

// �ڼ��� ������ �ּ����� �����.

bool isfirst[10] = { false, };
pair<long long, int> alpha[10];
int N;

void MakeAnswer()
{
    sort(alpha, alpha + 10, greater<>());
    // 0�� �����ϴ� ���� ���ĺ� 10���� ��� �����������̴�.
    // �̶� �� ������ 9��° �ε������� ������ 0���� Ŀ����.
    if (alpha[9].first != 0)
    {
        // ���� ���� ������ ��ȸ�ϸ� ù��°�� �������� ���� ���ĺ��� 0���� ��ȯ�Ѵ�.
        for (int i = 9; i >= 0; --i)
        {
            if (!isfirst[alpha[i].second])
            {
                alpha[i].first = 0;
                break;
            }
        }
    }
    long long answer = 0;
    // ���� ū ������ 9 ~ 1�� ���Ͽ� ������ ���Ѵ�.
    for (int i = 9; i >= 1; --i)
    {
        for (int j = 0; j < 10; ++j)
        {
            if (alpha[j].first == 0)
                continue;
            answer += alpha[j].first * i;
            alpha[j].first = 0;
            break;
        }
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < 10; ++i)
        alpha[i].second = i;
    string str;
    for (int i = 0; i < N; ++i)
    {
        cin >> str;
        // �� ���ڿ��� �� �� ���ĺ��� 0�� �Ǹ� �ȵǱ⿡ �̸� üũ�صд�.
        isfirst[str[0] - 'A'] = true;
        long long here = 1;
        for (int j = str.size() - 1; j >= 0; --j)
        {
            alpha[str[j] - 'A'].first += here;
            here *= 10;
        }
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}