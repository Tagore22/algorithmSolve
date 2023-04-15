#include <iostream>
#include <cstring>

using namespace std;

// 풀이.
// 언뜻 보면 복잡해보이지만 막상 생각해보면 그리 어렵지 않았다.
// 가장 큰수와 작은수를 계산할때가 반대의 형식인데 큰수를 구할때의 원리는 다음과 같다.

// 1. 시작값은 9부터이다. 주어진 부호를 순회하는데 현재 순회값은 0부터이다. '>' 를 만날때까지 값은 계속 줄어든다.
// 2. 처음으로 '>'를 만났을때 값을 string에 집어넣는다.
// 3. 현재값은 가장 큰 9부터 0까지 중 아직 정해지지 않은(false인) 수중 가장 큰수이다.
// 4. 다시 현재 순회값의 + 1 값부터 마저 순회한다. 이것을 반복한다.

// 작은수는 그 반대이다. 

bool check[10];
char board[9];
string answer;
int K;

void CalMax()
{
    memset(check, false, sizeof(check));

    // 현재값. 게속 추적해나가야 한다.
    int now;

    // 주어진 부호들을 순회한다.
    for (int i = 0; i < K; ++i)
    {
        // 현재 값은 9 ~ 0 중 정해지지 않은(false인) 가장 큰 수이다.
        for (int j = 9; j >= 0; --j)
            if (!check[j])
            {
                now = j;
                break;
            }

        // 현재 순회값부터 끝까지 순회해가며 '>'일때까지 그 값은 작아져간다.
        int iter = i;
        while (board[iter] == '<' && iter < K)
        {
            ++iter;
            --now;
        }

        // 현재값은 정해졌고 string에 집어넣는다.
        check[now] = true;
        answer.push_back(now + '0');
    }

    // 직접 대입해보면 알겠지만 마지막에 한번 더 집어넣어야한다.
    for (int j = 9; j >= 0; --j)
        if (!check[j])
        {
            now = j;
            break;
        }

    answer.push_back(now + '0');

    // 최종값을 출력한다.
    cout << answer << '\n';
}


// 최대값을 구하는 함수와 반대다.
void CalMin()
{
    memset(check, false, sizeof(check));
    answer.clear();

    int now;
    for (int i = 0; i < K; ++i)
    {
        // 0 ~ 9 중 아직 정해지지 않은 가장 작은수가 현재값이다.
        for (int j = 0; j < 10; ++j)
            if (!check[j])
            {
                now = j;
                break;
            }

        int iter = i;

        // 현재 순회값부터 마지막까지 순회하며 '<'를 찾을때까지 현재값은 계속 커져간다.
        while (board[iter] == '>' && iter < K)
        {
            ++iter;
            ++now;
        }

        // 현재 값은 정해졌고 string에 더한다.
        check[now] = true;
        answer.push_back(now + '0');
    }

    // 최대값과 동일하게 대입해보면 마지막에 한번 더 추가해야한다.
    for (int j = 0; j < 10; ++j)
        if (!check[j])
        {
            now = j;
            break;
        }

    answer.push_back(now + '0');

    // 최종값 출력.
    cout << answer << '\n';
}

void MakeAnswer()
{
    CalMax();
    CalMin();
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    for (int i = 0; i < K; ++i)
        cin >> board[i];
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}