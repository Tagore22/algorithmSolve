#include <iostream>

using namespace std;

// 풀이.
// 어렵다기보다는 복잡했던 문제다. 3x3 문자배열이 주어질 때 올바른 배열인가
// 확인하는 문제인데 각 조건들은 다음과 같다.

// 1. o가 x보다 많을 수 없다. o가 후공이기 때문이다.
// 2. x가 o보다 둘 이상 많을 수 없다.
// 3. x와 o, 둘다 3개를 만들 수 없다. 둘 중 하나가 만든 상황에서 게임은 끝나기 때문이다.
// 4. x가 3개를 만들었을 때, o보다 한개 많아야 한다.
// 5. o가 3개를 만들었을 때, x와 개수가 동일해야한다.
// 6. 배열은 빈칸이 없고, x와 o 모두 3개씩 맞추지 못했다.

// 이런 조건들은 구현하면 된다. 상술하였듯 조건이 많아서 다 떠올리는데에 시간이 들었다.

// 자세한 설명은 주석으로 남긴다.

char board[3][3];
int xnum = 0, onum = 0;

void CheckTictacto()
{
    // 상술한 1번과 2번 조건.
    // 이 조건문에서 o가 하나 적거나, o와 x가 같은 경우만 남기는데
    // 후자를 깜빡해서 후술할 내용에서 빈틈이 생겼다.
    if (onum > xnum || xnum > onum + 1)
    {
        cout << "invalid" << '\n';
        return;
    }

    int xans = 0, oans = 0;
    for (int i = 0; i < 3; ++i)
    {
        // 각각 x와 o가 가로 혹은 세로로 3개를 만들 경우.
        if ((board[i][0] == 'X' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == 'X' && board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            ++xans;

        if ((board[i][0] == 'O' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) ||
            (board[0][i] == 'O' && board[0][i] == board[1][i] && board[1][i] == board[2][i]))
            ++oans;
    }

    // x와 o가 대각선으로 3개를 만들 경우.
    if ((board[0][0] == 'X' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[2][0] == 'X' && board[2][0] == board[1][1] && board[1][1] == board[0][2]))
        ++xans;

    if ((board[0][0] == 'O' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) ||
        (board[2][0] == 'O' && board[2][0] == board[1][1] && board[1][1] == board[0][2]))
        ++oans;

    // 3번 조건.
    if (xans > 1 && oans > 1)
    {
        cout << "invalid" << '\n';
        return;
    }

    // 4, 5, 6번 조건. 이 함수의 if문에서 상술하였듯 4번 조건에 x와 o의 개수에 대한 내용이 있다.
    // 처음에는 xnum == onum + 1을 추가하지 않았었는데 if문에서 알아서 걸러줄 거라는 생각이 들었기 때문이다.
    // 하지만 xnum == onum 혹은 xnum == onum + 1일 두가지 경우가 통과되는데 이 중 전자는 제대로 된 답이
    // 될 수 없어서 틀린 생각이다. 그러므로 반드시 xnum == onum + 1을 추가해주어야 한다.
    if ((xans > 0 && oans == 0 && xnum == onum + 1) || (oans > 0 && xans == 0 && xnum == onum) || (xans + oans == 0 && xnum + onum == 9))
        cout << "valid" << '\n';
    else
        cout << "invalid" << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true)
    {
        string str;
        cin >> str;
        if (str == "end")
            break;
        xnum = onum = 0;
        for (int i = 0; i < 9; ++i)
        {
            board[i / 3][i % 3] = str[i];
            if (str[i] == 'X')
                ++xnum;
            else if (str[i] == 'O')
                ++onum;
        }
        CheckTictacto();
    }
    return 0;
}