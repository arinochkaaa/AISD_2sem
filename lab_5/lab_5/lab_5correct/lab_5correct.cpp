#include <iostream>
#include <stack>
#include <string>

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '[' && close == ']') ||
        (open == '{' && close == '}');
}

bool isValidParentheses(const std::string& str) {
    std::stack<char> s;
    int count = 0;
    for (char ch : str) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch); 
            count++;
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.empty() || !isMatching(s.top(), ch)) {
                return false;
            }
            s.pop(); 
        }
    }
    if (count == 0) std::cout << "скобок нету, поэтому\n ";
    return s.empty(); 
}

int main() {
    setlocale(LC_ALL, "rus");
    std::string input;

    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    if (isValidParentheses(input)) {
        std::cout << "Скобки расставлены верно." << std::endl;
    }
    else {
        std::cout << "Скобки расставлены неверно." << std::endl;
    }

    return 0;
}
