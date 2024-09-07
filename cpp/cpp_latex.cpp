// cpp_latex.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

void noitem() {
    using namespace std::literals;
    ifstream f1("C:\\new_doc\\cpp\\cpp.tex");
    ofstream f2("C:\\new_doc\\cpp\\cpp_noitem.tex");
    string line;
    stack<int> s;
    bool flag = false;
    while (getline(f1, line)) {
        if (line == "") {
            f2 << line << endl;
            continue;
        }
        const std::string WHITESPACE = " \n\r\t\f\v";
        auto pos = line.find_first_not_of(WHITESPACE);
        if (pos == string::npos) {
            f2 << line << endl;
            continue;
        }
        string trim_line = line.substr(pos);
        if (trim_line[0] == '%') {
            f2 << line << endl;
            continue;
        }
        

        if (line.find("\\item About PIMPL, you need to know") != string::npos) {
            cout << "ggg" << endl;
        }
        cout << line << endl;
        if (trim_line.find("\\begin{itemize}"sv) != string::npos) {
            s.push(1);
            flag = false;
            continue;
        }
        else if (trim_line.find("\\begin{enumerate}"sv) != string::npos) {
            s.push(2);

        }
        else if (trim_line.find("\\end{enumerate}"sv) != string::npos) {
            s.pop();

        }
        else if (trim_line.find("\\end{itemize}"sv) != string::npos) {
            s.pop();
            continue;
        }
        else if (trim_line.find("\\begin{description}"sv) != string::npos) {
            s.push(3);
        }
        else if (trim_line.find("\\end{description}"sv) != string::npos) {
            s.pop();
        }


        auto item = "\\item"sv;
        if (trim_line.starts_with(item)) {
            if (!s.empty() && s.top() == 1) {
                auto i = line.find(item);
                if (!flag) {
                    line.erase(i, item.length());
                    flag = true;
                }
                else {
                    line.replace(i, item.length(), "\\par");
                }
            }
        }

        f2 << line << endl;
    }

    std::cout << "Hello World!\n";
}

void addline() {
    ifstream f1("C:\\new_doc\\cpp\\cpp_noitem.tex");
    ofstream f2("C:\\new_doc\\cpp\\cpp_noitem_line.tex");
    string line;
    int count = 0;
    const std::string WHITESPACE = " \n\r\t\f\v";
    stack<int> s;
    while (getline(f1, line)) {
        auto pos = line.find_first_not_of(WHITESPACE);
        if (pos == string::npos) {
            continue;
        }
        string trim_line = line.substr(pos);

        if (trim_line.find("\\begin{itemize}"sv) != string::npos) {
            s.push(1);
            //flag = false;
            continue;
        }
        else if (trim_line.find("\\begin{enumerate}"sv) != string::npos) {
            s.push(2);

        }

        
        f2 << "  " << endl;
        
        f2 << line << endl;
    }
}

int main()
{
    noitem();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
