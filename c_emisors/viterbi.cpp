#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

// codificando usando cosidog conolucional
vector<string> convolutional_encode(const string &input){
    vector<string> result;
    int s0 = 0, s1 = 0;
    for (char bit : input) {
        if (bit != '0' && bit != '1') {
            throw invalid_argument("El mensaje debe ser solo de 0s y 1s");
        }
        
        int current_bit = bit - '0';
        int output0 = (current_bit + s1 + s0) % 2; // g0 = 1 + D + D^2
        int output1 = (current_bit + s1) % 2;      // g1 = 1 + D^2
        s0 = s1;
        s1 = current_bit;
        
        result.push_back(to_string(output0) + to_string(output1));
    }
    
    return result;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        cerr << "Uso: " << argv[0] << " <mensaje_binario>" << endl;
        return 1;
    }
    
    string input = argv[1];
    
    try {
        vector<string> encoded = convolutional_encode(input);
        cout << "Mensaje original: " << input << endl;
        cout << "Mensaje codificado: ";
        for (const string &pair : encoded) {
            cout << pair;
        }
        cout << endl;
    } catch (const invalid_argument &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}