#include <iostream>
#include <string>
#include <cstdlib> // Para exit()
#include "./emisor_cpp/checksum.h"
#include "./emisor_cpp/hamming.h"
#include "./emisor_cpp/viterbi.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <hamming|viterbi|checksum> <binary_string>" << std::endl;
        return 1; 
    }

    std::string algorithm = argv[1];
    std::string binary_string = argv[2];
    //std::cout << "binary string: " << binary_string << std::endl;

    if (algorithm == "hamming") {
        std::string result = hamming(binary_string);
        std::cout << "Hamming result: " << result << std::endl;
    } 
    else if (algorithm == "viterbi") {
        std::string result = viterbi(binary_string);
        std::cout << "Viterbi result: " << result << std::endl;
    } 
    else if (algorithm == "checksum") {
        std::string result = checksum(binary_string);
        std::cout << "Checksum result: " << result << std::endl;
    } 
    else {
        std::cerr << "Invalid algorithm. Options: hamming, viterbi, checksum" << std::endl;
        return 1; 
    }

    return 0; 
}