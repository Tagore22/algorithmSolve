#include <iostream>

using namespace std;

//´Ü¼øÇÑ µ¡¼À Ãâ·Â ¹®Á¦.

void MakeAnswer()
{
    int a, b;
    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        cout << (a + b) << '\n';
    }
}

int main()
{
    MakeAnswer();
    return 0;
}