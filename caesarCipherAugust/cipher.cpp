#include "cipher.hpp"

std::string CaesarCipher::encrypt(std::string s, int offset){
	std::string::iterator it;
	std::string result;
	for (it = s.begin() ; it < s.end(); it++){
		char current = *it;
		result.push_back((current+offset)%256);
		
	}
	return result;
}

string CaesarCipher::decrypt(string s, int offset){
	std::string::iterator it;
	std::string result;
	return 0;
}


