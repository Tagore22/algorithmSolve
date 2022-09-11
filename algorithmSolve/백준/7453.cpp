#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//4개의 배열을 임의의 2개의 배열로 나누어 각 합을 모아둔 후, lower_bound, upper_bound를 이용하여 
//2값의 합이 0인지를 로그시간복잡도로 찾아낸다. 2개의 배열로 나눌때 A와 B는 모든 경우의 수를 다 보았고,
//lower_bound, upper_bound를 이용할때 A와 B의 모든 경우 x C와 D의 모든 경우의 수를 다보게 된다.

vector<int> first_array, second_array;
int board[4][4000];
int N;

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            first_array.push_back(board[0][i] + board[1][j]);
            second_array.push_back(board[2][i] + board[3][j]);
        }
    sort(first_array.begin(), first_array.end());
    sort(second_array.begin(), second_array.end());

    long long answer = 0;
    for (int i = 0; i < first_array.size(); ++i)
    {
        int from = lower_bound(second_array.cbegin(), second_array.cend(), -first_array[i]) - second_array.cbegin();
        int to = upper_bound(second_array.cbegin(), second_array.cend(), -first_array[i]) - second_array.cbegin();

        answer += to - from;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < 4; ++j)
            cin >> board[j][i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}