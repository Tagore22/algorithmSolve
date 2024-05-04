#include <iostream>

using namespace std;

int main()
{
    string str1[10], str2[10];
    int N, M;
    cin >> N >> M;
    bool answer = true;
    for (int iter = 0; iter < N; ++iter)
        cin >> str1[iter];
    for (int iter = 0; iter < N; ++iter)
        cin >> str2[iter];
    for (int iter = 0; iter < N; ++iter)
        for (int i = 1; i < str2[iter].size(); i += 2)
            if (str2[iter][i] != str2[iter][i - 1] || str1[iter][i / 2] != str2[iter][i])
            {
                answer = false;
                break;
            }

    if (answer)
        cout << "Eyfa" << '\n';
    else
        cout << "Not Eyfa" << '\n';
    return 0;
}