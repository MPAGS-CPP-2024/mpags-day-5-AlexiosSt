#include "CipherFactory.hpp"
#include "PlayfairCipher.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"
#include <memory>

std::unique_ptr<Cipher> CipherFactory::makeCipher(const CipherType type,
            const std::string& key){
    switch (type){
        case CipherType::Caesar:
            return std::make_unique<CaesarCipher>(key);
        
        case CipherType::Playfair:
            return std::make_unique<PlayfairCipher>(key);

        case CipherType::Vigenere:
            return std::make_unique<VigenereCipher>(key);
    }
    return std::unique_ptr<Cipher>{};
}