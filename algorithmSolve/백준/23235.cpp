#include <iostream>

using namespace std;

int main()
{
    int N, idx = 1;
    while (true)
    {
        cin >> N;
        if (N == 0)
            break;
        int num;
        for (int iter = 0; iter < N; ++iter)
            cin >> num;
        cout << "Case " << idx << ": Sorting... done!" << '\n';
        ++idx;
    }
    return 0;
}