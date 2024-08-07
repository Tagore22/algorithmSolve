#include <iostream>

using namespace std;

// 풀이.
// 언젠가 어려워 보여서 넘겼던 문제다. 오늘은 꽤나 쉽게 풀었는데 나 스스로가 많이 강해졌나보다.
// 브루트포스 알고리즘의 접근이 필요했던 것 같다. 공식이라던가 점화식이라던가 보다는 규칙을 주먹구구식
// 으로 구해냈다. 아래 주석을 보면 알수 있듯이 보여지는 면은 1 ~ 3개가 존재한다. 이 값들을 각각 구해
// 모두 더하면 된다. 정답율이 30퍼가 안되었지만 그리 어렵지 않게 풀었는데 뜻하지 않은 2가지 실수로
// 좀 해맸다.

// 자세한 설명은 주석으로 남긴다.

long long dice[6];
long long N, answer = 0, mindice = 51, maxdice = 0;

// 각 주사위는 1면이 보이는곳, 2면이 보이는곳, 3면이 보이는곳으로 나뉜다.
// 이때 1면이 보이는곳은 무조건 가장 작은 수가로 하면 되고
// 2면은 각 면에서 시작해서 맞닿은 면과의 합이 가장 작은곳으로,
// 3면은 어떤 면 A에서 시작해서 닿은 면이 B일때 다시 B에서 닿은 면들중
// A와 닿는 면 C를 찾아 세 면의 합을 구하면 된다. 또한, 3면이 보이는 곳은 오직 4곳뿐이다.
// 닿을수 없는 곳은 A부터 각 5, 4, 3, 2, 1, 0이다.

// 3면이 보이는 주사위들의 최소값을 구하는 함수.
void ThreeFace()
{
    long long sum = 151;
    // A와 B, B와 A 같은 중복은 필요가 없기에 이전 인덱스값 + 1부터 구해준다.
    for (int i = 0; i < 6; ++i)
    {
        for (int j = i + 1; j < 6; ++j)
        {
            for (int k = j + 1; k < 6; ++k)
            {
                // 마주보는 면이 존재해서는 안된다. 따라서 두 인덱스값의 합이 5일 경우는 피한다.
                // 여기서 첫번째 실수가 나왔는데 밑의 2면의 if문을 그대로 복사해서 붙여넣다가
                // i + j == 5 라는 조건을 빼먹었다. 후...
                if (i + k == 5 || j + k == 5 || i + j == 5)
                    continue;
                sum = min(sum, dice[i] + dice[j] + dice[k]);
            }
        }
    }
    // 3면이 보이는 곳은 윗부분에 오직 4곳뿐이다.
    answer += sum * 4;
}

// 2면이 보이는 주사위들의 최소값을 구하는 함수.
void TwoFace()
{
    long long sum = 101;
    // 3면을 구할때와 마찬가지로 중복을 피하기 위해 이전 인덱스값 + 1부터 구해낸다.
    for (int i = 0; i < 6; ++i)
    {
        for (int j = i + 1; j < 6; ++j)
        {
            if (i + j == 5)
                continue;
            sum = min(sum, dice[i] + dice[j]);
        }
    }
    // 2면이 보이는 곳의 수는 (N - 1) * 4 + (N - 2) * 4다. 각 옆면과 윗면.
    answer += ((N - 1) * 4 + (N - 2) * 4) * sum;
}

void MakeAnswer()
{
    // 여기서 두번째 실수가 발생했는데 주어지는 N의 값은 100만보다 작은 자연수이다.
    // 따라서 1인 경우도 존재하는데 기존의 구한 코드로는 1일 경우에 제대로 된 값이 나오지 않아
    // 예외처리를 해주어야 했다. 주사위가 1개뿐이므로 가장 큰 면을 아래로 두면 된다.
    if (N == 1)
    {
        for (int i = 0; i < 6; ++i)
            answer += dice[i];
        answer -= maxdice;
        cout << answer << '\n';
        return;
    }
    // 1면이 보이는곳의 수는 N - 2의 제곱 + N - 2 * N - 1의 4다. 각 위부분과 옆부분.
    answer += ((N - 2) * (N - 2) + (N - 2) * (N - 1) * 4) * mindice;
    TwoFace();
    ThreeFace();
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < 6; ++i)
    {
        cin >> dice[i];
        mindice = min(mindice, dice[i]);
        maxdice = max(maxdice, dice[i]);
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}