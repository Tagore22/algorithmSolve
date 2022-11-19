#include <iostream>
#include <string>

using namespace std;

//1206번의 풀이중 0~인원수 * 10의 for문을 이분탐색으로 변환한 풀이. 최대 100번 밖에 순회하지 않기에 성능이 거의 20배는 빨라졌다.

int board[50];
int N;

void MakeAnswer()
{
    for (int i = 1; i <= 1000; ++i)
    {
        int find_num = 0;
        for (int j = 0; j < N; ++j)
        {
            int lo = -1, hi = i * 10 + 1, mid;
            for (int iter = 0; iter < 100; ++iter)
            {
                mid = (lo + hi) / 2;
                if (mid * 1000 / i > board[j])
                {
                    hi = mid;
                }
                else if (mid * 1000 / i < board[j])
                {
                    lo = mid;
                }
                else
                {
                    ++find_num;
                    break;
                }
            }
        }
        if (find_num == N)
        {
            cout << i << '\n';
            break;
        }
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        board[i] = stoi(str.substr(str.find('.') + 1));
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}