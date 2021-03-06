/*****************************************************************
 *    
 *  OTEnvelope.cpp
 *  
 */

/************************************************************
 -----BEGIN PGP SIGNED MESSAGE-----
 Hash: SHA256
 
 *                 OPEN TRANSACTIONS
 *
 *       Financial Cryptography and Digital Cash
 *       Library, Protocol, API, Server, and GUI 
 *    
 *    	 -- Anonymous Numbered Accounts.
 *    	 -- Untraceable Digital Cash.
 *    	 -- Triple-Signed Receipts.
 *    	 -- Cheques, Vouchers, Transfers, Inboxes.
 *    	 -- Basket Currencies, Markets, Payment Plans.
 *    	 -- Signed, XML, Ricardian-style Contracts.
 *    
 *  Copyright (C) 2010-2012 by "Fellow Traveler" (A pseudonym)
 *
 *  EMAIL:
 *  FellowTraveler@rayservers.net
 *  
 *  BITCOIN:  1NtTPVVjDsUfDWybS4BwvHpG2pdS9RnYyQ
 *
 *  KEY FINGERPRINT (PGP Key in license file):
 *  9DD5 90EB 9292 4B48 0484  7910 0308 00ED F951 BB8E
 *
 *  OFFICIAL PROJECT WIKI(s):
 *  https://github.com/FellowTraveler/Moneychanger
 *  https://github.com/FellowTraveler/Open-Transactions/wiki 
 *
 *  WEBSITE:
 *  http://www.OpenTransactions.org/
 *    
 *  Components and licensing:
 *   -- Moneychanger..A Java client GUI.....LICENSE:.....GPLv3
 *   -- OTLib.........A class library.......LICENSE:...LAGPLv3 
 *   -- OT-API........A client API..........LICENSE:...LAGPLv3
 *   -- testwallet....Command-line client...LICENSE:...LAGPLv3
 *   -- OT-Server.....Server Application....LICENSE:....AGPLv3
 *  Github.com/FellowTraveler/Open-Transactions/wiki/Components
 *
 *  All of the above OT components were designed and written by
 *  Fellow Traveler, with the exception of Moneychanger, which
 *  was contracted out to Vicky C (livewire_3001@yahoo.com).
 *
 *  -----------------------------------------------------
 *
 *   LICENSE:
 *   This program is free software: you can redistribute it
 *   and/or modify it under the terms of the GNU Affero
 *   General Public License as published by the Free Software
 *   Foundation, either version 3 of the License, or (at your
 *   option) any later version.
 *    
 *   ADDITIONAL PERMISSION under the GNU Affero GPL version 3
 *   section 7: (This paragraph applies only to the LAGPLv3
 *   components listed above.) If you modify this Program, or
 *   any covered work, by linking or combining it with other
 *   code, such other code is not for that reason alone subject
 *   to any of the requirements of the GNU Affero GPL version 3.
 *   (==> This means if you are only using the OT-API, then you
 *   don't have to open-source your code--only your changes to
 *   Open Transactions itself must be open source. Similar to
 *   LGPLv3, except it applies to software-as-a-service, not
 *   just to distributing binaries.)
 *
 *   Extra WAIVER for OpenSSL, Lucre, and all other libraries
 *   used by Open Transactions: This program is released under
 *   the AGPL with the additional exemption that compiling,
 *   linking, and/or using OpenSSL is allowed. The same is true
 *   for any other open source libraries included in this
 *   project: complete waiver from the AGPL is hereby granted to
 *   compile, link, and/or use them with Open Transactions,
 *   according to their own terms, as long as the rest of the
 *   Open Transactions terms remain respected, with regard to
 *   the Open Transactions code itself.
 *    
 *   Lucre License:
 *   This code is also "dual-license", meaning that Ben Lau-
 *   rie's license must also be included and respected, since
 *   the code for Lucre is also included with Open Transactions.
 *   See Open-Transactions/OTLib/Lucre/LUCRE_LICENSE.txt
 *   The Laurie requirements are light, but if there is any
 *   problem with his license, simply remove the Lucre code.
 *   Although there are no other blind token algorithms in Open
 *   Transactions (yet. credlib is coming), the other functions
 *   will continue to operate.
 *   -----------------------------------------------------
 *   You should have received a copy of the GNU Affero General
 *   Public License along with this program.  If not, see:
 *   http://www.gnu.org/licenses/
 *
 *   If you would like to use this software outside of the free
 *   software license, please contact FellowTraveler.
 *   (Unfortunately many will run anonymously and untraceably,
 *   so who could really stop them?)
 *   
 *   DISCLAIMER:
 *   This program is distributed in the hope that it will be
 *   useful, but WITHOUT ANY WARRANTY; without even the implied
 *   warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *   PURPOSE.  See the GNU Affero General Public License for
 *   more details.
 -----BEGIN PGP SIGNATURE-----
 Version: GnuPG v1.4.11 (Darwin)
 
 iQIcBAEBCAAGBQJOjvvUAAoJEAMIAO35UbuOBlMP/1LX0xJ9CrTOe1G/mgc+VygT
 JPVZDAbQDL/lJXOZMbaPJ/GaLXyEnTViHp97ERrlVuBQz+9uonIKCmPqAGYGVBG1
 MGV2QcscXU2aOUT1VPf2OYEOIul0h8FX2lixfqouH9/OkVsGRLr79Zu8z3zdsO4R
 ktQtjZEU6lnL2t6cmp/cuXlQnbz1xvxd56xNDR11YP07Z4x+CuDB4EAK+P9TfCwn
 tqq5yJmxJM9HtMoi3cUU7kXodKm1n1YZt7O46DOxHqbXqErHChN1ekSK0fXad614
 Gmh+5JfvHjx5XoFWMxb46aAAcUiG8+QpFBcKtSYP2X96k1ylgxMCzrK60ec/MxKV
 BzvP00OJ6PzzrTlcUaCgJ8ZX+0scOMvW0XKioEorozKSWNFvT4Drc4Thhy8u9ET3
 ru1enNFrjdxKjw2+ZTQcKSZjSRx2kMQ2od/dkqUlhe/M1cHGhseH6ls7pItrkykE
 ufZ9GlZoxYE+FRatIBPneT9WwsvFFvH+i6cQ/MM9pbTr19g6VPzVZ4U9E65BbTDB
 czITynH+uMtJLbprtCdQlsI+vqTgYNoY8AUsmnr1qUkp020qGlvwfCJVrooisTmm
 yIh+Yp/KBzySU3inzclaAfv102/t5xi1l+GTyWHiwZxlyt5PBVglKWx/Ust9CIvN
 6h9BYZFTZrh/OwBXCdAv
 =MUfS
 -----END PGP SIGNATURE-----
 **************************************************************/

#include <string>

#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>

extern "C"
{	
#include <openssl/evp.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/rand.h>
    
#ifdef _WIN32
#include <WinSock.h>
#else
#include <arpa/inet.h> /* For htonl() */
#endif
}

#include "OTStorage.h"

#include "OTAsymmetricKey.h"
#include "OTASCIIArmor.h"
#include "OTPseudonym.h"
#include "OTEnvelope.h"
#include "OTLog.h"



/* 
 
 DERIVING KEYS FROM A PASSWORD
 
 #include <evp.h>
 #include <openssl/rand.h>
 
 char * passwd = "secret password";
 
 unsigned char salt[8];
 
 int iter = 65535;
 
 unsigned char key[16];
 
 RAND_bytes(salt, sizeof(salt));
 
 // From OTPassword.h:
 // size_t strnlen(const char *s, size_t max) 

 PKCS5_PBKDF2_HMAC_SHA1(passwd, strnlen(passwd, BIGGEST_POSSIBLE_PWD), salt, sizeof(salt), iter, sizeof(key), key);
 
 AES_KEY aes_key;
 AES_set_encrypt_key(key, 128, aes_key);
 
 
 // perform aes encryption here...
 
 unsigned char iv[16];
 RAND_bytes(iv,   sizeof(iv));

 
 -----------------------------------------------------------

 DEALING WITH SALT:
 
 // Note: Salt is generated randomly when the symmetric key is created from the passphrase.
 // Then the salt must be STORED with the symmetric key, so that the passphrase / salt / encrypted symmetric key
 // can later be used to produce a decrypted symmetric key (which should not stay in memory for long...)
 //
 
int main()
{
	char *pass = "password";
	char *salt = "12340000";
	int ic = 1;
	unsigned char buf[1024];

	ic = 1;
	PKCS5_PBKDF2_HMAC_SHA1(pass, strlen(pass), (unsigned char*)salt, strlen(salt), ic, 32+16, buf);
	printf("PKCS5_PBKDF2_HMAC_SHA1(\"%s\", \"%s\", %d)=\n", pass, salt, ic);
	print_hex(buf, 32+16);

 // NOTE: The above function is used INSTEAD of the one below!
 
    ic = 1;
	EVP_BytesToKey(EVP_aes_256_cbc(), EVP_sha1(), (unsigned char*)salt, (unsigned char*)pass, strlen(pass), ic, buf, buf+32);
	printf("EVP_BytesToKey(\"%s\", \"%s\", %d)=\n", pass, salt, ic);
	print_hex(buf, 32+16);

	return(0);
}
 
 

 
 
 int EVP_BytesToKey(const EVP_CIPHER *type,const EVP_MD *md,
                    const unsigned char *salt,
                    const unsigned char *data, int datal,
                    int count,
                    unsigned char *key,unsigned char *iv);
 
 EVP_BytesToKey() derives a key and IV from various parameters. 
    type is the cipher to derive the key and IV for.
    md is the message digest to use. 
    The salt paramter is used as a salt in the derivation: it should point to an 8 byte buffer or NULL if no salt is used. 
    data is a buffer containing datal bytes which is used to derive the keying data. 
    count is the iteration count to use. 
 The derived key and IV will be written to key and iv respectively.
 -----------------------------------------------------------
 
 
 
 The initialization vector needs to be known to Alice AND Bob.
   And it needs to be transmitted at the time the session key is negotiated.
 
 So there should probably be a "OTEnvelope" class which stores the IV
 as well as the session key, and which can be encrypted with a public key 
 and decrypted with a private key. The keys can just be passed in or whatever. 
 
 
int PKCS5_PBKDF2_HMAC_SHA1	(
    const void * 	password,
    size_t          password_len,
    const void * 	salt,
    size_t          salt_len,
    unsigned long 	iter,
    size_t          keylen,
    void *          key 
)	
 
 
 OPENSSL's version:
 
 int PKCS5_PBKDF2_HMAC_SHA1(
    const char *pass, int passlen,
    const unsigned char *salt, int saltlen,
    int iter,
    int keylen,  unsigned char *out);

 */



// ------------------------------------------------------------------------



/*
 // TOdo: make this so you can pass in a password, or you can pass NULL
 // and then it will use the GetPasswordCallback() method to collect one
 // from the user.
 
 OT_OPENSSL_CALLBACK * OTAsymmetricKey::GetPasswordCallback()

 #define OPENSSL_CALLBACK_FUNC(name) extern "C" int (name)(char *buf, int size, int rwflag, void *userdata)

 */

