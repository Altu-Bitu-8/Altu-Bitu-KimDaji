#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 시리얼 번호 구조체
struct serial { 
    string code;  
    int length;
    int score;
};

// 자리수 합 계산
int getScore(const string& code) {
    int score = 0;
    for (char c : code) { 
        if (isdigit(c)) score += c - '0';  
    }
    return score;
}

// 비교 함수 
// v1 < v2 : v1 >= v2 일 경우, false 이므로 v2 - v1 으로 swap
// v2 <= v1 순서로 정렬되므로 내림차순 정렬을 의미한다

bool cmp(const serial& s1, const serial& s2) {
    if (s1.length != s2.length) {
        return s1.length < s2.length;  
        // 길이가 짧은 것이 먼저
    }
    if (s1.score != s2.score) {
        return s1.score < s2.score;  
        // 자리 수의 합이 작은 것이 먼저
    }
    return s1.code < s2.code;  
    // 사전 순 
}

int main() {
    int n;
    cin >> n;  

    vector<serial> arr(n);  

    // 입력
    for (int i = 0; i < n; i++) {
        cin >> arr[i].code;
        arr[i].length = arr[i].code.length();
        arr[i].score = getScore(arr[i].code);
    }
    
    // 정렬 
    sort(arr.begin(), arr.end(), cmp);

    // 출력
    for (const auto& s : arr) {
        cout << s.code << '\n';
    }

    return 0;
}
