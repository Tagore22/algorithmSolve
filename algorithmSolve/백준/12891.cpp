#include <iostream>

using namespace std;

// Ǯ��.
// ���̰� S�� ���ڿ��� ������ ���̰� P�� �κй��ڿ����� A, C, G, T�� ����Ƚ���� �����ϴ� �κй��ڿ��� ������ ����ϴ� ������.
// ó������ ���̰� P�� ��� �κй��ڿ��� ��ȸ�ϵ�, ����ġ��� ���귮�� ���̷��� ������ �׷��� �ð��ʰ��� ����.
// ��¥ Ǯ�̴� 0��°���� P - 1���� ���ڱ��� Ȯ���� �տ��� �Ѱ��� ���� �ڿ��� �Ѱ��� �ִ� ����̾���.
// �׷��� �ϸ� 100������ ���귮�ȿ� ������ ���� Ȯ���ȴ�. �ٸ� �� ���Ŀ� ��Ǯ����� �Ѱ��� �Ǽ��� �ߴµ�
// �̴� ���� �ļ��Ѵ�.

// �ڼ��� ������ �ּ����� �����.

int S, P, A, C, G, T;
string str;

void MakeAnswer()
{
    // ������ answer�� �� A, C, G, T�� ������ 0���� �ʱ�ȭ�Ѵ�.
    int answer = 0, a_num = 0, c_num = 0, g_num = 0, t_num = 0;
    // ���� 0 ~ P - 1��° ���ڸ� Ȯ���Ѵ�.
    for (int i = 0; i < P; ++i)
    {
        if (str[i] == 'A')
            ++a_num;
        else if (str[i] == 'C')
            ++c_num;
        else if (str[i] == 'G')
            ++g_num;
        else if (str[i] == 'T')
            ++t_num;

        // ������ �Ʒ� if���� ���⿡ �־���. �ʹ� �����ϰ� ����������
        // ���⿡ �����ϸ� ���� ���� P�� �κй��ڿ��� ���������� answer�� 1 �ʰ��� ����
        // ��Ÿ���� �ִ�. ���� ��� �Է��� 4, 2, AAAA, 1, 0, 0, 0�϶�
        // �Ʒ� if���� ���⿡ �ִٸ� �� ó�� AA������ �˻������� �ⲯ�ؾ� answer�� 1�̿��� ������
        // �����δ� ���� 2���� ���ڰ� ��� 1, 0, 0, 0�� �������� answer�� 2�� �Ǿ� Ʋ���� �ȴ�.
    }

    // ���� P���� ���� Ȯ���� answer�� �����Ѵ�.
    if (a_num >= A && c_num >= C && g_num >= G && t_num >= T)
        ++answer;

    // �Ǿ� ���ڸ� �����ϰ� �ڿ� �ϳ��� �߰��س����� ��ȸ�� �Ѵ�.
    for (int i = P; i < S; ++i)
    {
        // �Ǿ� ���ڸ� �����.
        if (str[i - P] == 'A')
            --a_num;
        else if (str[i - P] == 'C')
            --c_num;
        else if (str[i - P] == 'G')
            --g_num;
        else if (str[i - P] == 'T')
            --t_num;

        // �ǵڿ� ���ڸ� �߰��Ѵ�.
        if (str[i] == 'A')
            ++a_num;
        else if (str[i] == 'C')
            ++c_num;
        else if (str[i] == 'G')
            ++g_num;
        else if (str[i] == 'T')
            ++t_num;

        // �̹� �߰��� ���� �����ϴ��� Ȯ���Ѵ�.
        if (a_num >= A && c_num >= C && g_num >= G && t_num >= T)
            ++answer;
    }

    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S >> P >> str >> A >> C >> G >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}