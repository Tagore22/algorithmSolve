#include <iostream>
#include <cstring>

using namespace std;

//그리드로 풀기 애매하여 결국 완전탐색을 해야하나 최대 경우수가 3의 1000제곱이다. 시간내에 무조건 불가능하니
//DP를 이용해서 각 자리에 3가지 모두를 사용하는 경우의 수를 구해낸다.

int N;
const int DIVNUM = 1000000;
int cashe[1001][1001][2][3];

int Cal(int idx, int O_num, int L_num, int A_num)
{
    if (L_num >= 2 || A_num >= 3)
        return 0;
    if (idx == N)
        return 1;

    int& ans = cashe[idx][O_num][L_num][A_num];
    if (ans != -1)
        return ans;

    ans = Cal(idx + 1, O_num + 1, L_num, 0) + Cal(idx + 1, O_num, L_num + 1, 0) +
        Cal(idx + 1, O_num, L_num, A_num + 1);

    return ans %= DIVNUM;
}

void MakeAnswer()
{
    cout << Cal(0, 0, 0, 0) << '\n';
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(cashe, -1, sizeof(cashe));

    cin >> N;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}