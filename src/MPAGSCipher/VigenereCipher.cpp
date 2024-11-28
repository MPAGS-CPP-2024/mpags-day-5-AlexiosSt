#include "VigenereCipher.hpp"
#include "Alphabet.hpp"

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

VigenereCipher::VigenereCipher(const std::string& key)
{
    this->setKey(key);
}

void VigenereCipher::setKey(const std::string& key)
{
    string amsg{""};
    key_=key;

    //Key to uppercase!
    std::transform(std::begin(key_), std::end(key_), std::begin(key_),
                   ::toupper);
    
    //Remove non-alpha chars from key!
    key_.erase(std::remove_if(std::begin(key_), std::end(key_),
                              [](char c) { return !std::isalpha(c); }),
               std::end(key_));
    
    if (key_.empty()) {
        cerr<<"[warning] The formatted key is empty i am afraid... I change it to sth default\n";
        key_="HELLOKEY";
    }

    //LOOP over key: - find letter position
    //               - create caesar c. using the position as key
    //
    charLookup_.clear();

    for (auto& ch : key_){
        if (charLookup_.find(ch) != charLookup_.end()){
            continue;
        }

        for (size_t i{0}; i<Alphabet::size; i++){
            if (ch==Alphabet::alphabet[i]) {
                //cout<<ch<<" "<<i<<endl;
                CaesarCipher myc{i};
                auto pt= make_pair(ch, myc);
                charLookup_.insert(pt);
                break;
            }
        }
    }
    
    //amsg=key_+" is the key for now!";
    //cout<<amsg<<endl;
}

std::string VigenereCipher::applyCipher(const std::string& inTxt, const CipherMode cMode) const{

    string outTxt{""}; 
    string newK{key_};
    size_t offset{0};

    //For each ch in inTxt:
    //      - find the corresponding letter in the key
    //      - repeating/truncating as required
    //      - find the caesar cipher from the lookup
    //      - run the en/decryption
    
    for (size_t i{0}; i<inTxt.size(); i++){
        size_t keyLen{newK.size()};
        if (i>keyLen-1) {
            newK+=newK[offset];
            offset++;
        }
        //cout<<i<<" "<<newK[i] <<"("<<newK.size()<<")"<<endl;    //is the respective letter in the key 
        
        auto itercc = charLookup_.find(newK[i]);
        if (itercc==charLookup_.end()) 
            return "[error] Letter not found in the formatted input text!!";
        
        auto& [keychar, cipher]{*itercc};
        string prech(1, inTxt[i]);

        auto newch = cipher.applyCipher(prech, cMode);
        outTxt+=newch;
    }

    //cout<<"your key is now:"<<newK<<endl;
    
    return outTxt;
}
