#include <iostream>

using namespace std;

// Ǯ��.
// ���� ��ȭ�İ����� �ִ°� ������ �� �𸣰ھ��⿡
// �׳� �� ��츶�� ���ǽ��� �ɾ�Ǯ����.

int quad[2][4];

char Check()
{
    if ((quad[0][1] == quad[1][3] && quad[0][2] == quad[1][0]) ||
        (quad[0][2] == quad[1][0] && quad[0][3] == quad[1][1]) ||
        (quad[0][0] == quad[1][2] && quad[0][3] == quad[1][1]) ||
        (quad[0][0] == quad[1][2] && quad[0][1] == quad[1][3]))
        return 'c';

    else if ((quad[0][1] == quad[1][3] && quad[1][0] < quad[0][2] && quad[1][2] > quad[0][0])
        || (quad[0][2] == quad[1][0] && quad[1][3] > quad[0][1] && quad[1][1] < quad[0][3])
        || (quad[0][3] == quad[1][1] && quad[1][0] < quad[0][2] && quad[1][2] > quad[0][0])
        || (quad[0][0] == quad[1][2] && quad[1][3] > quad[0][1] && quad[1][1] < quad[0][3]))
        return 'b';

    else if (quad[0][2] < quad[1][0] || quad[0][3] < quad[1][1] ||
        quad[0][0] > quad[1][2] || quad[0][1] > quad[1][3])
        return 'd';

    else
        return 'a';
}

void MakeAnswer()
{
    for (int iter = 0; iter < 4; ++iter)
    {
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 4; ++j)
                cin >> quad[i][j];
        char answer = Check();
        cout << answer << '\n';
    }
}

void Init()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

int main()
{
    Init();
    MakeAnswer();
    return 0;
}