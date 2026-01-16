#include <iostream>

using namespace std;

// Ç®ÀÌ.
// 13ÃþÀ» °Ç³Ê¶Ú´Ù. Èì... ±×³É ¸» ±×´ë·Î 13Ãþ µü ÇÑÃþ¸¸ °Ç³Ê¶Ù´Â °ÍÀÌ¾ú´Ù.
// ³Ê¹« ¾î·Æ°Ô »ý°¢Çß´Ù.

int main()
{
    int x;
    cin >> x;

    cout << (x >= 13 ? x + 1 : x) << '\n';
    return 0;
}