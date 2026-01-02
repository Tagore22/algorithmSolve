#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// 너무 어렵다. 나중에 다시 보자.

// 해시 충돌을 최소화하기 위해 26개의 알파벳에 대응하는 소수 배열
// 큰 소수를 무작위로 배치하여 성분이 같으면 같은 해시값이 나오도록 함
long long powers1[26];
long long powers2[26];

void setup_primes() {
    // 임의의 소수들 (예시)
    int primes1[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101 };
    int primes2[] = { 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239 };

    for (int i = 0; i < 26; i++) {
        powers1[i] = (long long)primes1[i] * primes1[i] * primes1[i] * 12345; // 값의 분산을 위해 조정
        powers2[i] = (long long)primes2[i] * primes2[i] * primes2[i] * 54321;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.length();
    int n2 = s2.length();
    setup_primes();

    // 더 짧은 길이를 기준으로 최대 가능 길이부터 탐색
    for (int len = min(n1, n2); len > 0; len--) {
        set<pair<long long, long long>> hashes;

        // s1에서 길이 len인 모든 부분 문자열의 해시값 계산
        long long h1 = 0, h2 = 0;
        for (int i = 0; i < len; i++) {
            h1 += powers1[s1[i] - 'a'];
            h2 += powers2[s1[i] - 'a'];
        }
        hashes.insert({ h1, h2 });

        for (int i = len; i < n1; i++) {
            h1 = h1 - powers1[s1[i - len] - 'a'] + powers1[s1[i] - 'a'];
            h2 = h2 - powers2[s1[i - len] - 'a'] + powers2[s1[i] - 'a'];
            hashes.insert({ h1, h2 });
        }

        // s2에서 길이 len인 모든 부분 문자열의 해시값을 계산하며 s1에 있는지 확인
        h1 = 0, h2 = 0;
        for (int i = 0; i < len; i++) {
            h1 += powers1[s2[i] - 'a'];
            h2 += powers2[s2[i] - 'a'];
        }
        if (hashes.count({ h1, h2 })) {
            cout << len << endl;
            return 0;
        }

        for (int i = len; i < n2; i++) {
            h1 = h1 - powers1[s2[i - len] - 'a'] + powers1[s2[i] - 'a'];
            h2 = h2 - powers2[s2[i - len] - 'a'] + powers2[s2[i] - 'a'];
            if (hashes.count({ h1, h2 })) {
                cout << len << endl;
                return 0;
            }
        }
    }

    cout << 0 << endl;
    return 0;
}