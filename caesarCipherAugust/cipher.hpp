#ifndef __CIPHER_HPP_INCLUDED__
#define __CIPHER_HPP_INCLUDED__

using namespace std;
/**
 * This class works as a Caesar Cipher encryptor/decryptor
 * for strings containing ASCII characters.
 */
class CaesarCipher {
	public:
		static string encrypt(string s, int offset);
		static string decrypt(string s, int offset);
};
#endif