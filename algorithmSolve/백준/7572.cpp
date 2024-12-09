#include <iostream>
#include <cmath>

using namespace std;

// 풀이.
// 음수의 나눗셈 연산을 주의해야 한다.

int main()
{
    char ez[12] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L' };
    int year;
    cin >> year;
    int diff = abs(year - 2013);
    bool isright = year >= 2013 ? true : false;
    int gan_idx = 9, ez_idx = 5;
    int gan_move = diff % 10, ez_move = diff % 12;
    if (isright)
    {
        gan_idx = (gan_idx + gan_move) % 10;
        ez_idx = (ez_idx + ez_move) % 12;
    }
    else
    {
        gan_idx = (10 + gan_idx - gan_move) % 10;
        ez_idx = (12 + ez_idx - ez_move) % 12;
    }
    cout << ez[ez_idx] << gan_idx << '\n';
    return 0;
}