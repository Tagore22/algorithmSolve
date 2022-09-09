#include <iostream>
#include <cstring>

using namespace std;

bool l[20];
bool r[20];
int board[10][10];
int N;

//기본적인 백트래킹으론 격자가 최대 10*10이기에 2의 100제곱이 되어 시간초과가 나버린다.
//그래서 검은칸일때와 하얀칸일때를 구분하여 두번에 걸쳐 답을 구해야한다.
//특히나 y와 x값을 이용하여 각 대각선에 비숍이 존재하는지 구하는 방법은 놀라웠다.


int Simulation(int y, int x, bool isblack)
{
    if (y >= N)
        return 0;
    int answer = 0;
    int next_y = x + 2 >= N ? y + 1 : y;
    int next_x = x + 2 >= N ? (x % 2) ^ 1 : x + 2;

    //x-y+N-1와 y+x는 각 왼쪽대각선 전부와 오른쪽대각선 전부의 해당하는 좌표들과 일치하기에 하나의 값으로 비숍의 유무를 알아낼수 있다.
    if (board[y][x] == 1 && !l[x - y + N - 1] && !r[y + x])
    {
        l[x - y + N - 1] = r[y + x] = true;
        answer = max(answer, Simulation(next_y, next_x, isblack) + 1);
        l[x - y + N - 1] = r[y + x] = false;
    }
    answer = max(answer, Simulation(next_y, next_x, isblack));
    return answer;
}

void MakeAnswer()
{
    int answer = Simulation(0, 0, false);
    answer += Simulation(0, 1, true);
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(l, false, sizeof(l));
    memset(r, false, sizeof(r));

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> board[i][j];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}