#include "text_processing.h"
#include <boost/algorithm/string.hpp>

std::string RemoveWord(const std::string& text, const std::string& word) {
    std::string result;
    size_t left_index = 0;
    while (left_index < text.size()) {
        size_t right_index = left_index;
        while (right_index < text.size() && std::isalpha(text[right_index])) {
            ++right_index;
        }
        const auto& current_word = text.substr(left_index, right_index - left_index);
        if (!boost::iequals(current_word, word)) {
            result += current_word;
        }
        left_index = right_index;
        while (left_index < text.size() && !std::isalpha(text[left_index])) {
            result += text[left_index++];
        }
    }
    return result;
}

std::vector<std::string> ProcessLines(std::vector<std::string> lines, const std::string& word) {
    for (auto& line : lines) {
        line = RemoveWord(line, word);
    }
    std::sort(lines.begin(), lines.end(), [](const auto& lhs, const auto& rhs) {
        return boost::ilexicographical_compare(lhs, rhs);
    });
    return lines;
}