#include <cipher.h>
#include "../gtest-1.7.0/gtest.h"

TEST(CipherTest, HandlesEncrypt){
	EXPECT_EQ("a", encrypt("b", -1));
	EXPECT_EQ("c", encrypt("b", 1));
}

TEST(CipherTest, HandlesDecrypt){
	EXPECT_EQ("b", decrypt("a", -1));
	EXPECT_EQ("b", decrypt("c", 1));
}

// Man kan såklart göra fler tester - och kanske speciellt prova övergång mellan
// första och sista bokstaven i ascii - men det är lite överkurs här imo.
