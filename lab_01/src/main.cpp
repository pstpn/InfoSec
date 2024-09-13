#include <iostream>

#include "enigma.hpp"
#include "rotor.hpp"

int main() {
    const std::vector<Rotor> rotors{
        Rotor{std::vector<char>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25}, 25},
        Rotor{std::vector<char>{20, 21, 22, 23, 24, 25, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 25},
        Rotor{std::vector<char>{7, 6, 5, 4, 3, 2, 1, 0, 24, 23, 22, 21, 20, 25, 8, 9, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10}, 25}
    };
    const Reflector reflector{std::vector<char>{25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}};
    const Commutator commutator{std::vector<char>{25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}};
    Enigma enigma{rotors, reflector, commutator};

    std::string s;
    std::cout << "\nInput word: ";
    std::cin >> s;

    const std::string encrypted_word = enigma.encrypt(s);
    std::cout << "Encrypted: " << encrypted_word << std::endl;
    std::cout << "Decrypted: " << enigma.decrypt(encrypted_word) << std::endl;
}