#include <iostream>
#include <algorithm>

using namespace std;

// 풀이.
// sort()의 정렬 기준이 되는 함수를 만드는 것이 중요한 함수이다.
// 국어, 영어, 수학, 이름 순으로 비교를 하게 되는데 현재 비교되는 부분이
// 같지 않다면 그 단계에서 바로 비교가 되고 그렇지 않다면 다음 비교 순위로 넘어간다.
// 비교를 끝내고 나면 순서대로 이름만 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

// 각 사람들을 표현하는 구조체.
struct person
{
    string name;
    int l;
    int e;
    int m;
};

person board[100000];
int N;

// 정렬의 기준이 되는 함수. 국어, 영어, 수학, 이름순으로 비교하되
// 현재 두 비교값이 다르다면 비교가 가능하고 같다면 다음 비교 대상으로 넘어가 다시 비교함.
bool ComparePerson(const person& lhs, const person& rhs)
{
    if (lhs.l != rhs.l)
        return lhs.l > rhs.l ? true : false;
    else if (lhs.e != rhs.e)
        return lhs.e < rhs.e ? true : false;
    else if (lhs.m != rhs.m)
        return lhs.m > rhs.m ? true : false;
    else
        return lhs.name < rhs.name ? true : false;
}

void MakeAnswer()
{
    // 위 함수를 이용하여 정렬한후 순서대로 이름을 출력한다.
    sort(board, board + N, ComparePerson);
    for (int i = 0; i < N; ++i)
        cout << board[i].name << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> board[i].name >> board[i].l >> board[i].e >> board[i].m;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}