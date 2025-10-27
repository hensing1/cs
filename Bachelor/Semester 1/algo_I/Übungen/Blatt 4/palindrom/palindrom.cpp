#include <iostream>
#include <string>

bool is_palindrome(std::string word, int i, int j);

int main(int argc, char **argv) {
    if (argc != 2)
        return -1;
    
    std::string word = argv[1];
    std::cout << is_palindrome(word, 0, word.size() - 1) << std::endl;
}

bool is_palindrome(std::string word, int i, int j) {
    if (j <= i)
        return true;
    
    if (word[i] == word[j])
        return is_palindrome(word, i + 1, j - 1);

    return false;
}