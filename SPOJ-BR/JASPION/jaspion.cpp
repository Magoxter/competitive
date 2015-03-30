#include <iostream>
#include <sstream>
#include <string>
#include <map>

std::map<std::string, std::string> buildDic(int M) {
    std::map<std::string, std::string> dic;

    for (int i = 0; i < M; i++) {
        // Read word
        std::string word;
        std::getline(std::cin, word);

        // Now read translation
        std::string trans;
        std::getline(std::cin, trans);
 
        dic[word] = trans;
    }

    return dic;
}

void translateSong(std::map<std::string, std::string> dic, int N) {
    for (int i = 0; i < N; i++) {
        // Read entire line
        std::string line;
        std::getline(std::cin, line);

        // Separate line in words
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            if (dic.find(word) != dic.end()) std::cout << dic[word] << " ";
            else std::cout << word << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    int T;

    // Number of test cases
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        // Number of words in the dictionary and number of lines of the song
        int M, N;
        std::string trash;
        
        std::cin >> M >> N;
        // Removing \n from stream
        std::getline(std::cin, trash);

        // Constructing the dictionary
        std::map<std::string, std::string> dic = buildDic(M);

        /*std::cout << std::endl;
        for (auto elem : dic) {
            std::cout << elem.first << " " << elem.second << std::endl;
        }*/

        translateSong(dic, N);
    }
    
    return 0;
}