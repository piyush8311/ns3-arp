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

namespace ns3 {

uint32_t createDigitalSignature(char* privateKey, std::string message);

bool verifyDigitalSignature(uint32_t digitalSignature, char* publicKey);

}

#endif /* NS_3_25_SRC_INTERNET_MODEL_CRYPTO_H_ */
