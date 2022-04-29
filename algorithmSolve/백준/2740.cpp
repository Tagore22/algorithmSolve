#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> boardA;
vector<vector<int>> boardB;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int aN, aM, bN, bM;
    cin >> aN >> aM;
    boardA.assign(aN, vector<int>(aM, 0));
    for (int i = 0; i < aN; ++i)
        for (int j = 0; j < aM; ++j)
            cin >> boardA[i][j];
    cin >> bN >> bM;
    boardB.assign(bN, vector<int>(bM, 0));
    for (int i = 0; i < bN; ++i)
        for (int j = 0; j < bM; ++j)
            cin >> boardB[i][j];
    for (int k = 0; k < aN; ++k)
    {
        for (int i = 0; i < bM; ++i)
        {
            int answer = 0;
            for (int j = 0; j < aM; ++j)
                answer += boardA[k][j] * boardB[j][i];
            cout << answer << ' ';
        }
        cout << '\n';
    }
    return 0;
}