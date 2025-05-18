#include <iostream>

using namespace std;

int main()
{
    int R, C, V;
    cin >> R >> C >> V;
    long long answer = R % V == 0 ? R / V : R / V + 1;
    answer = C % V == 0 ? answer * (C / V) : answer * (C / V + 1);
    cout << answer << '\n';
    return 0;
}