#include <iostream>

using namespace std;

// 풀이.
// 주어진 수 T를 300, 60, 10로 나눌때 가장 적은 수를 출력하는 문제다.
// 가장 적은 수를 만들기 위해서는 최대한 큰수들로 나누어야 한다.
// 따라서 가장 큰 수인 300부터 T를 나누어 나가며 T를 줄여야 한다.
// 그 후 10으로 나누고 나서 T가 0이 아니라면 나누는 것이 불가능하므로 -1을 출력하고
// 0이라면 여태까지 나누었던 수들을 출력하면 된다.

// 자세한 설명은 주석으로 남긴다.

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> T;
    int a, b, c;

    // 위 상술하였듯이 나눌때 가장 적은 수를 만드려면 가장 큰 수부터 나누어야 한다.
    // 따라서 300부터 T를 나누어 가며 T를 줄인다.
    a = T / 300;
    T %= 300;
    b = T / 60;
    T %= 60;
    c = T / 10;
    T %= 10;

    // 가장 작은 10으로 까지 나눈후 T가 0이 아니라면 나누는것이 불가능하기에 -1을 출력한다.
    if (T != 0)
        cout << -1 << '\n';
    // 0이라면 나누는것이 가능하므로 각 수들의 나눈값들을 출력한다.
    else
        cout << a << ' ' << b << ' ' << c << '\n';

    return 0;
}