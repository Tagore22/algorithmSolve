#include <iostream>
#include <string>

using namespace std;

// 풀이.
// 내 상태가 안좋은건지 문제가 어려운건지 브론즈 문제 푸는데 1시간 가까이 걸렸다;
// 문제자체는 문자열을 6개씩 나누어 A ~ H까지 두번이상 틀리지 않는 문자열이 존재하는지 확인하는 문제이다.
// for문의 순서를 짜는데 오래걸렸다.

string board[8] = { "000000", "001111", "010011", "011100", "100110", "101001", "110101", "111010" };
string str;
int N;

int main()
{
    cin >> N >> str;
    string answer = "";
    bool isFind, isDiff;
    for (int iter = 0; iter < N; ++iter)
    {
        for (int i = 0; i < 8; ++i)
        {
            isDiff = false;
            isFind = true;
            for (int j = iter * 6; j < iter * 6 + 6; ++j)
            {
                if (str[j] != board[i][j - iter * 6])
                {
                    if (isDiff)
                    {
                        isFind = false;
                        break;
                    }
                    isDiff = true;
                }
            }
            if (isFind)
            {
                answer += 65 + i;
                break;
            }
        }
        if (!isFind)
        {
            answer = to_string(iter + 1);
            break;
        }
    }
    cout << answer << '\n';
    return 0;
}