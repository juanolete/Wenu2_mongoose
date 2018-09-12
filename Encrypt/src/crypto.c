#include "mgos.h"
#include "crypto.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <cstdio>

#include "mbedtls/md.h"
#include "mbedtls/aes.h"
#include "mbedtls/sha256.h"
 
// HMAC SHA256
void mg_hmac_sha256(unsigned char* payload, unsigned char* key, byte* hmacResult){
  size_t payloadLength = strlen(payload);
  size_t keyLength = strlen(key);
  mbedtls_md_context_t ctx;
  mbedtls_md_type_t md_type = MBEDTLS_MD_SHA256;
  mbedtls_md_init(&ctx);
  mbedtls_md_setup(&ctx, mbedtls_md_info_from_type(md_type),1);
  mbedtls_md_hmac_starts(&ctx, (const unsigned char *)key, keyLength);
  mbedtls_md_hmac_update(&ctx, (const unsigned char *)payload, payloadLength);
  mbedtls_md_hmac_finish(&ctx, hmacResult); 
  mbedtls_md_free(&ctx);
}

// AES CBC ENCRYPT
void mg_aescbc_encrypt(char* key, char* payload, unsigned char* iv, unsigned char* output ){
  size_t payloadLength = strlen(payload);
  size_t keyLength = strlen(key);
  /* Modificar tamaño de payload a un multiplo de 16 bytes
  if(payloadLength % 16 != 0){
    char* input = (char*) malloc(1 + payloadLength%16 + payloadLength);
  }
  */
  size_t inputLength = strlen(payload); //se debe mejorar
  mbedtls_aes_context aes;
  mbedtls_aes_init(&aes);
  mbedtls_aes_setkey_enc(&aes, (const unsigned char *)key, keyLength*8);
  mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_ENCRYPT, inputLength, iv, (const unsigned char*)payload, output);
  mbedtls_aes_free(&aes);
}

// AES CBC ENCRYPT DECRYPT
void mg_aescbc_decrypt(char* key, char* payload, unsigned char* iv, unsigned char* output){
  size_t payloadLength = strlen(payload);
  size_t keyLength = strlen(key);  
  mbedtls_aes_context aes; 
  mbedtls_aes_init(&aes);
  mbedtls_aes_setkey_enc(&aes, (const unsigned char*)key, payloadLength*8);
  mbedtls_aes_crypt_cbc(&aes, MBEDTLS_AES_DECRYPT, payloadLength, iv, (const unsigned char*)payload, output);
  mbedtls_aes_free( &aes );
}

bool mgos_crypto_init(void) {
  return true;
}
