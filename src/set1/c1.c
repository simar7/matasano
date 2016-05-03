#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>
#include <openssl/evp.h>

#define SIZE 1024
#define INPUT_HEX_STR "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
#define OUTPUT_BASE64_STR "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"

char* _hex_to_base64(char* input_string) {
    BIO *bio, *b64;
    char output_string[SIZE];

    bio = BIO_new(BIO_s_mem());
    b64 = BIO_new(BIO_f_base64());
    
    BIO_push(b64, bio);
    BIO_set_flags(b64, BIO_FLAGS_BASE64_NO_NL);
    BIO_write(b64, input_string, strlen(input_string));
    BIO_flush(b64);
    
    BIO_read(bio, output_string, strlen(input_string)); 

    BIO_free(bio);
    BIO_free(b64);

    return (char*) output_string;
}

int main(int argc, char *argv[]) {

    char* input_string = INPUT_HEX_STR;

    char* output_string = _hex_to_base64(input_string);
    if (!strcmp(output_string, OUTPUT_BASE64_STR)) {
        printf("%s", "Strings match!\n");
    } else {
        printf("%s", "Strings don't match!\n");
        printf("Resulting output = %s\n", output_string);
        printf("Desired   output = %s\n", OUTPUT_BASE64_STR);
        return -1;
    }
    return 0;
}
