//! Unit Tests for MPAGSCipher Cipher Classes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "PlayfairCipher.hpp"
#include "CaesarCipher.hpp"
#include "VigenereCipher.hpp"

bool testCipher( const Cipher& cipher, const CipherMode mode,
const std::string& inputText, const std::string& outputText){

    bool outcome {cipher.applyCipher(inputText, mode)==outputText};
    return outcome;
}

TEST_CASE("Vigenere Cipher encryption", "[vigenere]") {
  VigenereCipher cc{"hello"};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES",
      "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ") );
}

TEST_CASE("Vigenere Cipher decryption", "[vigenere]") {
  VigenereCipher cc{"hello"};
  REQUIRE( testCipher(cc, CipherMode::Decrypt, "ALTDWZUFTHLEWZBNQPDGHKPDCALPVSFATWZUIPOHVVPASHXLQSDXTXSZ",
      "THISISQUITEALONGMESSAGESOTHEKEYWILLNEEDTOREPEATAFEWTIMES") );
}

TEST_CASE("Playfair Cipher encryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( testCipher(cc, CipherMode::Encrypt, "BOBISSOMESORTOFJUNIORCOMPLEXXENOPHONEONEZEROTHING",
    "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA") );
}

TEST_CASE("Playfair Cipher decryption", "[playfair]") {
  PlayfairCipher cc{"hello"};
  REQUIRE( testCipher(cc, CipherMode::Decrypt, "FHIQXLTLKLTLSUFNPQPKETFENIOLVSWLTFIAFTLAKOWATEQOKPPA",
    "BOBISXSOMESORTOFIUNIORCOMPLEXQXENOPHONEONEZEROTHINGZ") );
}

TEST_CASE("Caesar Cipher encryption", "[caesar]")
{
    CaesarCipher cc{10};
    REQUIRE( testCipher(cc, CipherMode::Encrypt, "HELLOWORLD", "ROVVYGYBVN") );
}

TEST_CASE("Caesar Cipher decryption", "[caesar]")
{
    CaesarCipher cc{10};
    REQUIRE( testCipher(cc, CipherMode::Decrypt, "ROVVYGYBVN", "HELLOWORLD") );
}