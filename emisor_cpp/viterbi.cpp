#include <string>
#include "viterbi.h"
#include <iostream>

std::string viterbi(std::string binary_string) {
    std::string encoded_message;
    int s0 = 0, s1 = 0; // estado inicial del codificador
    
    for (char bit : binary_string) {
        if (bit != '0' && bit != '1') {
            throw std::invalid_argument("El mensaje debe ser una cadena de 0s y 1s");
        }
        
        int current_bit = bit - '0';
        int output0 = (current_bit + s1 + s0) % 2; // g0 = 1 + D + D^2
        int output1 = (current_bit + s1) % 2;      // g1 = 1 + D^2
        s0 = s1;
        s1 = current_bit;

        encoded_message += std::to_string(output0) + std::to_string(output1);
    }
    
    return encoded_message;
}