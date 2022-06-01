#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> board;
int n;

void MakeArray()
{
    if (n <= 1)
        return;
    vector<bool> array(n + 1, true);
    array[0] = false;
    array[1] = false;
    int SqrtNum = sqrt(n);
    for (int i = 2; i <= SqrtNum; ++i)
        if (array[i])
            for (int j = i * i; j <= n; j += i)
                array[j] = false;

    for (int i = 0; i <= n; ++i)
        if (array[i])
            board.push_back(i);
}

void Calcul()
{
    if (board.empty())
    {
        cout << 0 << '\n';
        return;
    }
    int left = 0;
    int right = 0;
    int answer = 0;
    int sum = board[0];
    while (left <= right)
    {
        if (sum == n)
        {
            ++answer;
            sum -= board[left];
            ++left;
        }
        else if (sum > n)
        {
            sum -= board[left];
            ++left;
        }
        else
        {
            ++right;
            if (right >= board.size())
                break;
            sum += board[right];
        }
    }
    cout << answer << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    MakeArray();
    Calcul();
    return 0;
}