#include "ns3/crypto.h"

namespace ns3
{
uint32_t createDigitalSignature(char* privateKey, std::string message) {
	return 1;
}

bool verifyDigitalSignature(uint32_t digitalSignature, char* publicKey) {
	if(digitalSignature == 1) {
		return true;
	}
	return false;
}
}
