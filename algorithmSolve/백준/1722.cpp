#include <iostream>
#include <vector>

using namespace std;

// 풀이
// 예전에 종만북을 공부하면서 많이 풀어봤던 문제이다. K번째 수열을 구하는 문제인데, 우선 현재 자리수에서 구할수 있는 개수를 알아야한다.
// 그것이 MakePermu()인데, 수열에 같은 수가 중복으로 들어가지 않기에 팩토리얼 개수와 동일하다.

// 이 문제에는 소문제가 있는데 그것을 각각 처리해줘야한다.

// 우선 1번부터 보자면, 주어지는 K번째 수열을 출력하는 것이다.
// 작은수부터 정렬되어 있기에 가장 작은수인 1부터 시작하여 현재 i번째에서 만들수 있는 수 make_cur와 K를 비교한다. K가 더 작거나 같다면
// 현재 수로 만들수 있기에 최종답 배열 answer에 i를 넣고, 다시 i는 사용할수 없기에 check[i] = false를 해준다.
// 이렇게 N번을 반복하여 최종답 answer를 만들어 출력하면 된다.

// 2번은 그 반대로 수열이 주어졌을때 몇번째 수열인지 K값을 출력해야하는데 비슷한 원래로 풀수 있다. 출력값 skip을 0으로 시작한다.
// 다시 자리수를 반복하며 1번부터 시작하여 현재수 i와 현재 자리수 board[iter]를 비교한다. 그래서 비교시 두 수가 같다면 다음 자리수로 넘어가고
// 같지 않다면 make_cur보다 skip이 커서 다음수로 넘어간것이기에 출력값 skip에 make_cur값을 더해준다. 다만 위 상술하였듯 수열에 중복되는 수는
// 없기에 이미 사용된 수는 check 배열을 이용하여 무시해주어야한다. 이렇게 마지막 자리까지 순회가 끝나면 최종값 skip에 1을 더해 출력한다.

vector<int> board;
vector<long long> permu;
vector<bool> check;
int N, T;
long long num;

void MakePermu()
{
    permu.push_back(1);
    for (int i = 1; i <= N; ++i)
        permu.push_back(permu[i - 1] * i);
}

void CalOne()
{
    long long skip = num;
    for (int iter = 1; iter <= N; ++iter)
    {
        long long make_cur = permu[N - iter];
        for (int i = 1; i <= N; ++i)
        {
            if (!check[i])
                continue;
            if (skip <= make_cur)
            {
                board.push_back(i);
                check[i] = false;
                break;
            }
            else
            {
                skip -= make_cur;
            }
        }
    }

    for (auto& n : board)
        cout << n << ' ';
    cout << '\n';
}

void CalTwo()
{
    long long skip = 0;
    for (int iter = 0; iter < N; ++iter)
    {
        long long make_cur = permu[N - iter - 1];
        for (int i = 1; i <= N; ++i)
        {
            if (!check[i])
                continue;
            if (board[iter] == i)
            {
                check[i] = false;
                break;
            }
            skip += make_cur;
        }
    }
    cout << skip + 1 << '\n';
}

void MakeAnswer()
{
    MakePermu();
    if (T == 1)
        CalOne();
    else
        CalTwo();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> T;
    check.resize(N + 1, true);
    if (T == 1)
        cin >> num;
    else
        for (int i = 0; i < N; ++i)
        {
            int a;
            cin >> a;
            board.push_back(a);
        }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}