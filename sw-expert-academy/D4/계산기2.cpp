#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>
 
using namespace std;
 
// 우선순위 정의
unordered_map<char, int> pri = { {'*', 2}, {'+', 1} };
 
int main() {
 
    int N, answer;
    string infix; // 중위 표기식
    string postfix; // 후위 표기식
 
    for (int tc = 1; tc <= 10; tc++) {
        // input
        cin >> N >> infix;
 
        // 중위 표기식 -> 후위 표기식
        stack<char> oper;
        postfix = "";
        for (char c : infix) {
            if (isdigit(c)) // 피연산자
                postfix += c;
            else { // 연산자
                while (!oper.empty() && pri[c] <= pri[oper.top()]) {
                    postfix += oper.top();
                    oper.pop();
                }
                oper.push(c);
            }
        }
        while (!oper.empty()) {
            postfix += oper.top();
            oper.pop();
        }
         
        // 후위 표기식 계산
        stack<int> num;
        for (char c : postfix) {
            if (isdigit(c)) // 피연산자
                num.push(c - '0');
            else { // 연산자
                int n1 = num.top(); num.pop();
                int n2 = num.top(); num.pop();
                if (c == '*')
                    num.push(n1 * n2);
                else // c == '+'
                    num.push(n1 + n2);
            }
        }
        answer = num.top();
 
        // output
        cout << '#' << tc << ' ' << answer << '\n';
    }
 
    return 0;
}