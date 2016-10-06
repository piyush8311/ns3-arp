#include "ns3/crypto.h"
#include <string>
#include <cryptopp/files.h> 
namespace ns3
{

void createOneKeyPair(RSA::PrivateKey &privateKey, RSA::PublicKey &publicKey){
	AutoSeededRandomPool rng;
	InvertibleRSAFunction parameters;
	parameters.GenerateRandomWithKeySize(rng, 1536);

	RSA::PrivateKey privateKey_t(parameters);
	RSA::PublicKey publicKey_t(parameters);

	privateKey = privateKey_t;
	publicKey = publicKey_t;
	return;
}


SecByteBlock createDigitalSignature(RSA::PrivateKey privateKey, std::string message) {

	//cout<<"Entering createDigitalSignature\n";
	AutoSeededRandomPool rng;
	// Signer object
	RSASS<CryptoPP::PKCS1v15, CryptoPP::SHA1>::Signer signer(privateKey);

	// Create signature space 	 	
	size_t length = signer.MaxSignatureLength();
	SecByteBlock signature(length);

	// Sign message
	length = signer.SignMessage(rng, (const byte*) message.c_str(),
    message.length(), signature);

	// Resize now we know the true size of the signature
	signature.resize(length);

	//cout << "Exiting createDigitalSignature\n";
	return signature;
}

bool verifyDigitalSignature(SecByteBlock signature, RSA::PublicKey publicKey, std::string message) {
	// Verifier object
	/*cout<<"Entering verifyDigitalSignature\n";
	cout<<message<<" "<<"\n";
	std::string m_digitalSignature_string(reinterpret_cast<const char*>(signature.data()),signature.size());
	cout<<m_digitalSignature_string<<"\n";*/

	CryptoPP::FileSink sink("verifierPublic.key");
	publicKey.Save(sink);
	RSASS<CryptoPP::PKCS1v15, CryptoPP::SHA1>::Verifier verifier(publicKey);

	// Verify
	bool result = verifier.VerifyMessage((const byte*)message.c_str(),
    message.length(), signature, signature.size());

	// Result
	//cout<<"Exiting verifyDigitalSignature\n";
	if(true == result) {
    	return true;
	} else {
    	return false;
	}
	
}
}
