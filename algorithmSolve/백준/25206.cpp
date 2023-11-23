#include <iostream>
#include <map>

using namespace std;

// Ǯ��.
// ���� * ������������ ���� ������ �������� ���� ������� ����ϴ� ������.
// �� ����(String)���� ��������(float)�� �پ��־����Ƿ� map�� �̿��ؼ� �����ؾ��ߴ�.
// �� �ķδ� ����Ѵ�� ���� * ������������ ���հ� ������ ������ ������ ����ϸ� �ȴ�.

// �ڼ��� ������ �ּ����� �����.

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    // ���������� ������ �����Ѵ�.
    map<string, float> board;
    board["A+"] = 4.5;
    board["A0"] = 4.0;
    board["B+"] = 3.5;
    board["B0"] = 3.0;
    board["C+"] = 2.5;
    board["C0"] = 2.0;
    board["D+"] = 1.5;
    board["D0"] = 1.0;
    board["F"] = 0.0;

    int sum = 0;
    float mulsum = 0.0, point;
    string str, grade;
    for (int iter = 0; iter < 20; ++iter)
    {
        // �����, ����, ����� �Է¹޴´�.
        cin >> str >> point >> grade;
        // �������� ���õǾ� �ֵ��� ����� P��� �����Ѵ�.
        if (grade == "P")
            continue;
        // ������ ���� * ���������� ���� �����ش�.
        sum += point;
        mulsum += board[grade] * point;
    }
    // ���� * ������������ �հ� �������� ���� ������ ����Ѵ�.
    cout << mulsum / sum << '\n';
    return 0;
}