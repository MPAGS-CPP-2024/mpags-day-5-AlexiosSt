#ifndef MPAGS_CIPHER_HPP
#define MPAGS_CIPHER_HPP

#include "CipherMode.hpp"
#include <string>

/**
 * \file Cipher.hpp
 * \brief Contains the declaration of the Cipher base class
 */

/**
 * \class Cipher
 * \brief Base class for Ciphers used to (de)encrypt text
 */
class Cipher{
    public:
    Cipher() = default;
    Cipher(const Cipher& rhs) = default;
    Cipher(Cipher&& rhs) = default;
    Cipher& operator=(const Cipher& rhs) = default;
    Cipher& operator=(Cipher&& rhs) = default;
    virtual ~Cipher() = default;

    virtual std::string applyCipher( const std::string& input,
        const CipherMode mode ) const = 0;
};

#endif