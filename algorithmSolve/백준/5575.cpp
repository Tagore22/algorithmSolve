#include <iostream>

using namespace std;

// 퇴근 시간 - 출근 시간을 출력하는 문제.

int main()
{
    int from[3][3], to[3][3], answer[3];
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> from[i][j];
        }
        for (int j = 0; j < 3; ++j)
            cin >> to[i][j];
    }
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 2; j >= 0; --j)
        {
            if (to[i][j] < from[i][j])
            {
                --to[i][j - 1];
                to[i][j] += 60;
            }
            answer[j] = to[i][j] - from[i][j];
        }
        for (int j = 0; j < 3; ++j)
            cout << answer[j] << ' ';
        cout << '\n';
    }
    return 0;
}