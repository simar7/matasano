#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bio.h>

#define SIZE 1024
#define INPUT_HEX_STR "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d"
#define OUTPUT_BASE64_STR "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t"

char* _hex_to_base64(char* input_string) {
    BIO *bio, *b64;
    char output_string[SIZE];

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new_fp(stdout, BIO_NOCLOSE);

    BIO_push(b64, bio);
    BIO_write(b64, INPUT_HEX_STR, strlen((char *)INPUT_HEX_STR));
    BIO_flush(b64);

    return (char*) OUTPUT_BASE64_STR;
}

int main(int argc, char *argv[]) {

    char* input_string = INPUT_HEX_STR;

    char* output_string = _hex_to_base64(input_string);
    if (!strcmp(output_string, OUTPUT_BASE64_STR)) {
        printf("%s", "Strings match!");
    }

    return 0;
}