bool OTSymmetricKey::GenerateKey(const OTPassword & thePassword)
{
    const char * szFunc = "OTSymmetricKey::GenerateKey";
    
    OT_ASSERT(m_nIterationCount > 1000);
    OT_ASSERT(!m_bIsGenerated);
    OT_ASSERT(thePassword.isPassword());

    // This derived_key memory is unused, except to help us allocate a 16-byte derived key OTPassword
    // object. (OTPassword stores its own memory internally, and merely copies the derived key, which
    // we then overwrite in the call to PKCS5_PBKDF2_HMAC_SHA1.)
    //
    unsigned char   derived_key[OT_DEFAULT_SYMMETRIC_KEY_SIZE];
    // theDerivedKey will be populated with its actual data in the call to PKCS5_PBKDF2_HMAC_SHA1.
    OTPassword      theDerivedKey(static_cast<void *>(&derived_key[0]), OT_DEFAULT_SYMMETRIC_KEY_SIZE);
	// --------------------------------------------------
    OTPassword      theActualKey;
    
    if (OT_DEFAULT_SYMMETRIC_KEY_SIZE != theActualKey.randomizeMemory(OT_DEFAULT_SYMMETRIC_KEY_SIZE))
	{
		OTLog::vError("%s: Failed generating symmetric key. (Returning false.)\n", szFunc);
		return false;
	}
	// --------------------------------------------------
	if (false == m_dataSalt.Randomize( OT_DEFAULT_SYMMETRIC_SALT_SIZE )) 
	{
		OTLog::vError("%s: Failed generating random salt. (Returning false.)\n", szFunc);
		return false;
	}    
	// --------------------------------------------------
	if (false == m_dataIV.Randomize( OT_DEFAULT_SYMMETRIC_IV_SIZE )) 
	{
		OTLog::vError("%s: Failed generating iv for encrypting a symmetric key. (Returning false.)\n", szFunc);
		return false;
	}
	// --------------------------------------------------
    const char * char_p_password_contents = thePassword.getPassword();
    const size_t size_t_password_length   = static_cast<const size_t>(thePassword.getPasswordSize());
    
    unsigned char * char_p_derived_contents  = static_cast<unsigned char *>(theDerivedKey.getMemoryWritable());
    const size_t size_t_derived_length    = static_cast<const size_t>(theDerivedKey.getMemorySize());
    
    const unsigned char * uchar_p_salt_contents = static_cast<const unsigned char *>(m_dataSalt.GetPayloadPointer());
    const size_t size_t_salt_length       = static_cast<const size_t>(m_dataSalt.GetSize());
    // -----------------
    // Key derivation.
    //
    // int PKCS5_PBKDF2_HMAC_SHA1(const char*, int, const unsigned char*, int, int, int, unsigned char*)’
    //
    PKCS5_PBKDF2_HMAC_SHA1(char_p_password_contents,  size_t_password_length,
                           uchar_p_salt_contents,      size_t_salt_length,
                           m_nIterationCount,
                           size_t_derived_length,    char_p_derived_contents);
    // -------------------------------------------------------------------------------------------------
    //
    // Below this point, theDerivedKey contains a new symmetric key derived from the salt, the iteration
    // count, and the password that was passed in. We will store the salt and iteration count inside this
    // OTSymmetricKey object, and we'll store an encrypted copy of the ActualKey, encrypted to the Derived Key.
    // We'll also store the IV for that encryption bit.
    //
    // Encrypt theActualKey using theDerivedKey, which is clear/raw already. (Both are OTPasswords.)
    // Put the result into the OTPayload m_dataEncryptedKey.
    //
    const bool bEncryptedKey = OTEnvelope::Encrypt(theDerivedKey,  // theDerivedKey is a symmetric key, in clear form. Used for encrypting theActualKey.
                                                   // -------------------------------
                                                   static_cast<const char *>(theActualKey.getMemory()), // This is the Plaintext that's being encrypted.
                                                   static_cast<uint32_t>(theActualKey.getMemorySize()),
                                                   // -------------------------------
                                                   m_dataIV,
                                                   // -------------------------------
                                                   m_dataEncryptedKey); // OUTPUT. (Ciphertext.)    
    m_bIsGenerated = bEncryptedKey;
    return m_bIsGenerated;
}


// ------------------------------------------------------------------------
/*
 To generate a symmetric key:
 
    1. First we generate the plain symmetric key itself using RAND_bytes().
    2. Then we generate the salt using RAND_bytes()
    3. Then we use thePassword and the salt to derive a key using PBKDF2.
    4. Then we encrypt the plain symmetric key using the derived key from PBKDF2.
    5. Then we store the salt and the encrypted symmetric key. (We discard the derived key.)
    6. (Use the plain symmetric key to encrypt the plaintext.)
 
 To use the symmetric key:
    
    1. We use thePassword from user input, and the stored salt, with PBKDF2 to derive a key.
    2. Use the derived key to decrypt the encrypted symmetric key.
    3. (Use the decrypted symmetric key to decrypt the ciphertext.)
 */

// Done:  add a "get Key" function which takes the OTPassword, generates the derived key using salt already on
// OTSymmetricKey objet, then decrypts the encrypted symmetric key (using derived key) and returns clear symmetric
// key back as another OTPassword object.

// Assumes key is already generated. Tries to get the raw clear key from its encrypted form, via its password.

// If returns true, theRawKeyOutput will contain the decrypted symmetric key, in an OTPassword object.
// Otherwise returns false if failure.
//
bool OTSymmetricKey::GetRawKey(const OTPassword & thePassword, OTPassword & theRawKeyOutput) const
{
//    const char * szFunc = "OTSymmetricKey::GetKey";
    
    OT_ASSERT(m_bIsGenerated);
    OT_ASSERT(thePassword.isPassword());
    
    // ------------------------------------
    // This derived_key memory is unused, except to help us allocate a 16-byte derived key OTPassword
    // object. (OTPassword stores its own memory internally, and merely copies derived_key, which
    // we then overwrite with the real derived key in the call to PKCS5_PBKDF2_HMAC_SHA1.)
    //
    unsigned char   derived_key[OT_DEFAULT_SYMMETRIC_KEY_SIZE];
    // theDerivedKey will be populated with its actual data in the call to PKCS5_PBKDF2_HMAC_SHA1.
    OTPassword      theDerivedKey(static_cast<void *>(&derived_key[0]), OT_DEFAULT_SYMMETRIC_KEY_SIZE);
	// --------------------------------------------------
    const char * char_p_password_contents = const_cast<char *>(thePassword.getPassword());
    const size_t size_t_password_length   = static_cast<const size_t>(thePassword.getPasswordSize());
    
    unsigned char * uchar_p_derived_contents  = static_cast<unsigned char *>(theDerivedKey.getMemoryWritable());
    const size_t size_t_derived_length    = static_cast<const size_t>(theDerivedKey.getMemorySize());
    
    const unsigned char * uchar_p_salt_contents  = static_cast<const unsigned char *>(m_dataSalt.GetPayloadPointer());
    const size_t size_t_salt_length       = static_cast<const size_t>(m_dataSalt.GetSize());
    // -----------------
    // Key derivation.
    //
    // int PKCS5_PBKDF2_HMAC_SHA1(const char*, int, const unsigned char*, int, int, int, unsigned char*)
    //
    PKCS5_PBKDF2_HMAC_SHA1(char_p_password_contents, size_t_password_length,
                           uchar_p_salt_contents,     size_t_salt_length,
                           m_nIterationCount,
                           size_t_derived_length,    uchar_p_derived_contents);
    // -------------------------------------------------------------------------------------------------
    //
    // Below this point, theDerivedKey contains a derived symmetric key, from the salt, the iteration
    // count, and the password that was passed in. The salt and iteration count were both stored inside this
    // OTSymmetricKey object when this key was originally generated, and we store an encrypted copy of the
    // ActualKey already, as well--encrypted to the Derived Key. (We also store the IV from that encryption bit.)
    //
    // Decrypt theActualKey using theDerivedKey, which is clear/raw already. (Both are OTPasswords.)
    // Put the result into theRawKeyOutput.
    //
    // -----------------

    const bool bDecryptedKey = OTEnvelope::Decrypt(theDerivedKey, // theDerivedKey is a symmetric key, in clear form. Used for decrypting m_dataEncryptedKey into theRawKeyOutput.
                                                   // -------------------------------
                                                   static_cast<const char *>(m_dataEncryptedKey.GetPayloadPointer()), // This is the Ciphertext.  
                                                   m_dataEncryptedKey.GetSize(),
                                                   // -------------------------------
                                                   m_dataIV,
                                                   // -------------------------------
                                                   theRawKeyOutput); // OUTPUT. (Recovered plaintext of symmetric key.) You can pass OTPassword& OR OTPayload& here (either will work.)
    return bDecryptedKey;
}



// ------------------------------------------------------------------------


bool OTSymmetricKey::SerializeTo(OTString & strOutput, bool bEscaped/*=false*/) const
{
    OTASCIIArmor ascOutput;
    
    if (this->SerializeTo(ascOutput))
        return ascOutput.WriteArmoredString(strOutput, "SYMMETRIC KEY", bEscaped);

    return false;
}


bool OTSymmetricKey::SerializeFrom(const OTString & strInput, bool bEscaped/*=false*/)
{
    OTASCIIArmor ascInput;

    if (strInput.Exists() && ascInput.LoadFromString(const_cast<OTString &>(strInput), 
                                                     bEscaped, 
                                                     "-----BEGIN OT ARMORED SYMMETRIC KEY"))
        return true;

    return false;
}


// ------------------------------------------------------------------------


bool OTSymmetricKey::SerializeTo(OTASCIIArmor & ascOutput) const
{
    OTPayload theOutput;
    
    if (this->SerializeTo(theOutput))
    {
        ascOutput.SetData(theOutput);
        return true;
    }
    
    return false;
}


bool OTSymmetricKey::SerializeFrom(const OTASCIIArmor & ascInput)
{
    OTPayload theInput;
    
    if (ascInput.Exists() && ascInput.GetData(theInput))
    {
        return this->SerializeFrom(theInput);
    }
    return false;
}


// ------------------------------------------------------------------------


bool OTSymmetricKey::SerializeTo(OTPayload & theOutput) const
{
    // -----------------------------------------------
    uint16_t   n_is_generated    = static_cast<uint16_t>(htons(m_bIsGenerated ? 1 : 0)); 
    uint16_t   n_key_size_bits   = static_cast<uint16_t>(htons(static_cast<uint16_t>(m_nKeySize))); 
    
    uint32_t   n_iteration_count = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_nIterationCount))); 
    
    uint32_t   n_salt_size       = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_dataSalt.GetSize()))); 
    uint32_t   n_iv_size         = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_dataIV.GetSize()))); 
    uint32_t   n_enc_key_size    = static_cast<uint32_t>(htonl(static_cast<uint32_t>(m_dataEncryptedKey.GetSize()))); 
    // -----------------------------------------------
    theOutput.Concatenate(static_cast<void *>(&n_is_generated),   
                          static_cast<uint32_t>(sizeof(n_is_generated)));
    theOutput.Concatenate(static_cast<void *>(&n_key_size_bits),   
                          static_cast<uint32_t>(sizeof(n_key_size_bits)));
    theOutput.Concatenate(static_cast<void *>(&n_iteration_count),   
                          static_cast<uint32_t>(sizeof(n_iteration_count)));
    // -------------------------
    theOutput.Concatenate(static_cast<void *>(&n_salt_size),   
                          static_cast<uint32_t>(sizeof(n_salt_size)));
    theOutput.Concatenate(m_dataSalt.GetPayloadPointer(),
                          m_dataSalt.GetSize());
    // -------------------------
    theOutput.Concatenate(static_cast<void *>(&n_iv_size),   
                          static_cast<uint32_t>(sizeof(n_iv_size)));
    theOutput.Concatenate(m_dataIV.GetPayloadPointer(),
                          m_dataIV.GetSize());
    // -------------------------
    theOutput.Concatenate(static_cast<void *>(&n_enc_key_size),   
                          static_cast<uint32_t>(sizeof(n_enc_key_size))); 
    theOutput.Concatenate(m_dataEncryptedKey.GetPayloadPointer(),
                          m_dataEncryptedKey.GetSize());
    
    return true;
}

// ------------------------------------------------------------------------


