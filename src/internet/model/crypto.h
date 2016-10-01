/*
 * crypto.h
 *
 *  Created on: 25-Sep-2016
 *      Author: piyush
 */

#ifndef NS_3_25_SRC_INTERNET_MODEL_CRYPTO_H_
#define NS_3_25_SRC_INTERNET_MODEL_CRYPTO_H_
#include <string>
#include <stdint.h>

#include "cryptopp/secblock.h"
using CryptoPP::SecByteBlock;

#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

#include <cryptopp/sha.h>
#include <cryptopp/rsa.h>
using CryptoPP::InvertibleRSAFunction;
using CryptoPP::RSA;
using CryptoPP::RSASS;

#include "cryptopp/integer.h"
using CryptoPP::Integer;

#include "cryptopp/pubkey.h"
using CryptoPP::PrivateKey;
using CryptoPP::PublicKey;

#include "cryptopp/hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "cryptopp/osrng.h"
using CryptoPP::AutoSeededRandomPool;

namespace ns3 {
void createOneKeyPair(RSA::PrivateKey &privateKey, RSA::PublicKey &publicKey);

SecByteBlock createDigitalSignature(RSA::PrivateKey privateKey, std::string message);

bool verifyDigitalSignature(SecByteBlock signature, RSA::PublicKey publicKey, std::string message);

}

#endif /* NS_3_25_SRC_INTERNET_MODEL_CRYPTO_H_ */
