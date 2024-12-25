#include <iostream>

using namespace std;

int main()
{
    int N, W, H, L;
    cin >> N >> W >> H >> L;
    int answer = (W / L) * (H / L);
    answer = min(N, answer);
    cout << answer << '\n';
    return 0;
}