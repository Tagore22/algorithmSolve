#include <iostream>
#include <vector>

using namespace std;

int n, m;
vector<int> board;
vector<vector<int>> isP;

void calcul()
{
    for (int i = 0; i < n; ++i)
        isP[i][i] = 1;
    for (int i = 0; i < n - 1; ++i)
        if (board[i] == board[i + 1])
            isP[i][i + 1] = 1;
    for (int i = 2; i < n; ++i)
        for (int j = 0; j < n - i; ++j)
        {
            if (isP[j + 1][i + j - 1] == 1 && (board[j] == board[i + j]))
                isP[j][i + j] = 1;
        }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    board.assign(n, 0);
    isP.assign(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        cin >> board[i];
    calcul();
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        cout << isP[a - 1][b - 1] << '\n';
    }
    return 0;
}