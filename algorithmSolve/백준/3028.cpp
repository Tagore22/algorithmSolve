#include <iostream>

using namespace std;

bool isball[3] = { true, false, false };
int nums[3][2] = { {0, 1}, {1, 2}, {0, 2} };

void ChangeCup(int lhs, int rhs)
{
    bool temp = isball[lhs];
    isball[lhs] = isball[rhs];
    isball[rhs] = temp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string str;
    cin >> str;
    for (int i = 0; i < str.size(); ++i)
    {
        int idx = str[i] - 'A';
        ChangeCup(nums[idx][0], nums[idx][1]);
    }
    for (int i = 0; i < 3; ++i)
    {
        if (isball[i])
        {
            cout << i + 1 << '\n';
            break;
        }
    }
    return 0;
}