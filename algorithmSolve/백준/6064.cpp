#include <iostream>

using namespace std;

//주어진 수 M,N,x,y가 있을때 M의 배수 + x와 N의 배수 + y가 같을때가 존재한다면 그 수를 출력하고, 없다면 -1을 출력하는 문제이다.
//다만 M과 N의 배수를 구할때 그 최대값을 알아야하는데 그 최대값은 두 수 M과 N의 최소공배수 임을 알수 있다.
//처음엔 M의 배수와 N의 배수를 최대값까지 모두 구하여 배열을 순회하며 같은 경우를 찾았는데 이상하게 답이 나오질 않아서
//M을 증가시키며 N으로 나누었을때 y가 나오는 경우로 바꾸었다. 메모리더 더 적게 차지 하고 연산도 적기에 속도도 더 빠르다.

int T, M, N, x, y;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int Cal()
{
    const int MAX_NUM = lcm(M, N);

    for (int i = x; i <= MAX_NUM; i += M)
    {
        int check = i % N == 0 ? N : i % N;
        if (check == y)
            return i;
    }

    return -1;
}

void MakeAnswer()
{
    for (int i = 0; i < T; ++i)
    {
        cin >> M >> N >> x >> y;
        cout << Cal() << '\n';
    }
}

void Input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
}

int main()
{
    Input();
    MakeAnswer();
    return 0;
}