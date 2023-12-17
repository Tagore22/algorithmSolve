#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 2776번의 더 나은 풀이.
// 배열에 특정 정수가 존재하는지만 확인하고 삭제할일이 없기에 굳이 set을 사용하지 않고
// 배열의 크기만큼 순회하지 않아도 이분 탐색을 활용하면 더 빠르게 접근할수 있다.
// 따라서 lower_bound 혹은 upper_bound를 이용하면 되는데 속도는 비슷하기에 아무거나 사용하면 된다.

// 자세한 설명은 주석으로 남긴다.

vector<int> board;
int T, N, M;

void MakeAnswer()
{
    for (int k = 0; k < T; ++k)
    {
        // 매번 배열을 비우거나 초기화해야하기에 그냥 vector를 사용하였다.
        board.clear();
        cin >> N;
        int num;
        for (int i = 0; i < N; ++i)
        {
            cin >> num;
            board.push_back(num);
        }
        // lower_bound 혹은 upper_bound를 사용하기 위한 정렬.
        sort(board.begin(), board.end());
        cin >> M;
        for (int i = 0; i < M; ++i)
        {
            cin >> num;
            // 현재 정수 num과 같거나 더 큰 가장 작은 수의 위치를 찾는다.
            auto iter = lower_bound(board.begin(), board.end(), num);
            // 그런 수가 존재하지 않아서 위치가 board.end()라면 0을 출력하고 for문을 반복한다.
            if (iter == board.end())
            {
                cout << 0 << '\n';
                continue;
            }
            // 존재한다면 그 수가 num과 같다면 1을 그렇지 않다면 0을 출력한다.
            cout << (*iter == num ? 1 : 0) << '\n';
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}