#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int main()
{
    string rawInput;
    getline(cin, rawInput);
    istringstream ss(rawInput);
    string word;
    vector<int> numbers{};
    vector<string> operators{};
    while (ss >> word)
    {
        if (word == "+" ||word == "-" || word == "*" || word == "/") {
            operators.push_back(word);
        }
        else {
            int num = stoi(word);
            numbers.push_back(num);
        }
    }
    

    int opLen = operators.size();
    int numLen = numbers.size();
    int opNumDiff = numLen - opLen;
    if (opLen < 1 || numLen < 1 || opNumDiff != 1)
    {
        cout << "Error";
        return -1;
    }

    int sum = 0;
    for (int i = 0; i < numLen - 1; i++)
    {
        if (i != 0)
        {
            if (operators[opLen - 1 - i] == "+")
            {
                sum = sum + numbers[i + 1];
            }
            if (operators[opLen - 1 - i] == "-")
            {
                sum = sum - numbers[i + 1];
            }
            if (operators[opLen - 1 - i] == "*")
            {
                sum = sum * numbers[i + 1];
            }
            if (operators[opLen - 1 - i] == "/")
            {
                sum = sum / numbers[i + 1];
            }
        }
        else
        {

            if (operators[opLen - 1 - i] == "+")
            {
                sum = numbers[i] + numbers[i + 1];
            }
            if (operators[opLen - 1 - i] == "-")
            {
                sum = numbers[i] - numbers[i + 1];
            }
            if (operators[opLen - 1 - i] == "*")
            {
                sum = numbers[i] * numbers[i + 1];
            }
            if (operators[opLen - 1 - i] == "/")
            {
                sum = numbers[i] / numbers[i + 1];
            }
        }
    }

    vector<string> output{};
    int n = opLen - 1;
    for (int i = 0; i < numLen; i++) {
        if (numLen > 2 && (i == 0)) {
            output.push_back("(");
        }
        string numStr = to_string(numbers[i]);
        output.push_back(numStr);
        output.push_back(" ");
        if (numLen > 2 && (i == 1)) {
            output.pop_back();
            output.push_back(")");
            output.push_back(" ");
        }
        if (n >= 0) {
            output.push_back(operators[n]);
            output.push_back(" ");
            n--;
        }
    }

    output.push_back("=");
    string numStr = to_string(sum);
    output.push_back(" ");
    output.push_back(numStr);

    int outputLen = output.size();

    for (int i = 0; i < outputLen; i++) {
        cout<<output[i];
    }
    return 0;
}