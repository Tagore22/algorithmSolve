#include <iostream>

using namespace std;

// 풀이.
// 브4 문제인데 내가 수학적 접근에 약한지 조금 걸렸다.
// 엄지에서 시작해서 다시 검지까지 오는 곳까지 사이클이 생긴다. 따라서 사이클의 주기인 8만큼 나누어주어야하는데
// 이때 귀찮은 부분이 검지부터 약지까지 2개씩 구간이 생긴다는 것이었다. 따라서 따로 조건문에 추가하여 처리하였다.

int main()
{
    int N;
    cin >> N;
    int answer = N % 8;
    if (answer == 1)
        cout << 1 << '\n';
    else if (answer == 0 || answer == 2)
        cout << 2 << '\n';
    else if (answer == 7 || answer == 3)
        cout << 3 << '\n';
    else if (answer == 6 || answer == 4)
        cout << 4 << '\n';
    else
        cout << 5 << '\n';
    return 0;
}