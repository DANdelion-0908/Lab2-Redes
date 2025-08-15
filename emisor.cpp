#include <iostream>
#include <string>
#include <cstdlib> // Para exit()
#include "./emisor_cpp/checksum.h"
#include "./emisor_cpp/hamming.h"
#include "./emisor_cpp/viterbi.h"

using namespace std; // Para quitar el std:: 

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <hamming|viterbi|checksum> <binary_string>" << endl;
        return 1; 
    }

    string algorithm = argv[1];
    string binary_string = argv[2];
    //cout << "binary string: " << binary_string << endl;

    if (algorithm == "hamming") {
        string result = hamming(binary_string);
        cout << "Hamming result: " << result << endl;
    } 
    else if (algorithm == "viterbi") {
        string result = viterbi(binary_string);
        cout << "Viterbi result: " << result << endl;
    } 
    else if (algorithm == "checksum") {
        string result = checksum(binary_string);
        cout << "Checksum result: " << result << endl;
    } 
    else {
        cerr << "Invalid algorithm. Options: hamming, viterbi, checksum" << std::endl;
        return 1; 
    }

    return 0; 
}