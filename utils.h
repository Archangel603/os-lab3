#ifndef LAB3_UTILS_H
#define LAB3_UTILS_H

#include "vector"
#include "string"

using namespace std;

vector<string> split(string input, string delimiter) {
    vector<string> res;
    size_t pos = 0;
    std::string token;
    while ((pos = input.find(delimiter)) != string::npos) {
        token = input.substr(0, pos);
        res.push_back(token);

        input.erase(0, pos + delimiter.length());
    }

    res.push_back(input);

    return res;
}

vector<int> splitToInt(string input, string delimiter) {
    auto items = split(input, delimiter);
    vector<int> result(items.size());

    for (int i = 0; i < items.size(); i++) {
        result[i] = stoi(items[i]);
    }

    return result;
}

#endif //LAB3_UTILS_H
