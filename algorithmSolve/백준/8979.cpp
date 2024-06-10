#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// 생각보다 어렵진 않았는데 정답율이 40퍼가 안되었던 문제.
// 아래 풀이 이외에도 여러 풀이가 존재하는데 가장 첫번째로 생각나는 것은 각 나라의 순서까지 배열로 생성하여
// 정렬후 K번째 나라의 값을 lower_bound()에 적용하여 맨 첫번째 원소로부터의 거리를 출력하는 것이다.
// 다만 나의 경우에는 변수 4개짜리 구조체를 쓰기 싫었고 그냥 아래 처럼 풀었다.

// 자세한 설명은 주석으로 남긴다.

struct point
{
    int g;
    int s;
    int b;
};
int N, K;
point board[1000];
point piv;

// 두 나라를 비교하는 함수. 처음에 invalid comparator 오류가 떴었다.
bool ComparePoint(const point& lhs, const point& rhs)
{
    // 각 메달이 다르다면 큰쪽이 앞에 오게끔 정렬하되, 모두 같다면 무시한다.
    // 확실히는 기억이 안나는데 정렬하지 않을 경우 false 였던것 같기도.
    if (lhs.g != rhs.g)
        return lhs.g > rhs.g;
    else if (lhs.s != rhs.s)
        return lhs.s > rhs.s;
    else if (lhs.b != rhs.b)
        return lhs.b > rhs.b;
    else
        return false;
}

void MakeAnswer()
{
    // 기준별로 각 나라를 정렬한다.
    sort(board, board + N, ComparePoint);
    int answer = 1;
    // 배열을 순회하며 등수를 점점 낮추어 간다. 찾고자 하는 나라의 메달과 동일한 경우가 나왔을때
    // 순회를 탈출한다. 이제부터 공동 등수 혹은 그보다 아래인 나라들만 나오기 때문이다.
    for (int i = 0; i < N; ++i)
    {
        if (board[i].g == piv.g && board[i].s == piv.s && piv.b == board[i].b)
            break;
        ++answer;
    }
    cout << answer << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> K;
    int num;
    for (int i = 0; i < N; ++i)
    {
        cin >> num >> board[i].g >> board[i].s >> board[i].b;
        if (num == K)
            piv = board[i];
    }
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}