// Notice I don't theInput.reset(), because what if this
// key was being read from a larger file containing several
// keys?  I should just continue reading from the current
// position, and let the CALLER reset first, if that's his
// intention.
//
bool OTSymmetricKey::SerializeFrom(OTPayload & theInput)
{
    const char * szFunc = "OTSymmetricKey::SerializeFrom";
    
    int  nRead  = 0;
    
    // ****************************************************************************
    //
    // Read network-order "is generated" flag. (convert to host order) 
    //    
    uint16_t  n_is_generated = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<char*>(&n_is_generated), 
                                       sizeof(n_is_generated))))
	{
		OTLog::vError("%s: Error reading n_is_generated.\n", szFunc);
		return false;
	}
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    //
    uint16_t host_is_generated = ntohs(n_is_generated);
    
    if (1 == host_is_generated)
        m_bIsGenerated = true;
    else if (0 == host_is_generated)
        m_bIsGenerated = false;
    else
    {
        OTLog::vError("%s: Error: host_is_generated, Bad value: %d. (Expected 0 or 1.)\n",
                      szFunc, static_cast<int>(host_is_generated));
        return false;
    }
    // ****************************************************************************
    
    
    
    // ****************************************************************************
    //
    // Read network-order "key size in bits". (convert to host order) 
    //    
    uint16_t  n_key_size_bits = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<char*>(&n_key_size_bits), 
                                       sizeof(n_key_size_bits))))
	{
		OTLog::vError("%s: Error reading n_key_size_bits.\n", szFunc);
		return false;
	}
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.

    m_nKeySize = static_cast<unsigned int>(ntohs(n_key_size_bits));
    
    // ****************************************************************************
    
    
    
    // ****************************************************************************
    //
    // Read network-order "iteration count". (convert to host order) 
    //    
    uint32_t  n_iteration_count = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<char*>(&n_iteration_count), 
                                       sizeof(n_iteration_count))))
	{
		OTLog::vError("%s: Error reading n_iteration_count.\n", szFunc);
		return false;
	}
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    
    m_nIterationCount = static_cast<int>(ntohl(n_iteration_count));
    
    // ****************************************************************************
    
    
    
    // ****************************************************************************
    //
    // Read network-order "salt size". (convert to host order) 
    //    
    uint32_t  n_salt_size = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<char*>(&n_salt_size), 
                                       sizeof(n_salt_size))))
	{
		OTLog::vError("%s: Error reading n_salt_size.\n", szFunc);
		return false;
	}
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    
    const uint32_t lSaltSize = ntohl(n_salt_size);
    
	// ----------------------------------------------------------------------------
    //
    // Then read the Salt itself.
    //
    m_dataSalt.SetPayloadSize(lSaltSize);
    
    if (0 == (nRead = theInput.OTfread(static_cast<char*>(const_cast<void *>(m_dataSalt.GetPayloadPointer())),
                                       static_cast<int>(lSaltSize))))
    {
        OTLog::vError("%s: Error reading salt for symmetric key.\n", szFunc);
        return false;
    }
    // ****************************************************************************
    
    
    
    
    // ****************************************************************************
    //
    // Read network-order "IV size". (convert to host order) 
    //    
    uint32_t  n_iv_size = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<char*>(&n_iv_size), 
                                       sizeof(n_iv_size))))
	{
		OTLog::vError("%s: Error reading n_iv_size.\n", szFunc);
		return false;
	}
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    
    const uint32_t lIVSize = ntohl(n_iv_size);
    
	// ----------------------------------------------------------------------------
    //
    // Then read the IV itself.
    //
    m_dataIV.SetPayloadSize(lIVSize);
    
    if (0 == (nRead = theInput.OTfread(static_cast<char*>(const_cast<void *>(m_dataIV.GetPayloadPointer())),
                                       static_cast<int>(lIVSize))))
    {
        OTLog::vError("%s: Error reading IV for symmetric key.\n", szFunc);
        return false;
    }
    // ****************************************************************************
    

    
    // ****************************************************************************
    //
    // Read network-order "encrypted key size". (convert to host order) 
    //    
    uint32_t  n_enc_key_size = 0;
    
    if (0 == (nRead = theInput.OTfread(reinterpret_cast<char*>(&n_enc_key_size), 
                                       sizeof(n_enc_key_size))))
	{
		OTLog::vError("%s: Error reading n_enc_key_size.\n", szFunc);
		return false;
	}
    // ----------------------------------------------------------------------------
	// convert from network to HOST endian.
    
    const uint32_t lEncKeySize = ntohl(n_enc_key_size);
    
	// ----------------------------------------------------------------------------
    //
    // Then read the Encrypted Key itself.
    //
    m_dataEncryptedKey.SetPayloadSize(lEncKeySize);
    
    if (0 == (nRead = theInput.OTfread(static_cast<char*>(const_cast<void *>(m_dataEncryptedKey.GetPayloadPointer())),
                                       static_cast<int>(lEncKeySize))))
    {
        OTLog::vError("%s: Error reading encrypted symmetric key.\n", szFunc);
        return false;
    }
    // ****************************************************************************

    return true;
}

// ------------------------------------------------------------------------












// ------------------------------------------------------------------------

OTSymmetricKey::OTSymmetricKey()
:   m_bIsGenerated(false), 
    m_nKeySize(OT_DEFAULT_SYMMETRIC_KEY_SIZE_BITS), // 128
    m_nIterationCount(OT_DEFAULT_ITERATION_COUNT) 
{
    
}

// ------------------------------------------------------------------------

OTSymmetricKey::OTSymmetricKey(const OTPassword & thePassword)
:   m_bIsGenerated(false), 
    m_nKeySize(OT_DEFAULT_SYMMETRIC_KEY_SIZE_BITS), // 128
    m_nIterationCount(OT_DEFAULT_ITERATION_COUNT)
{
//    const bool bGenerated = 
        this->GenerateKey(thePassword);
}

// ------------------------------------------------------------------------

OTSymmetricKey::~OTSymmetricKey()
{
//  Release(); // Unnecessary here, since the two data object members already will destruct.
}
// ------------------------------------------------------------------------

void OTSymmetricKey::Release()
{
    m_bIsGenerated    = false;
    m_nIterationCount = OT_DEFAULT_ITERATION_COUNT;
    m_nKeySize        = OT_DEFAULT_SYMMETRIC_KEY_SIZE_BITS; // 128
    
    m_dataSalt.Release();
    m_dataIV.Release();
    m_dataEncryptedKey.Release();    
}




// ------------------------------------------------------------------------

// Presumably this Envelope contains encrypted data (in binary form.)
// If you would like an ASCII-armored version of that data, just call this
// function.
// Should be called "Get Binary Envelope Encrypted Contents Into Ascii-Armored Form"
//
bool OTEnvelope::GetAsciiArmoredData(OTASCIIArmor & theArmoredText) const
{
	return theArmoredText.SetData(m_dataContents);
}

// Let's say you just retrieved the ASCII-armored contents of an encrypted envelope.
// Perhaps someone sent it to you, and you just read it out of his message.
// And let's say you want to get those contents back into binary form in an
// Envelope object again, so that they can be decrypted and extracted back as
// plaintext. Fear not, just call this function.
// should be called "Set Via Ascii Armored Data"
bool OTEnvelope::SetAsciiArmoredData(const OTASCIIArmor & theArmoredText)
{
	return theArmoredText.GetData(m_dataContents);
}




// ------------------------------------------------------------------------


/*
 void OTData::AESEncrypt(OTData & theKey)
{
	const unsigned char *iv="blahfuckheadfixthis";
	
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	
	const EVP_CIPHER * cipher = EVP_aes_128_cbc();
	
	EVP_EncryptInit(&ctx, cipher, theKey.GetPointer(), iv);
	
	EVP_EncryptUpdate(&ctx, out, &outlen, in, inlen);
	
	// unsigned char * out
	EVP_EncryptFinal(&ctx, out, &outlen);
	
	EVP_CIPHER_CTX_cleanup(&ctx);
}
 
 
 int EVP_EncryptInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type,
                     unsigned char  *key, unsigned char *iv);
 */

// #define OT_DEFAULT_SYMMETRIC_BUFFER_SIZE 4096


