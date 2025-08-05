#include <iostream>
#include <cmath>

using namespace std;

// Ǯ��.
// �� �̵��� ���μ��� �� 2ĭ, 1ĭ�� ������ ����Ʈ�� �̵��� �´��� Ȯ���ϰ�
// �� ĭ�� �� �ѹ����� �湮�ߴ���, ������ �̵����� ���������� ���ƿ� �� �ִ��� ��
// Ȯ���Ұ� ���� �������⿡ �ڵ尡 �ϳ� �������.

// �ڼ��� ������ �ּ����� �����.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string prev = "", str;
    bool isanswer = true;
    bool visit[6][6] = { false, };
    for (int iter = 0; iter < 36; ++iter)
    {
        string cur;
        cin >> cur;

        // ���� ��ġ�� ��ǥ���� ���.
        int firstidx = cur[0] - 'A';
        int secondidx = cur[1] - '1';
        if (prev == "")
        {
            prev = cur;
            str = prev;
            visit[firstidx][secondidx] = true;
            continue;
        }

        // ����, ������ �̵�ĭ ���.
        int first = abs(cur[0] - prev[0]);
        int second = abs(cur[1] - prev[1]);
        // ����Ʈ�� �������� �´���, �ߺ� �湮�ߴ��� Ȯ��.
        if (!((first == 2 && second == 1) || (first == 1 && second == 2)) ||
            visit[firstidx][secondidx])
            isanswer = false;

        // �������� ��ü�ϰ� �湮 ���θ� �����Ѵ�.
        prev = cur;
        visit[firstidx][secondidx] = true;
    }
    // �� ������ �������� ���� �������� �ǵ��ƿ� �� �ִ��� Ȯ��.
    int first = abs(str[0] - prev[0]);
    int second = abs(str[1] - prev[1]);
    if (!((first == 2 && second == 1) || (first == 1 && second == 2)))
        isanswer = false;
    cout << (isanswer ? "Valid" : "Invalid") << '\n';
    return 0;
}