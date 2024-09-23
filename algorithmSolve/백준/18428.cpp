#include <iostream>
#include <vector>

using namespace std;

// 풀이.
// 그다지 어려운 문제는 아니었다. 2가지 부분으로 나누어야 했는데 다음과 같다.
// 1. 빈칸들중 3개를 골라 O로 채우는 함수.
// 2. 3개의 O를 찾았을때 각 선생들의 시야를 확인하는 함수.

// N자체가 일단 작기 때문에 딱히 부담도 없었던 문제다. 또한, 각 칸을 확인할때
// 행과 열이 아닌 하나의 수를 N으로 계산하여 구현했던게 좋았던것 같다.

// 자세한 설명은 주석으로 남긴다.

char board[6][6];
vector<int> teacher;
int N;

// 3개의 O를 골랐을때 각 선생들의 시야를 확인하는 함수.
bool CheckSight()
{
    // 모든 선생들을 순회한다.
    for (auto& t : teacher)
    {
        // 상술하였듯 하나의 인덱스값을 N으로 계산하여 행과 열을 알아낼수 있다.
        int y = t / N;
        int x = t % N;

        // 아래쪽 시야 확인.
        for (int i = y; i < N; ++i)
        {
            // 만약 장애물이 존재한다면 더이상 확인할 필요가 없다.
            if (board[i][x] == 'O')
                break;
            // 혹은 학생을 발견했다면 false를 반환하여 실패를 알린다.
            else if (board[i][x] == 'S')
                return false;
        }
        // 위쪽 시야 확인.
        for (int i = y; i >= 0; --i)
        {
            if (board[i][x] == 'O')
                break;
            else if (board[i][x] == 'S')
                return false;
        }
        // 오른쪽 시야 확인.
        for (int i = x; i < N; ++i)
        {
            if (board[y][i] == 'O')
                break;
            else if (board[y][i] == 'S')
                return false;
        }
        // 왼쪽 시야 확인.
        for (int i = x; i >= 0; --i)
        {
            if (board[y][i] == 'O')
                break;
            else if (board[y][i] == 'S')
                return false;
        }
    }
    // 여기까지 도달했다면 선생의 시야에는 더이상 학생이 발견되지 않았다.
    return true;
}

// 3개의 O를 찾는 모든 경우를 찾는 함수.
void FindO(int idx, int num)
{
    // 3개의 O를 발견했다면 이 상태에서 모든 선생들의 시야를 막을수 있는지 확인해본다.
    if (num == 3)
    {
        // 막을수 있다면 YES를 출력후 프로그램을 종료한다.
        if (CheckSight())
        {
            cout << "YES" << '\n';
            exit(0);
        }
        // 그렇지 않다면 탈출하여 다른 경우를 찾는다.
        return;
    }

    // 현재 위치부터 모든 칸을 순회하며 확인한다.
    for (int i = idx; i < N * N; ++i)
    {
        int y = i / N;
        int x = i % N;
        if (board[y][x] == 'X')
        {
            // 찾은 빈칸을 O로 채우고 재귀호출한다.
            board[y][x] = 'O';
            FindO(i, num + 1);
            // 반드시 원래대로 복구시켜야한다.
            board[y][x] = 'X';
        }
    }
}

void MakeAnswer()
{
    FindO(0, 0);
    // FindO()에서 모든 경우를 찾아봤는데도 찾지 못했다면
    // 그 어떤 경우에도 불가능하기에 NO를 출력한다.
    cout << "NO" << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            cin >> board[i][j];
            if (board[i][j] == 'T')
                teacher.push_back(i * N + j);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}