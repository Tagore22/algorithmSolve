#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

//here부터 인덱스를 증가해가며 각 건물과의 기울기를 계산한다.
//기울기가 기존에 저장된 최대 기울기값보다 크다면 그 건물은 보이며
//최대 기울기를 갱신한다.

using namespace std;

vector<vector<bool>> check;
vector<int> board;
int n;
int answer = 0;

double CalculSlope(int here, int there)
{
    if (board[there] == board[here])
        return 0;
    return static_cast<double>(board[there] - board[here]) / static_cast<double>(there - here);
}

void Calcul(int here)//0일때와 size -1 일때 추가할것.
{
    int ans = 0;
    for (int i = 0; i < here; ++i)
        if (check[i][here])
            ++ans;

    if (here < n - 1)
    {
        double MaxS = numeric_limits<double>::lowest();//::min()은 양수중 최저값, ::lowest는 음수중 최저값
        for (int i = here + 1; i < n; ++i)
        {
            double slope = CalculSlope(here, i);
            if (slope > MaxS)
            {
                ++ans;
                MaxS = slope;
                check[here][i] = true;
            }
        }
    }
    answer = max(answer, ans);
}

void ShowAnswer()
{
    check.assign(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i)
        Calcul(i);
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        board.push_back(a);
    }
    ShowAnswer();
    return 0;
}