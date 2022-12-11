#include <iostream>
#include <vector>
#include <algorithm>

//풀이
//처음에는 주어진 S만큼 앞에서 부터 내림차순을 하는 것으로 생각했는데 너무 간단했으며, 답도 맞지 않았다.
//진짜 풀이는 맨 첫번째 원소부터 배열을 순회하며 주어진 S보다 같거나 적게 이동해서 i번째 원소로 이동 가능한
//가장 큰 원소를 찾아가며 이동시키는 것이다.
//즉, 첫번째 원소 값은 2번째 원소부터 순회하며 S번안에 첫번째 원소로 이동 가능한 가장 큰 원소를 찾아 첫번째 원소로 두고
//이것을 맨 마지막 원소까지 반복하는 것이다.

using namespace std;

vector<int> board;
int N, S;

void MakeAnswer()
{
    for (int i = 0; i < N; ++i)
    {
        int max_num = board[i]; //현재 가장 큰 원소
        int max_idx = i;        //가장 큰 원소의 인덱스값

        for (int j = i + 1; j < N; ++j)
            if (max_num < board[j] && j - i <= S) //i번째 원소까지 이동가능한 원소중 가장 큰값을 찾는다.
            {
                max_num = board[j];
                max_idx = j;
            }

        S -= max_idx - i;
        board.erase(board.begin() + max_idx);
        board.insert(board.begin() + i, max_num);

        if (S == 0)
            break;
    }

    for (auto& a : board)
        cout << a << ' ';
    cout << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num;
        board.push_back(num);
    }
    cin >> S;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}