//static
bool OTEnvelope::Encrypt(const OTPassword & theRawSymmetricKey, // The symmetric key, in clear form.
                         // -------------------------------
                         const char *       szInput,            // This is the Plaintext.
                         const uint32_t     lInputLength,
                         // -------------------------------
                         const OTPayload &  theIV,              // (We assume this IV is already generated and passed in.)
                         // -------------------------------
                               OTPayload &  theEncryptedOutput) // OUTPUT. (Ciphertext.)
{
    const char * szFunc = "OTEnvelope::Encrypt(static)";
    // -----------------------------------------------  
    OT_ASSERT(OT_DEFAULT_SYMMETRIC_IV_SIZE   == theIV.GetSize());
    OT_ASSERT(OT_DEFAULT_SYMMETRIC_KEY_SIZE  == theRawSymmetricKey.getMemorySize());
    OT_ASSERT(NULL != szInput);
    OT_ASSERT(lInputLength > 0);
    // -----------------------------------------------    
	EVP_CIPHER_CTX	ctx;
    
	unsigned char	buffer    [ OT_DEFAULT_SYMMETRIC_BUFFER_SIZE ]; // 4096
    unsigned char	buffer_out[ OT_DEFAULT_SYMMETRIC_BUFFER_SIZE + EVP_MAX_IV_LENGTH];
    
	size_t			len     = 0;
    int				len_out = 0;
    // -----------------------------------------------
	memset(buffer,     0, OT_DEFAULT_SYMMETRIC_BUFFER_SIZE );
	memset(buffer_out, 0, OT_DEFAULT_SYMMETRIC_BUFFER_SIZE + EVP_MAX_IV_LENGTH);
    // -----------------------------------------------    
	//
	// This is where the envelope final contents will be placed.
    // including the size of the IV, the IV itself, and the ciphertext.
    //
	theEncryptedOutput.Release();
    
    // -----------------------------------------------
    class _OTEnv_Enc_stat
    {
    private:
        const char      *  m_szFunc;
        EVP_CIPHER_CTX	&  m_ctx;
    public:
        _OTEnv_Enc_stat(const char * param_szFunc,
                        EVP_CIPHER_CTX & param_ctx) :
            m_szFunc(param_szFunc),
            m_ctx(param_ctx)
        {
            OT_ASSERT(NULL != param_szFunc);

            EVP_CIPHER_CTX_init(&m_ctx);
        }
        ~_OTEnv_Enc_stat()
        {
            // EVP_CIPHER_CTX_cleanup returns 1 for success and 0 for failure.
            //
            if (0 == EVP_CIPHER_CTX_cleanup(&m_ctx))
                OTLog::vError("%s: Failure in EVP_CIPHER_CTX_cleanup. (It returned 0.)\n", m_szFunc);
        }
    };
    _OTEnv_Enc_stat  theInstance(szFunc, ctx);
    // -----------------------------------------------

    const EVP_CIPHER * cipher_type = EVP_aes_128_cbc();    	    
    
    // -----------------------------------------------
    if (!EVP_EncryptInit(&ctx, 
                         cipher_type, 
                         static_cast<unsigned char *>(const_cast<void *>(theRawSymmetricKey.getMemory())),
                         static_cast<unsigned char *>(const_cast<void *>(theIV.GetPayloadPointer()))))
    {
        OTLog::vError("%s: EVP_EncryptInit: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------
	//
    // Now we process the input and write the encrypted data to
	// the output.
	//
    uint32_t  lRemainingLength = lInputLength;
    uint32_t  lCurrentIndex    = 0;
    
    while (lRemainingLength > 0)
    {
        // If the remaining length is less than the default buffer size, then set len to remaining length.
        // else if remaining length is larger than or equal to default buffer size, then use the default buffer size.
        // Resulting value stored in len.
        //
        len = (lRemainingLength < OT_DEFAULT_SYMMETRIC_BUFFER_SIZE) ? lRemainingLength : OT_DEFAULT_SYMMETRIC_BUFFER_SIZE; // 4096
        lRemainingLength -= len;
        
        if (!EVP_EncryptUpdate(&ctx,
                               buffer_out,
                               &len_out,
                               const_cast<unsigned char *>(reinterpret_cast<const unsigned char *>(&(szInput [ lCurrentIndex ]))),
                               len))
        {
            OTLog::vError("%s: EVP_EncryptUpdate: failed.\n", szFunc);
			return false;
        }
        lCurrentIndex += len;
        theEncryptedOutput.Concatenate(static_cast<void *>(buffer_out), 
                                       static_cast<uint32_t>(len_out));
    }
    // -----------------------------------------------
    //
	if (!EVP_EncryptFinal(&ctx, buffer_out, &len_out))
    {
        OTLog::vError("%s: EVP_EncryptFinal: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------    
    // This is the "final" piece that is added from EncryptFinal just above.
    //
    theEncryptedOutput.Concatenate(static_cast<void *>(buffer_out), 
                                   static_cast<uint32_t>(len_out));    
    // -----------------------------------------------
    return true;
}



// Encrypt theInput as envelope using symmetric crypto, using a random AES key that's 
// kept encrypted in an OTSymmetricKey (encrypted using another key derived from  
// thePassword.)

bool OTEnvelope::Encrypt(const OTString & theInput, OTSymmetricKey & theKey, const OTPassword & thePassword)
{
    const char * szFunc = "OTEnvelope::Encrypt";
    // -----------------------------------------------
    OT_ASSERT(thePassword.isPassword());
    OT_ASSERT(thePassword.getPasswordSize() > 0);
    OT_ASSERT(theInput.Exists());
    // -----------------------------------------------
    // Generate a random initialization vector.
    //
    OTPayload theIV;

    if (false == theIV.Randomize(OT_DEFAULT_SYMMETRIC_IV_SIZE))
    {
		OTLog::vError("%s: Failed trying to randomly generate IV.\n", szFunc);
		return false;	
    }
    // -----------------------------------------------
    // If the symmetric key hasn't already been generated, we'll just do that now...
    // (The passphrase is used to derive another key that is used to encrypt the
    // actual symmetric key, and to access it later.)
    //
    if ((false == theKey.IsGenerated()) && (false == theKey.GenerateKey(thePassword)))
    {
		OTLog::vError("%s: Failed trying to generate symmetric key using password.\n", szFunc);
		return false;	
    }
    // -----------------------------------------------
    OTPassword  theRawSymmetricKey;
    
    if (false == theKey.GetRawKey(thePassword, theRawSymmetricKey))
    {
		OTLog::vError("%s: Failed trying to retrieve raw symmetric key using password.\n", szFunc);
		return false;	
    }
    // -----------------------------------------------
    //
    OTPayload theCipherText;
    
    const bool bEncrypted = OTEnvelope::Encrypt(theRawSymmetricKey, // The symmetric key, in clear form.
                                                // -------------------------------
                                                theInput.Get(),     // This is the Plaintext.
                                                theInput.GetLength() + 1, // for null terminator
                                                // -------------------------------
                                                theIV,              // Initialization vector.
                                                // -------------------------------
                                                theCipherText);     // OUTPUT. (Ciphertext.)
    // -----------------------------------------------
    //
    // Success?
    //
    if (!bEncrypted)
    {
        OTLog::vError("%s: (static) call failed to encrypt. Wrong key? (Returning false.)\n", szFunc);
		return false;
    }
    // -----------------------------------------------
    //
	// This is where the envelope final contents will be placed,
    // including the envelope type, the size of the IV, the IV
    // itself, and the ciphertext.
    //
	m_dataContents.Release();

    // -----------------------------------------------
    // Write the ENVELOPE TYPE (network order version.)
    //
    // 0 == Error
    // 1 == Asymmetric Key  (other functions -- Seal / Open.)
    // 2 == Symmetric Key   (this function -- Encrypt / Decrypt.)
    // Anything else: error.
    
    uint16_t   env_type_n = static_cast<uint16_t>(htons(2)); // Calculate "network-order" version of envelope type 2.
    
    m_dataContents.Concatenate(static_cast<void *>(&env_type_n),   
                               // (uint32_t here is the 2nd parameter to Concatenate, and has nothing to do with env_type_n being uint16_t)
                               static_cast<uint32_t>(sizeof(env_type_n)));  
    // ------------------------------------------------------------
    //
    // Write IV size (in network-order)
    //
    uint32_t  ivlen   = OT_DEFAULT_SYMMETRIC_IV_SIZE; // Length of IV for this cipher...
    OT_ASSERT(ivlen >= theIV.GetSize());
    uint32_t  ivlen_n = htonl(theIV.GetSize()); // Calculate "network-order" version of iv length.
    
	m_dataContents.Concatenate(static_cast<void *>(&ivlen_n),   
                               static_cast<uint32_t>(sizeof(ivlen_n)));
	
    // Write the IV itself.
    //
	m_dataContents.Concatenate(theIV.GetPayloadPointer(), 
                               static_cast<uint32_t>(theIV.GetSize()));
    // ------------------------------------------------------------
    
    // Write the Ciphertext.
    //
    m_dataContents.Concatenate(theCipherText.GetPayloadPointer(), 
                               static_cast<uint32_t>(theCipherText.GetSize()));
    
    // -----------------------------------------------
    return true;
}


// Note: these two functions will make it pretty easy to add Session Keys for all communications,
// since Envelopes are ALREADY used for all comms. 

// ------------------------------------------------------------------------

/*
class OTEnvelope_Decrypt_Output
{
private:
    OTPassword * m_pPassword;
    OTPayload  * m_pPayload;
    
    OTEnvelope_Decrypt_Output();
public:
    ~OTEnvelope_Decrypt_Output();
    
    OTEnvelope_Decrypt_Output(OTEnvelope_Decrypt_Output & rhs);
    OTEnvelope_Decrypt_Output(OTPassword & thePassword);
    OTEnvelope_Decrypt_Output(OTPayload  & thePayload);
    
    
    void swap(OTEnvelope_Decrypt_Output & other); // the swap member function (should never fail!)
    
    OTEnvelope_Decrypt_Output & operator = (OTEnvelope_Decrypt_Output other); // note: argument passed by value!
};
*/
// ------------------------------------------------------------------------

OTEnvelope_Decrypt_Output::OTEnvelope_Decrypt_Output() : m_pPassword(NULL), m_pPayload(NULL) {}

OTEnvelope_Decrypt_Output::~OTEnvelope_Decrypt_Output() {}


OTEnvelope_Decrypt_Output::OTEnvelope_Decrypt_Output(const OTEnvelope_Decrypt_Output & rhs) // passed 
: m_pPassword(NULL), m_pPayload(NULL)
{
    m_pPassword = rhs.m_pPassword;
    m_pPayload  = rhs.m_pPayload;
}
    
OTEnvelope_Decrypt_Output::OTEnvelope_Decrypt_Output(OTPassword & thePassword)
 : m_pPassword(&thePassword), m_pPayload(NULL)
{
    
}

OTEnvelope_Decrypt_Output::OTEnvelope_Decrypt_Output(OTPayload  & thePayload)
 : m_pPassword(NULL), m_pPayload(&thePayload)
{
    
}

void OTEnvelope_Decrypt_Output::swap(OTEnvelope_Decrypt_Output & other) // the swap member function (should never fail!)
{
    std::swap(m_pPassword, other.m_pPassword);
    std::swap(m_pPayload,  other.m_pPayload);
}
    
OTEnvelope_Decrypt_Output & OTEnvelope_Decrypt_Output::operator=(OTEnvelope_Decrypt_Output other) // note: argument passed by value!
{
    // swap this with other
    this->swap(other);
    
    // by convention, always return *this
    return *this;
}

// This is just a wrapper class.
//
void OTEnvelope_Decrypt_Output::Release()
{
    OT_ASSERT((m_pPassword != NULL) || (m_pPayload != NULL));

    if (NULL != m_pPassword)
        m_pPassword->zeroMemory();

    if (NULL != m_pPayload)
        m_pPayload->Release();
}


bool OTEnvelope_Decrypt_Output::Concatenate(const void * pAppendData, uint32_t lAppendSize)
{
    OT_ASSERT((m_pPassword != NULL) || (m_pPayload != NULL));
    
    if (NULL != m_pPassword)
    {
        if (static_cast<int>(lAppendSize) == m_pPassword->addMemory(pAppendData, static_cast<int>(lAppendSize)))
            return true;
        else
            return false;
    }
    // -------------------------
    if (NULL != m_pPayload)
    {
        m_pPayload->Concatenate(pAppendData, lAppendSize);
        return true;
    }
    return false;
}




// ------------------------------------------------------------------------

//static
bool OTEnvelope::Decrypt(const OTPassword & theRawSymmetricKey, // The symmetric key, in clear form.
                         // -------------------------------
                         const char *       szInput,            // This is the Ciphertext.
                         const uint32_t     lInputLength,
                         // -------------------------------
                         const OTPayload &  theIV,              // (We assume this IV is already generated and passed in.)
                         // -------------------------------
                         OTEnvelope_Decrypt_Output theDecryptedOutput) // OUTPUT. (Recovered plaintext.) You can pass OTPassword& OR OTPayload& here (either will work.)
{
    const char * szFunc = "OTEnvelope::Decrypt(static)";
    // -----------------------------------------------  
    OT_ASSERT(OT_DEFAULT_SYMMETRIC_IV_SIZE   == theIV.GetSize());
    OT_ASSERT(OT_DEFAULT_SYMMETRIC_KEY_SIZE  == theRawSymmetricKey.getMemorySize());
    OT_ASSERT(NULL != szInput);
    OT_ASSERT(lInputLength > 0);
    // -----------------------------------------------    
	EVP_CIPHER_CTX	ctx;
    
	unsigned char	buffer    [ OT_DEFAULT_SYMMETRIC_BUFFER_SIZE ]; // 4096
    unsigned char	buffer_out[ OT_DEFAULT_SYMMETRIC_BUFFER_SIZE + EVP_MAX_IV_LENGTH];
    
	size_t			len     = 0;
    int				len_out = 0;
    // -----------------------------------------------
	memset(buffer,     0, OT_DEFAULT_SYMMETRIC_BUFFER_SIZE );
	memset(buffer_out, 0, OT_DEFAULT_SYMMETRIC_BUFFER_SIZE + EVP_MAX_IV_LENGTH);
    // -----------------------------------------------    
	//
	// This is where the plaintext results will be placed.
    //
	theDecryptedOutput.Release();
    
    // -----------------------------------------------
    class _OTEnv_Dec_stat
    {
    private:
        const char      *  m_szFunc;
        EVP_CIPHER_CTX	&  m_ctx;
    public:
        _OTEnv_Dec_stat(const char * param_szFunc,
                        EVP_CIPHER_CTX & param_ctx) :
            m_szFunc(param_szFunc),
            m_ctx(param_ctx)
        {
            OT_ASSERT(NULL != param_szFunc);

            EVP_CIPHER_CTX_init(&m_ctx);
        }
        ~_OTEnv_Dec_stat()
        {
            // EVP_CIPHER_CTX_cleanup returns 1 for success and 0 for failure.
            //
            if (0 == EVP_CIPHER_CTX_cleanup(&m_ctx))
                OTLog::vError("%s: Failure in EVP_CIPHER_CTX_cleanup. (It returned 0.)\n", m_szFunc);
        }
    };
    _OTEnv_Dec_stat  theInstance(szFunc, ctx);
    // -----------------------------------------------

    const EVP_CIPHER * cipher_type = EVP_aes_128_cbc();    	    
    
    // -----------------------------------------------
    //
    if (!EVP_DecryptInit(&ctx, 
                         cipher_type, 
                         static_cast<unsigned char *>(const_cast<void *>(theRawSymmetricKey.getMemory())),
                         static_cast<unsigned char *>(const_cast<void *>(theIV.GetPayloadPointer()))))
    {
        OTLog::vError("%s: EVP_DecryptInit: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------
	//
    // Now we process the input and write the decrypted data to
	// the output.
	//
    uint32_t  lRemainingLength = lInputLength;
    uint32_t  lCurrentIndex    = 0;
    
    while (lRemainingLength > 0)
    {
        // If the remaining length is less than the default buffer size, then set len to remaining length.
        // else if remaining length is larger than or equal to default buffer size, then use the default buffer size.
        // Resulting value stored in len.
        //
        len = (lRemainingLength < OT_DEFAULT_SYMMETRIC_BUFFER_SIZE) ? lRemainingLength : OT_DEFAULT_SYMMETRIC_BUFFER_SIZE; // 4096
        lRemainingLength -= len;

        if (!EVP_DecryptUpdate(&ctx,
                               buffer_out,
                               &len_out,
                               const_cast<unsigned char *>(reinterpret_cast<const unsigned char *>(&(szInput [ lCurrentIndex ]))),
                               len))
        {
            OTLog::vError("%s: EVP_DecryptUpdate: failed.\n", szFunc);
			return false;
        }
        lCurrentIndex += len;
        
        if (false == theDecryptedOutput.Concatenate(static_cast<void *>(buffer_out), 
                                                    static_cast<uint32_t>(len_out)))
        {
            OTLog::vError("%s: Failure: theDecryptedOutput isn't large enough for the decrypted output (1).\n", szFunc);
            return false;
        }

    }
    // -----------------------------------------------
    //
	if (!EVP_DecryptFinal(&ctx, buffer_out, &len_out))
    {
        OTLog::vError("%s: EVP_DecryptFinal: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------    
    // This is the "final" piece that is added from DecryptFinal just above.
    //
    if (false == theDecryptedOutput.Concatenate(static_cast<void *>(buffer_out), 
                                                static_cast<uint32_t>(len_out)))
    {
        OTLog::vError("%s: Failure: theDecryptedOutput isn't large enough for the decrypted output (2).\n", szFunc);
        return false;
    }
    // -----------------------------------------------
    return true;
}


/*

void OTData::AESDecrypt(OTData & theKey)
{
	const unsigned char *iv="blahfuckheadfixthis";
	
	EVP_CIPHER_CTX ctx;
	EVP_CIPHER_CTX_init(&ctx);
	
	const EVP_CIPHER * cipher = EVP_aes_128_cbc();
	
	EVP_DecryptInit(&ctx, cipher, theKey.GetPointer(), iv);
	
	EVP_DecryptUpdate(&ctx, out, &outlen, in, inlen);
	
	// unsigned char * out
	EVP_DecryptFinal(&ctx, out, &outlen);
	
	EVP_CIPHER_CTX_cleanup(&ctx);
} 
 */

//
bool OTEnvelope::Decrypt(OTString & theOutput, const OTSymmetricKey & theKey, const OTPassword & thePassword)
{
    const char * szFunc = "OTEnvelope::Decrypt";
    // ------------------------------------------------
    OT_ASSERT(thePassword.isPassword());
    OT_ASSERT(thePassword.getPasswordSize() > 0);
    OT_ASSERT(theKey.IsGenerated());
    // -----------------------------------------------
    OTPassword  theRawSymmetricKey;
    
    if (false == theKey.GetRawKey(thePassword, theRawSymmetricKey))
    {
		OTLog::vError("%s: Failed trying to retrieve raw symmetric key using password. (Wrong password?)\n", 
                      szFunc);
		return false;	
    }
    // -----------------------------------------------
    //
    int nRead         = 0;
    int nRunningTotal = 0;
    
    m_dataContents.reset(); // Reset the fread position on this object to 0.

    // ****************************************************************************
    //
    // Read the ENVELOPE TYPE (as network order version -- and convert to host version.)
    //
    // 0 == Error
    // 1 == Asymmetric Key  (this function -- Seal / Open)
    // 2 == Symmetric Key   (other functions -- Encrypt / Decrypt use this.)
    // Anything else: error.
    //
    uint16_t  env_type_n = 0;
    
    if (0 == (nRead = m_dataContents.OTfread(reinterpret_cast<char*>(&env_type_n), sizeof(env_type_n))))
	{
		OTLog::vError("%s: Error reading Envelope Type. Expected asymmetric(1) or symmetric (2).\n", szFunc);
		return false;
	}
    nRunningTotal += nRead;
    // ----------------------------------------------------------------------------
	// convert that envelope type from network to HOST endian.
    //
    const uint16_t env_type = ntohs(env_type_n);
//  nRunningTotal += env_type;    // NOPE! Just because envelope type is 1 or 2, doesn't mean we add 1 or 2 extra bytes to the length here. Nope!
    
    if (2 != env_type)
	{
        const uint32_t l_env_type = static_cast<uint32_t>(env_type);
		OTLog::vError("%s: Error: Expected Envelope for Symmetric key (type 2) but instead found type %ld.\n", 
                      szFunc, l_env_type);
		return false;
	}
    // ****************************************************************************
    //
    // Read network-order IV size (convert to host version) before then reading IV itself.
    //    
    const int max_iv_length   = OT_DEFAULT_SYMMETRIC_IV_SIZE; // I believe this is a max length, so it may not match the actual length of the IV.
    
    // Read the IV SIZE (network order version -- convert to host version.)
    //
    uint32_t	iv_size_n   = 0;
    
    if (0 == (nRead = m_dataContents.OTfread(reinterpret_cast<char*>(&iv_size_n), sizeof(iv_size_n))))
	{
		OTLog::vError("%s: Error reading IV Size.\n", szFunc);
		return false;
	}
    nRunningTotal += nRead;
    // ----------------------------------------------------------------------------
	// convert that iv size from network to HOST endian.
    //
    const uint32_t iv_size_host_order = ntohl(iv_size_n);
    
    if (iv_size_host_order > static_cast<uint32_t>(max_iv_length))
    {
        OTLog::vError("%s: Error: iv_size (%ld) is larger than max_iv_length (%d).\n",
                      szFunc, iv_size_host_order, max_iv_length);
        return false;
    }
//  nRunningTotal += iv_size_host_order; // Nope!
    // ****************************************************************************
    //
    // Then read the IV (initialization vector) itself.
    //
    OTPayload theIV;
    theIV.SetPayloadSize(iv_size_host_order);
    
    if (0 == (nRead = m_dataContents.OTfread(static_cast<char*>(const_cast<void *>(theIV.GetPayloadPointer())), 
                                             static_cast<int>(iv_size_host_order))))
    {
        OTLog::vError("%s: Error reading initialization vector.\n", szFunc);
        return false;
    }
    nRunningTotal += nRead;
	// ----------------------------------------------------------------------------    
    // We create an OTPayload object to store the ciphertext itself, which begins AFTER the end of the IV.
    // So we see pointer + nRunningTotal as the starting point for the ciphertext.
    // the size of the ciphertext, meanwhile, is the size of the entire thing, MINUS nRunningTotal.
    //
	OTPayload theCipherText(static_cast<const void*>( 
                                               static_cast<const unsigned char *>(m_dataContents.GetPointer()) + nRunningTotal
                                               ), 
					  m_dataContents.GetSize() - nRunningTotal);
    // ----------------------------------------------------------------------------
    // Now we've got all the pieces together, let's try to decrypt it...
    //
    OTPayload thePlaintext; // for output.
    
    const bool bDecrypted = OTEnvelope::Decrypt(theRawSymmetricKey, // The symmetric key, in clear form.
                                                // -------------------------------
                                                static_cast<const char *>(theCipherText.GetPayloadPointer()),  // This is the Ciphertext.
                                                theCipherText.GetSize(),
                                                // -------------------------------
                                                theIV,
                                                // -------------------------------
                                                thePlaintext); // OUTPUT. (Recovered plaintext.) You can pass OTPassword& OR OTPayload& here (either will work.)
    // -----------------------------------------------
    // theOutput is where we'll put the decrypted data.
    //
    theOutput.Release();
    
    if (bDecrypted)
    {
        // -----------------------------------------------------
        // Make sure it's null-terminated...
        //
        uint32_t nIndex = thePlaintext.GetSize()-1;
        (static_cast<unsigned char*>(const_cast<void *>(thePlaintext.GetPointer())))[nIndex] = 0;
        
        // -----------------------------------------------------
        // Set it into theOutput (to return the plaintext to the caller)
        //
        theOutput.Set(static_cast<const char *>(thePlaintext.GetPointer()));
        // ----------------
    }
    
    return bDecrypted;
}

// ------------------------------------------------------------------------

// RSA / AES
//

bool OTEnvelope::Seal(const OTPseudonym & theRecipient, const OTString & theInput)
{
    setOfAsymmetricKeys   theKeys;
    theKeys.insert(const_cast<OTAsymmetricKey *>(&(theRecipient.GetPublicKey())));
    // -----------------------------
    return this->Seal(theKeys, theInput);
}
// --------------


bool OTEnvelope::Seal(setOfNyms & theRecipients, const OTString & theInput)
{
    setOfAsymmetricKeys RecipPubKeys;
    
    // Loop through theRecipients, and add the public key of each one to a set of keys.
    //
    FOR_EACH(setOfNyms, theRecipients)
    {
        OTPseudonym * pNym = *it;
		OT_ASSERT_MSG(NULL != pNym, "OTEnvelope::Seal: Assert: NULL pseudonym pointer.");
		// ------------------------------
        
        RecipPubKeys.insert(const_cast<OTAsymmetricKey *>(&(pNym->GetPublicKey())));
    }
    // --------------------------------
    if (0 == RecipPubKeys.size())
        return false;
    // --------------------------------
	return Seal(RecipPubKeys, theInput);
}


// ------------------------------------------------------------------------


bool OTEnvelope::Seal(const OTAsymmetricKey & RecipPubKey, const OTString & theInput)
{
    setOfAsymmetricKeys   theKeys;
    theKeys.insert(const_cast<OTAsymmetricKey *>(&RecipPubKey));
    // -----------------------------
    return this->Seal(theKeys, theInput);
}

//typedef std::set<OTPseudonym *>         setOfNyms;
//typedef std::set<OTAsymmetricKey *>	  setOfAsymmetricKeys;


// Seal up as envelope (Asymmetric, using public key and then AES key.)

bool OTEnvelope::Seal(setOfAsymmetricKeys & RecipPubKeys, const OTString & theInput)
{
    OT_ASSERT_MSG(RecipPubKeys.size() > 0, "OTEnvelope::Seal: ASSERT: RecipPubKeys.size() > 0");
    // -----------------------------------------------
    const char * szFunc = "OTEnvelope::Seal";
    // -----------------------------------------------
	EVP_CIPHER_CTX	 ctx;
    
	unsigned char	 buffer[4096];
    unsigned char	 buffer_out[4096 + EVP_MAX_IV_LENGTH];
    unsigned char	 iv[EVP_MAX_IV_LENGTH];
    
	size_t			 len     = 0;
    int				 len_out = 0;
    // -----------------------------------------------

	memset(buffer, 0, 4096);
	memset(buffer_out, 0, 4096 + EVP_MAX_IV_LENGTH);
	memset(iv, 0, EVP_MAX_IV_LENGTH);
    
    // -----------------------------------------------
    // The below three arrays are ALL allocated and then cleaned-up inside this fuction
    // (Using the below nested class, _OTEnv_Seal.) The first array will contain useful pointers, but we do NOT delete those.
    // The next array contains pointers that we DO need to cleanup.
    // The final array contains integers (sizes.)
    //
    EVP_PKEY      ** array_pubkey = NULL;  // These will be pointers we use, but do NOT need to clean-up.
    unsigned char ** ek           = NULL;  // These we DO need to cleanup...
    int           *  eklen        = NULL;  // This will just be an array of integers.
    // -----------------------------------------------
    // This class is used as a nested function, for easier cleanup. (C++ doesn't directly support nested functions.)
    // Basically it translates the incoming RecipPubKeys into the low-level arrays
    // ek and eklen (that OpenSSL needs.) This also cleans up those same arrays, once 
    // this object destructs (when we leave scope of this function.)
    //
    class _OTEnv_Seal
    {
    private:
        const char                  *   m_szFunc;
        EVP_CIPHER_CTX              &   m_ctx;                  // reference to openssl cipher context.
        EVP_PKEY                    *** m_array_pubkey;         // pointer to array of public key pointers.
        unsigned char               *** m_ek;                   // pointer to array of encrypted symmetric keys.
        int                         **  m_eklen;                // pointer to array of lengths for each encrypted symmetric key 
        setOfAsymmetricKeys         &   m_RecipPubKeys;         // array of public keys (to initialize the above members with.)
        int                             m_nLastPopulatedIndex;  // We store the highest-populated index (so we can free() up 'til the same index, in destructor.)
    public:
        _OTEnv_Seal(const char            * param_szFunc,
                    EVP_CIPHER_CTX        & theCTX,
                    EVP_PKEY            *** param_array_pubkey,
                    unsigned char       *** param_ek, 
                    int                  ** param_eklen,
                    setOfAsymmetricKeys   & param_RecipPubKeys) :
            m_szFunc(param_szFunc),
            m_ctx(theCTX), 
            m_array_pubkey(NULL), 
            m_ek(NULL), 
            m_eklen(NULL), 
            m_RecipPubKeys(param_RecipPubKeys),
            m_nLastPopulatedIndex(-1)
        {
            OT_ASSERT(NULL != param_szFunc);
            OT_ASSERT(NULL != param_array_pubkey);
            OT_ASSERT(NULL != param_ek);
            OT_ASSERT(NULL != param_eklen);
            OT_ASSERT(m_RecipPubKeys.size() > 0);
            // ----------------------------
            // Notice that each variable is a "pointer to" the actual array that was passed in.
            // (So use them that way, inside this class,
            //  like this:    *m_ek   and   *m_eklen )
            //
            m_array_pubkey = param_array_pubkey;
            m_ek           = param_ek;
            m_eklen        = param_eklen;
            // -----------------------------------------------
            // EVP_CIPHER_CTX_init() corresponds to: EVP_CIPHER_CTX_cleanup()
            // EVP_CIPHER_CTX_cleanup clears all information from a cipher context and free up any allocated 
            // memory associate with it. It should be called after all operations using a cipher are complete
            // so sensitive information does not remain in memory.
            //
            EVP_CIPHER_CTX_init(&m_ctx);
            
            // ----------------------------------------------
            // (*m_array_pubkey)[] array must have m_RecipPubKeys.size() no. of elements (each containing a pointer 
            // to an EVP_PKEY that we must NOT clean up.)
            //
            *m_array_pubkey = (EVP_PKEY **)malloc(m_RecipPubKeys.size() * sizeof(EVP_PKEY *));  
            OT_ASSERT(NULL != *m_array_pubkey);
            memset(*m_array_pubkey, 0, m_RecipPubKeys.size() * sizeof(EVP_PKEY *)); // size of array length * sizeof(pointer)
            // ----------------------------------------------
            // (*m_ek)[] array must have m_RecipPubKeys.size() no. of elements (each will contain a pointer from OpenSSL that we must clean up.)
            //
            *m_ek = (unsigned char**)malloc(m_RecipPubKeys.size() * sizeof(unsigned char*));  
            OT_ASSERT(NULL != *m_ek);
            memset(*m_ek, 0, m_RecipPubKeys.size() * sizeof(unsigned char*)); // size of array length * sizeof(pointer)
            // ----------------------------------------------
            // (*m_eklen)[] array must also have m_RecipPubKeys.size() no. of elements (each containing a size as integer.)
            //
            *m_eklen = (int *)malloc(m_RecipPubKeys.size() * sizeof(int));  
            OT_ASSERT(NULL != *m_eklen);
            memset(*m_eklen, 0, m_RecipPubKeys.size() * sizeof(int)); // size of array length * sizeof(int)
            // ----------------------------------------------
            //
            // ABOVE is all just above allocating the memory and setting it to 0 / NULL.
            //
            // Whereas BELOW is about populating that memory, so the actual OTEnvelope::Seal() function can use it.
            //
            // -----------------------------------------------
            int nKeyIndex = -1; // it will be 0 upon first iteration.
            
            FOR_EACH(setOfAsymmetricKeys, m_RecipPubKeys)
            {
                ++nKeyIndex; // 0 on first iteration.
                m_nLastPopulatedIndex = nKeyIndex;
                // -------------------
                OTAsymmetricKey * pPublicKey = *it;
                OT_ASSERT(NULL != pPublicKey);
                // -------------------
                EVP_PKEY * public_key	= const_cast<EVP_PKEY *>(pPublicKey->GetKey());
                OT_ASSERT(NULL != public_key);
                // -------------------
                // Copy the public key pointer to an array of public key pointers...
                //
                (*m_array_pubkey)[nKeyIndex] = public_key; // For OpenSSL, it needs an array of ALL the public keys.
                // -------------------
                // We allocate enough space for the encrypted symmetric key to be placed
                // at this index (the space determined based on size of the public key that
                // the symmetric key will be encrypted to.) The space is left empty, for OpenSSL
                // to populate.
                //
                (*m_ek)[nKeyIndex] = (unsigned char*)malloc(EVP_PKEY_size(public_key));  // (*m_ek)[i] must have room for EVP_PKEY_size(pubk[i]) bytes. 
                OT_ASSERT(NULL != (*m_ek)[nKeyIndex]);
                memset((*m_ek)[nKeyIndex], 0, EVP_PKEY_size(public_key)); 
                // -------------------
            } // FOR_EACH(setOfAsymmetricKeys, m_RecipPubKeys)
            // -----------------------------------------------
        }
        // --------------------------------
        ~_OTEnv_Seal() // (destructor)
        {
            OT_ASSERT(NULL != m_array_pubkey);  // 1. pointer to an array of pointers to EVP_PKEY,
            OT_ASSERT(NULL != m_ek);            // 2. pointer to an array of pointers to encrypted symmetric keys
            OT_ASSERT(NULL != m_eklen);         // 3. pointer to an array storing the lengths of those keys.
            // -------------------------------
            // Iterate the array of encrypted symmetric keys, and free the key at each index...
            // 
            // We know how many there are, because each pointer will otherwise be NULL.
            // Plus we have m_nLastPopulatedIndex, which is obviously as far as we will go.
            //
            // -------------------------------
            int    nKeyIndex = -1; // it will be 0 upon first iteration.
            while (nKeyIndex < m_nLastPopulatedIndex) // if m_nLastPopulatedIndex is 0, then this loop will iterate ONCE, with nKeyIndex incrementing to 0 on the first line.
            {
                ++nKeyIndex; // 0 on first iteration.
                // --------------
                OT_ASSERT(NULL != (*m_ek)[nKeyIndex]);
                // --------------
                free((*m_ek)[nKeyIndex]);
                (*m_ek)[nKeyIndex] = NULL;
            }
            // -------------------------------
            //
            // Now free all of the arrays: 
            // 1. an array of pointers to EVP_PKEY, 
            // 2. an array of pointers to encrypted symmetric keys
            //    (those all being NULL pointers due to the above while-loop),
            //    and
            // 3. an array storing the lengths of those keys.
            //
            // -------------------------------
            if (NULL != *m_array_pubkey) // NOTE: The individual pubkeys are NOT to be cleaned up, but this array, containing pointers to those pubkeys, IS cleaned up.
                free(*m_array_pubkey); *m_array_pubkey = NULL;  m_array_pubkey = NULL;
            if (NULL != *m_ek)
                free(*m_ek);           *m_ek           = NULL;  m_ek           = NULL;
            if (NULL != *m_eklen)
                free(*m_eklen);        *m_eklen        = NULL;  m_eklen        = NULL;           
            // -------------------------------
  
            // EVP_CIPHER_CTX_cleanup returns 1 for success and 0 for failure.
            //
            if (0 == EVP_CIPHER_CTX_cleanup(&m_ctx))
                OTLog::vError("%s: Failure in EVP_CIPHER_CTX_cleanup. (It returned 0.)\n", m_szFunc);
        }
        // -----------------------------------
    }; // class _OTEnv_Seal
    // ---------------------------------------------------------------------------------------------------------------
    
    // INSTANTIATE IT (This does all our setup on construction here, AND cleanup 
    // on destruction, whenever exiting this function.)
    
    _OTEnv_Seal local_RAII(szFunc, ctx, &array_pubkey, &ek, &eklen, RecipPubKeys);
 
    // --------------------------------
	// This is where the envelope final contents will be placed.
    // including the size of the encrypted symmetric key, the symmetric key
    // itself, the initialization vector, and the ciphertext.
    //
	m_dataContents.Release();
	
    // -----------------------------------------------
    const EVP_CIPHER * cipher_type = EVP_aes_128_cbc(); // todo hardcoding.
    // --------------------------
    /*
    int EVP_SealInit(EVP_CIPHER_CTX *ctx, const EVP_CIPHER *type,
                     unsigned char **ek,  int *ekl,
                     unsigned char *iv,
                     EVP_PKEY **pubk,     int npubk);
     
     -- ek is an array of buffers where the public-key-encrypted secret key will be written (for each recipient.)
     -- Each buffer must contain enough room for the corresponding encrypted key: that is,
            ek[i] must have room for EVP_PKEY_size(pubk[i]) bytes. 
     -- The actual size of each encrypted secret key is written to the array ekl. 
     -- pubk is an array of npubk public keys.
     */
    
//    EVP_PKEY      ** array_pubkey = NULL;  // These will be pointers we use, but do NOT need to clean-up.
//    unsigned char ** ek           = NULL;  // These we DO need to cleanup...
//    int           *  eklen        = NULL;  // This will just be an array of integers.

    if (!EVP_SealInit(&ctx, cipher_type, 
                      ek,   eklen, // array of buffers for output of encrypted copies of the symmetric "session key". (Plus array of ints, to receive the size of each key.)
                      iv,          // A buffer where the generated IV is written. Must contain room for the corresponding cipher's IV, as determined by (for example) EVP_CIPHER_iv_length(type).
                      array_pubkey, RecipPubKeys.size())) // array of public keys we are addressing this envelope to.
    {
        OTLog::vError("%s: EVP_SealInit: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------
    // Write the ENVELOPE TYPE (network order version.)
    //
    // 0 == Error
    // 1 == Asymmetric Key  (this function -- Seal / Open)
    // 2 == Symmetric Key   (other functions -- Encrypt / Decrypt use this.)
    // Anything else: error.
    
    uint16_t   env_type_n = static_cast<uint16_t>(htons(1)); // Calculate "network-order" version of envelope type 1.
    
    m_dataContents.Concatenate(static_cast<void *>(&env_type_n),   
                               static_cast<uint32_t>(sizeof(env_type_n))); 
    // ------------------------------------------------------------
    // Write the ARRAY SIZE (network order version.)
    
    uint32_t   array_size_n = static_cast<uint32_t>(htonl(RecipPubKeys.size())); // Calculate "network-order" version of array size.
    
    m_dataContents.Concatenate(static_cast<void *>(&array_size_n),   
                               static_cast<uint32_t>(sizeof(array_size_n))); 
    // ------------------------------------------------------------
    OT_ASSERT(NULL != ek);
    OT_ASSERT(NULL != eklen);
    // -----------------
    // Loop through the encrypted symmetric keys, and for each, write its 
    // network-order NymID size, and its NymID, and its network-order content size,
    // and its content, to the envelope data contents
    // (that we are currently building...)
    //
    int ii = -1; // it will be 0 upon first iteration.
    
    FOR_EACH(setOfAsymmetricKeys, RecipPubKeys)
    {
        ++ii; // 0 on first iteration.
        // -------------------
        OTAsymmetricKey * pPublicKey = *it;
        OT_ASSERT(NULL != pPublicKey);
        // -------------------
        OTIdentifier theNymID;
        bool bCalculatedID = pPublicKey->CalculateID(theNymID); // Only works for public keys.
        
        if (false == bCalculatedID)
        {
            OTLog::vError("%s: Error trying to calculate ID of recipient.\n", szFunc);
            return false;
        }
        // -------------------------
        const OTString strNymID(theNymID);
        
        uint32_t    nymid_len_n = static_cast<uint32_t>(htonl(strNymID.GetLength()+1)); // Calculate "network-order" version of length (+1 for null terminator)

        // Write nymid_len_n and strNymID for EACH encrypted symmetric key.
        //
        m_dataContents.Concatenate(static_cast<void *>(&nymid_len_n),   
                                   static_cast<uint32_t>(sizeof(nymid_len_n))); 
        
        m_dataContents.Concatenate(static_cast<const void *>(strNymID.Get()),         
                                   static_cast<uint32_t>(strNymID.GetLength()+1)); // (+1 for null terminator)
        // -------------------------
//      Write eklen_n and ek for EACH encrypted symmetric key, 
//        
//        EVP_PKEY      ** array_pubkey = NULL;  // These will be pointers we use, but do NOT need to clean-up.
//        unsigned char ** ek           = NULL;  // These we DO need to cleanup...
//        int           *  eklen        = NULL;  // This will just be an array of integers.

        // --------------------------
        OT_ASSERT(NULL != ek[ii]);
        OT_ASSERT(eklen[ii] > 0);
        // -----------------
        uint32_t    eklen_n = static_cast<uint32_t>(htonl(eklen[ii])); // Calculate "network-order" version of length.
        // -----------------        
        m_dataContents.Concatenate(static_cast<void *>(&eklen_n),   
                                   static_cast<uint32_t>(sizeof(eklen_n))); 
        
        m_dataContents.Concatenate(static_cast<void *>(ek[ii]),         
                                   static_cast<uint32_t>(eklen[ii]));
        
        // -------------------
    } // FOR_EACH(setOfAsymmetricKeys, m_RecipPubKeys)
    // -----------------------------------------------
    //
    // Write IV size before then writing IV itself.
    //
    int       ivlen   = EVP_CIPHER_iv_length(cipher_type); // Length of IV for this cipher... (TODO: add cipher name to output, and use it for looking up cipher upon Open.)
    OT_ASSERT(ivlen > 0);
    uint32_t  ivlen_n = static_cast<uint32_t>(htonl(ivlen)); // Calculate "network-order" version of iv length.

	m_dataContents.Concatenate(static_cast<void *>(&ivlen_n),   
                               static_cast<uint32_t>(sizeof(ivlen_n)));
	
	m_dataContents.Concatenate(static_cast<void *>(iv), 
                               static_cast<uint32_t>(ivlen));

    // -----------------------------------------------
	// Next we put the plaintext into a data object so we can process it via EVP_SealUpdate,
    // in blocks, into encrypted form in m_dataContents. Each iteration of the loop processes
    // one block.
    //
	OTData plaintext(static_cast<const void*>(theInput.Get()), theInput.GetLength()+1); // +1 for null terminator
	
    // -----------------------------------------------
    // Now we process the input and write the encrypted data to the
	// output.
	//
    while (0 < (len = plaintext.OTfread(reinterpret_cast<char*>(buffer), sizeof(buffer))))
    {
        if (!EVP_SealUpdate(&ctx, buffer_out, &len_out, buffer, len))
        {
            OTLog::vError("%s: EVP_SealUpdate failed.\n", szFunc);
			return false;
        }
        // -------------------
		m_dataContents.Concatenate(static_cast<void *>(buffer_out), 
                                   static_cast<uint32_t>(len_out));
	}
    // -----------------------------------------------

    if (!EVP_SealFinal(&ctx, buffer_out, &len_out))
    {
        OTLog::vError("%s: EVP_SealFinal failed.\n", szFunc);
		return false;
    }
    // This is the "final" piece that is added from SealFinal just above.
    //
    m_dataContents.Concatenate(static_cast<void *>(buffer_out), 
                               static_cast<uint32_t>(len_out));
    // -----------------------------------------------
    return true;
}







/*
#include <openssl/evp.h>
int EVP_OpenInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *type,unsigned char *ek,
				 int ekl,unsigned char *iv,EVP_PKEY *priv);
int EVP_OpenUpdate(EVP_CIPHER_CTX *ctx, unsigned char *out,
				   int *outl, unsigned char *in, int inl);
int EVP_OpenFinal(EVP_CIPHER_CTX *ctx, unsigned char *out,
				  int *outl);
DESCRIPTION

The EVP envelope routines are a high level interface to envelope decryption. They decrypt a public key 
 encrypted symmetric key and then decrypt data using it.

 int EVP_OpenInit(EVP_CIPHER_CTX *ctx,EVP_CIPHER *type,unsigned char *ek, int ekl,unsigned char *iv,EVP_PKEY *priv);
EVP_OpenInit() initializes a cipher context ctx for decryption with cipher type. It decrypts the encrypted 
 symmetric key of length ekl bytes passed in the ek parameter using the private key priv. The IV is supplied 
 in the iv parameter.

EVP_OpenUpdate() and EVP_OpenFinal() have exactly the same properties as the EVP_DecryptUpdate() and 
 EVP_DecryptFinal() routines, as documented on the EVP_EncryptInit(3) manual page.

NOTES

It is possible to call EVP_OpenInit() twice in the same way as EVP_DecryptInit(). The first call should have 
 priv set to NULL and (after setting any cipher parameters) it should be called again with type set to NULL.

If the cipher passed in the type parameter is a variable length cipher then the key length will be set to the 
value of the recovered key length. If the cipher is a fixed length cipher then the recovered key length must 
match the fixed cipher length.

RETURN VALUES

EVP_OpenInit() returns 0 on error or a non zero integer (actually the recovered secret key size) if successful.

EVP_OpenUpdate() returns 1 for success or 0 for failure.

EVP_OpenFinal() returns 0 if the decrypt failed or 1 for success.
*/


// DONE: Fix OTEnvelope so we can seal to multiple recipients simultaneously.
// TODO: Fix OTEnvelope so it supports symmetric crypto as well as asymmetric.

// TODO: Make sure OTEnvelope is safe with zeroing memory wherever needed.

// TODO: Might want to remove the Nym stored inside the purse, and replace with a 
// session key, just as envelopes will support a session key.


//Todo: Once envelopes support multiple recipient Nyms, then make a habit of encrypting
// to the user's key AND server's key, when sending.

// Hmm this might be better than a session key, since we don't have to worry about keeping track
// of the session key for LATER, since envelopes generate a session key already.
// BUT: That means we do it already, and that means we wouldn't get any speed benefit.
// Transport protocol should have session key already built-in -- hmm what if going over email or
// some insecure channel?
// Solution: Make it always encrypted to public key (as it already is now) with session key automatically
// (as already) by virtue of using OpenSSL envelope. This will, of course, generate a new session key for
// EACH envelope, so we will STILL add the protocol of initiating sessions, purely to reduce CPU cycles
// during each session. This means we'll have the same protocol as before but just faster (in a way.)
// 


// RSA / AES

bool OTEnvelope::Open(const OTPseudonym & theRecipient, OTString & theOutput)
{
    const char * szFunc = "OTEnvelope::Open";    
	// ------------------------------------------------
    unsigned char	buffer[4096];
    unsigned char	buffer_out[4096 + EVP_MAX_IV_LENGTH];
    unsigned char	iv[EVP_MAX_IV_LENGTH];

    size_t			len     = 0;
    int				len_out = 0;    
	// ------------------------------------------------
    
	memset(buffer, 0, 4096);
	memset(buffer_out, 0, 4096 + EVP_MAX_IV_LENGTH);
	memset(iv, 0, EVP_MAX_IV_LENGTH);

    // ------------------------------------------------
    // theOutput is where we'll put the decrypted result.
    //
    theOutput.Release();	
    // ------------------------------------------------
    // Grab the NymID of the recipient, so we can find his session
    // key (there might be symmetric keys for several Nyms, not just this
    // one, and we need to find the right one in order to perform this Open.)
    //
    OTString  strNymID;
    theRecipient.GetIdentifier(strNymID);
    // ------------------------------------------------
	OTAsymmetricKey &	privateKey	= const_cast<OTAsymmetricKey &>(theRecipient.GetPrivateKey());
	EVP_PKEY *			private_key = const_cast<EVP_PKEY *>(privateKey.GetKey());
	
	if (NULL == private_key)
	{
		OTLog::vError("%s: Null private key on recipient. (Returning false.)\n", szFunc);
		return false;
	}
    // ------------------------------------------------
    EVP_CIPHER_CTX	ctx;
    // ----------------------------------------------
    class _OTEnv_Open
    {
    private:
        const char        *   m_szFunc;
        EVP_CIPHER_CTX    &   m_ctx;        // reference to openssl cipher context.
        OTAsymmetricKey   &   m_privateKey; // reference to OTAsymmetricKey object.
    public:
        // ------------------------
        _OTEnv_Open(const char       * param_szFunc,
                    EVP_CIPHER_CTX   & theCTX,
                    OTAsymmetricKey  & param_privateKey) :
            m_szFunc(param_szFunc),
            m_ctx(theCTX),
            m_privateKey(param_privateKey)
        {
            OT_ASSERT(NULL != param_szFunc);

            EVP_CIPHER_CTX_init(&m_ctx);
        }
        // ------------------------
        ~_OTEnv_Open()  // DESTRUCTOR
        {
            m_privateKey.ReleaseKey();
            //
            // BELOW this point, private_key (which is a member of m_privateKey is either
            // cleaned up, or kept based on a timer value. (It MAY not be cleaned up,
            // depending on its state.)
            
            
            // EVP_CIPHER_CTX_cleanup returns 1 for success and 0 for failure.
            //
            if (0 == EVP_CIPHER_CTX_cleanup(&m_ctx))
                OTLog::vError("%s: Failure in EVP_CIPHER_CTX_cleanup. (It returned 0.)\n", m_szFunc);
        }
    };
    // ------------------------------------------------
    // INSTANTIATE the clean-up object.
    //            
    _OTEnv_Open     theNestedInstance(szFunc, ctx, privateKey);
    //
    // ------------------------------------------------
    //
	m_dataContents.reset(); // Reset the fread position on this object to 0.
	
    uint32_t nRunningTotal = 0; // Everytime we read something, we add the length to this variable.
    
	int nReadEnvType   = 0;
	int nReadArraySize = 0;
	int nReadIV        = 0;
	// ----------------------------------------------------------------------------
    //
    // Read the ARRAY SIZE (network order version -- convert to host version.)
    // -----------------
    // Loop through the array of encrypted symmetric keys, and for each:
    //      read its network-order NymID size (convert to host version), and then read its NymID,
    //      read its network-order key content size (convert to host), and then read its key content,
    // -----------------
    //
    // Read network-order IV size (convert to host version) before then reading IV itself.
    // (Then update encrypted blocks until evp open final...)
    //
    // --------------------------------------------------
    
    // So here we go...
    
    // ****************************************************************************
    //
    // Read the ENVELOPE TYPE (as network order version -- and convert to host version.)
    //
    // 0 == Error
    // 1 == Asymmetric Key  (this function -- Seal / Open)
    // 2 == Symmetric Key   (other functions -- Encrypt / Decrypt use this.)
    // Anything else: error.
    //
    uint16_t  env_type_n = 0;
    
    if (0 == (nReadEnvType = m_dataContents.OTfread(reinterpret_cast<char*>(&env_type_n), sizeof(env_type_n))))
	{
		OTLog::vError("%s: Error reading Envelope Type. Expected asymmetric(1) or symmetric (2).\n", szFunc);
		return false;
	}
    nRunningTotal += nReadEnvType;
    // ----------------------------------------------------------------------------
	// convert that envelope type from network to HOST endian.
    //
    const uint16_t env_type = ntohs(env_type_n);
//  nRunningTotal += env_type;    // NOPE! Just because envelope type is 1 or 2, doesn't mean we add 1 or 2 extra bytes to the length here. Nope!
    
    if (1 != env_type)
	{
		OTLog::vError("%s: Error: Expected Envelope for Asymmetric key (type 1) but instead found type %ld.\n", 
                      szFunc, env_type);
		return false;
	}
    // ****************************************************************************
    //
    // Read the ARRAY SIZE (network order version -- convert to host version.)
    //
    uint32_t	array_size_n = 0;
    
    if (0 == (nReadArraySize = m_dataContents.OTfread(reinterpret_cast<char*>(&array_size_n), sizeof(array_size_n))))
	{
		OTLog::vError("%s: Error reading Array Size for encrypted symmetric keys.\n", szFunc);
		return false;
	}
    nRunningTotal += nReadArraySize;
    // ----------------------------------------------------------------------------
	// convert that array size from network to HOST endian.
    //
    const uint32_t array_size = ntohl(array_size_n);
//  nRunningTotal += array_size;    // NOPE! Just because there are 10 array elements doesn't mean I want to add "10" here to the running total!! Not logical.
    // ****************************************************************************
    //
    // We are going to loop through all the keys and load each up (then delete.)
    // Each one is proceeded by its length. 
    // IF we find the one we are looking for, then we set it onto this variable,
    // theRawEncryptedKey, so we have it available below this loop.
    //
    OTPayload  theRawEncryptedKey;
    bool       bFoundKeyAlready = false; // If we find it during the loop below, we'll set this to true.
    // ----------------------------------------------------------------------------
    // Loop through as we read the encrypted symmetric keys, and for each:
    //      read its network-order NymID size (convert to host version), and then read its NymID,
    //      read its network-order key content size (convert to host), and then read its key content,
    // 
    for (unsigned int ii = 0; ii < array_size; ++ii)
    {
        // ****************************************************************************
        //
        // Loop through the encrypted symmetric keys, and for each:
        //      read its network-order NymID size (convert to host version), and then read its NymID,
        //      read its network-order key content size (convert to host), and then read its key content.
        // -----------------
        //
        uint32_t	nymid_len_n    = 0;
        int         nReadNymIDSize = 0;
        
        if (0 == (nReadNymIDSize = m_dataContents.OTfread(reinterpret_cast<char*>(&nymid_len_n), sizeof(nymid_len_n))))
        {
            OTLog::vError("%s: Error reading NymID length for an encrypted symmetric key.\n", szFunc);
            return false;
        }
        nRunningTotal += nReadNymIDSize;
        // ----------------------------------------------------------------------------
        // convert that array size from network to HOST endian.
        //
        int nymid_len = ntohl(nymid_len_n);    // FYI: ntohl returns uint32_t !!!!!
        
//      nRunningTotal += nymid_len; // Nope!
        // ----------------------------------------------------------------------------
        char * nymid = static_cast<char *>(malloc(nymid_len));
        OT_ASSERT(NULL != nymid);
        
        int  nReadNymID = 0;
        
        if (0 == (nReadNymID = m_dataContents.OTfread(nymid, sizeof(char) * nymid_len)))
        {
            OTLog::vError("%s: Error reading NymID for an encrypted symmetric key.\n", szFunc);
            free(nymid); nymid = NULL;
            return false;
        }
        nRunningTotal += nReadNymID;
        // ----------------------------------------------------------------------------
        const OTString loopStrNymID(nymid);
        free(nymid); nymid = NULL;
        // ****************************************************************************
        //
        // loopStrNymID ... if this matches strNymID then it's the one we're looking for.
        // But we have to load it all either way, just to iterate through them, so might
        // as well load it all first, then check. If it matches, we use it and break.
        // Otherwise we keep iterating until we find it.
        //
        // ----------------------------------------------------------------------------
        
        // Read its network-order key content size (convert to host-order), and then 
        // read its key content.

        unsigned char *	ek          = NULL;
        int				eklen       = 0;
        uint32_t		eklen_n     = 0;
        int             nReadLength = 0;
        int             nReadKey    = 0;
        // ----------------------------------------------------------------------------
        // First we read the encrypted key size.
        //
        if (0 == (nReadLength = m_dataContents.OTfread(reinterpret_cast<char *>(&eklen_n), sizeof(eklen_n))))
        {
            OTLog::vError("%s: Error reading encrypted key size.\n", szFunc);
            return false;
        }
        nRunningTotal += nReadLength;
        // ----------------------------------------------------------------------------
        // convert that key size from network to host endian.
        //
        eklen  = ntohl(eklen_n);
//      eklen  = EVP_PKEY_size(private_key);  // We read this size from file now...
        
//      nRunningTotal += eklen;  // Nope!
        // ----------------------------------------------------------------------------
        ek     = static_cast<unsigned char*>(malloc(eklen));  // I assume this is for the AES key
        OT_ASSERT(NULL != ek);
        memset(ek, 0, eklen);
        // ----------------------------------------------------------------------------
        // Next we read the encrypted key itself...
        //
        if (0 == (nReadKey = m_dataContents.OTfread(reinterpret_cast<char*>(ek), eklen)))
        {
            OTLog::vError("%s: Error reading encrypted key.\n", szFunc);
            free(ek); ek = NULL;
            return false;
        }
        nRunningTotal += nReadKey;
        // ****************************************************************************
        //
        // If we "found the key already" that means we already found the right key on
        // a previous iteration, so therefore we're *definitely* just going to throw
        // THIS one away. We just continue on to the next iteration and keep counting
        // the bytes.
        //
        if (false == bFoundKeyAlready)
        {
            // We have NOT found the right key yet, so let's see if this is the one we're looking for.
            
            if (strNymID == loopStrNymID) // FOUND IT! <==========
            {
                bFoundKeyAlready = true;
                
                theRawEncryptedKey.Assign(const_cast<const void *>(static_cast<void *>(ek)), eklen);
            }
        }        
        
        free(ek); ek = NULL;
        
    } // for
    // ------------------------------------------------------------------
    
    if (false == bFoundKeyAlready)
    {
        OTLog::vOutput(0, "%s: Sorry: Unable to find a session key for the Nym attempting to open this envelope.\n",
                       szFunc);
        return false;
    }
    
    // ****************************************************************************
    //
    // Read network-order IV size (convert to host version) before then reading IV itself.
    // (Then update encrypted blocks until evp open final...)
    //
    // --------------------------------------------------
    //    
    const int max_iv_length = OT_DEFAULT_SYMMETRIC_IV_SIZE; // I believe this is a max length, so it may not match the actual length.

    // Read the IV SIZE (network order version -- convert to host version.)
    //
    uint32_t	iv_size_n   = 0;
    int         nReadIVSize = 0;

    if (0 == (nReadIVSize = m_dataContents.OTfread(reinterpret_cast<char*>(&iv_size_n), sizeof(iv_size_n))))
	{
		OTLog::vError("%s: Error reading IV Size for encrypted symmetric keys.\n", szFunc);
		return false;
	}
    nRunningTotal += nReadIVSize;
    // ----------------------------------------------------------------------------
	// convert that iv size from network to HOST endian.
    //
    const int iv_size_host_order = ntohl(iv_size_n);
        
    if (iv_size_host_order > max_iv_length)
    {
        OTLog::vError("%s: Error: iv_size (%d) is larger than max_iv_length (%d).\n",
                      szFunc, iv_size_host_order, max_iv_length);
        return false;
    }
    // ****************************************************************************
    //
    // Then read the IV (initialization vector) itself.
    //
    if (0 == (nReadIV = m_dataContents.OTfread(reinterpret_cast<char*>(iv), iv_size_host_order)))
    {
        OTLog::vError("%s: Error reading initialization vector.\n", szFunc);
        return false;
    }
    
    nRunningTotal += nReadIV;
	// ----------------------------------------------------------------------------
    
    // We read the encrypted key size, then we read the encrypted key itself, with nReadKey containing
    // the number of bytes actually read. The IF statement says "if 0 ==" but it should probably say
    // "if eklen !=" (right?) Wrong: because I think it's a max length.
    //
    // We create an OTData object to store the ciphertext itself, which begins AFTER the end of the IV.
    // So we see pointer + nRunningTotal as the starting point for the ciphertext.
    // the size of the ciphertext, meanwhile, is the size of the entire thing, MINUS nRunningTotal.
    //
	OTData ciphertext(static_cast<const void*>( 
                                         static_cast<const unsigned char *>(m_dataContents.GetPointer()) + nRunningTotal
                                         ), 
					  m_dataContents.GetSize() - nRunningTotal);
    // ------------------------------------------------
    //
    const EVP_CIPHER * cipher_type = EVP_aes_128_cbc();  // todo hardcoding.
    //
    //  OTPayload
    //  void   SetPayloadSize   (uint32_t lNewSize);
    //	const
    //  void * GetPayloadPointer() const;
    
    //  OTData
    //  inline 
    //  uint32_t	 GetSize    () const { return m_lSize; } 
    //	bool         IsEmpty    () const;
    //  virtual void Release    ();
    //	void         Assign     (const void * pNewData, uint32_t lNewSize);
    //	void         Concatenate(const void * pNewData, uint32_t lNewSize);
    // ----------------------------------------------
    //
	if (!EVP_OpenInit(&ctx, cipher_type,
                      static_cast<const unsigned char *>(theRawEncryptedKey.GetPayloadPointer()),
                      static_cast<int>(theRawEncryptedKey.GetSize()),
                      iv,
                      private_key))
//  if (!EVP_OpenInit(&ctx, cipher_type, ek, eklen, iv, private_key))
    {
        // int EVP_OpenInit(
        //          EVP_CIPHER_CTX *ctx,
        //          EVP_CIPHER *type,
        //          unsigned char *ek, 
        //          int ekl,
        //          unsigned char *iv,
        //          EVP_PKEY *priv);
        
        //EVP_OpenInit() initializes a cipher context ctx for decryption with cipher type. It decrypts the encrypted 
        //	symmetric key of length ekl bytes passed in the ek parameter using the private key priv. The IV is supplied 
        //	in the iv parameter.

        OTLog::vError("%s: EVP_OpenInit: failed.\n", szFunc);
		return false;
    }
    
    // ----------------------------------------------------------------------------
	// Now we process ciphertext and write the decrypted data to plaintext.
    //
	OTData plaintext;

    // We loop through the ciphertext and process it in blocks...
    //
    while ((len = ciphertext.OTfread(reinterpret_cast<char*>(buffer), sizeof(buffer))) > 0)
    {
        if (!EVP_OpenUpdate(&ctx, buffer_out, &len_out, buffer, len))
        {
            OTLog::vError("%s: EVP_OpenUpdate: failed.\n", szFunc);
            return false;
        }

        plaintext.Concatenate(static_cast<void *>(buffer_out), 
                              static_cast<uint32_t>(len_out));
	}
	
    if (!EVP_OpenFinal(&ctx, buffer_out, &len_out))
    {
		OTLog::vError("%s: EVP_OpenFinal: failed.\n", szFunc);
		return false;
    }
    // -----------------------------------------------------    
	
    plaintext.Concatenate(static_cast<void *>(buffer_out), 
                          static_cast<uint32_t>(len_out));

    
	// Make sure it's null-terminated...
    //
	uint32_t nIndex = plaintext.GetSize()-1;
	(static_cast<unsigned char*>(const_cast<void*>(plaintext.GetPointer())))[nIndex] = 0;
	
    // -----------------------------------------------------
	// Set it into theOutput (to return the plaintext to the caller)
    //
	theOutput.Set(static_cast<const char *>(plaintext.GetPointer()));
    // ----------------
    return true;
}














// NOTHING INTERESTING BELOW THIS POINT












/*
int do_evp_seal(FILE *rsa_pkey_file, FILE *in_file, FILE *out_file)
{
    int retval = 0;
    RSA *rsa_pkey = NULL;
    EVP_PKEY *pkey = EVP_PKEY_new();
    EVP_CIPHER_CTX ctx;
    unsigned char buffer[4096];
    unsigned char buffer_out[4096 + EVP_MAX_IV_LENGTH];
    size_t len;
    int len_out;
    unsigned char *ek;
    int eklen;
    uint32_t eklen_n;
    unsigned char iv[EVP_MAX_IV_LENGTH];
	
    if (!PEM_read_RSA_PUBKEY(rsa_pkey_file, &rsa_pkey, OTAsymmetricKey::GetPasswordCallback(), NULL))
    {
        OTLog::Error("Error loading RSA Public Key File.\n");
        ERR_print_errors_fp(stderr);
        retval = 2;
        goto out;
    }
	
    if (!EVP_PKEY_assign_RSA(pkey, rsa_pkey))
    {
        OTLog::Error("EVP_PKEY_assign_RSA: failed.\n");
        retval = 3;
        goto out;
    }
	
    EVP_CIPHER_CTX_init(&ctx);
    ek = malloc(EVP_PKEY_size(pkey));
	
    if (!EVP_SealInit(&ctx, EVP_aes_128_cbc(), &ek, &eklen, iv, &pkey, 1))
    {
        OTLog::Error("EVP_SealInit: failed.\n");
        retval = 3;
        goto out_free;
    }
	
    // First we write out the encrypted key length, then the encrypted key,
     / then the iv (the IV length is fixed by the cipher we have chosen).
     
	
    eklen_n = htonl(eklen);
    if (fwrite(&eklen_n, sizeof eklen_n, 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
    if (fwrite(ek, eklen, 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
    if (fwrite(iv, EVP_CIPHER_iv_length(EVP_aes_128_cbc()), 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
	
    // Now we process the input file and write the encrypted data to the
	//output file.
	
    while ((len = fread(buffer, 1, sizeof buffer, in_file)) > 0)
    {
        if (!EVP_SealUpdate(&ctx, buffer_out, &len_out, buffer, len))
        {
            OTLog::Error("EVP_SealUpdate: failed.\n");
            retval = 3;
            goto out_free;
        }
		
        if (fwrite(buffer_out, len_out, 1, out_file) != 1)
        {
            perror("output file");
            retval = 5;
            goto out_free;
        }
    }
	
    if (ferror(in_file))
    {
        perror("input file");
        retval = 4;
        goto out_free;
    }
	
    if (!EVP_SealFinal(&ctx, buffer_out, &len_out))
    {
        OTLog::Error("EVP_SealFinal: failed.\n");
        retval = 3;
        goto out_free;
    }
	
    if (fwrite(buffer_out, len_out, 1, out_file) != 1)
    {
        perror("output file");
        retval = 5;
        goto out_free;
    }
	
out_free:
    EVP_PKEY_free(pkey);
    free(ek);
	
out:
    return retval;
}

int main(int argc, char *argv[])
{
    FILE *rsa_pkey_file;
    int rv;
	
    if (argc < 2)
    {
        OTLog::vOutput(0, "Usage: %s <PEM RSA Public Key File>\n", argv[0]);
        exit(1);
    }
	
    rsa_pkey_file = fopen(argv[1], "rb");
    if (!rsa_pkey_file)
    {
        perror(argv[1]);
        OTLog::Error("Error loading PEM RSA Public Key File.\n");
        exit(2);
    }
	
    rv = do_evp_seal(rsa_pkey_file, stdin, stdout);
	
    fclose(rsa_pkey_file);
    return rv;
}
*/


// We just read some encrypted (and armored) data, and we want to put it in
// an envelope so that it can be opened. So we can just directly set the
// armored string here, and it will be decoded into the original binary,
// inside this envelope. That way we can decrypt it (symmetric), or open it
// (asymmetric) and get the original plaintext that was sent.
//
OTEnvelope::OTEnvelope(const OTASCIIArmor & theArmoredText)
{
	SetAsciiArmoredData(theArmoredText);
}

OTEnvelope::OTEnvelope()
{
	
}

OTEnvelope::~OTEnvelope()
{
	
}




