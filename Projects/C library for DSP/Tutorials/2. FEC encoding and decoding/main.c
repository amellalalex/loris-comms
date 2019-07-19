#include <stdio.h>
#include <liquid/liquid.h>

int main()
{
    /////////////////////
    //      Setup      //
    /////////////////////

    //--- Set FEC encoding scheme ---//
    fec_scheme fec_encoding_scheme = LIQUID_FEC_HAMMING74;

    //--- Set input message length in bytes ---//
    unsigned int msg_len = 8;

    //--- Calculate encoded message length in bytes ---//
    unsigned int msg_encoded_len = fec_get_enc_msg_length(fec_encoding_scheme, msg_len);

    //--- Create placeholders ---//

    unsigned char msg[msg_len];
    unsigned char msg_encoded[msg_encoded_len];
    unsigned char msg_decoded[msg_len];


    /////////////////////
    //       Run       //
    /////////////////////

    //--- Create FEC encoding object ---//
    fec fec_obj = fec_create(fec_encoding_scheme, NULL); // (the second parameter is essentially ignored).

    //--- Create message ---//
    for(int x = 0; x < msg_len; x++) msg[x] = x;

    //--- Encode message ---//
    fec_encode(fec_obj, msg_len, msg, msg_encoded);

    //--- Corrupt encoded message ---//
    msg_encoded[0] ^= 0x01; // (flip bit)

    //--- Decode message ---//
    fec_decode(fec_obj, msg_len, msg_encoded, msg_decoded); // (function required length of decoded message, not the encoded parameter).

    //--- Count bit errors ---//
    unsigned int bit_errs = count_bit_errors_array(msg, msg_decoded, msg_len);

    
    ///////////////////////////////
    //       Print results       //
    ///////////////////////////////

    //--- Original message ---//
    printf("[*] Original message: [%3u] ", msg_len);
    for(int x = 0; x < msg_len; x++)
        printf("%.2X ", msg[x]);
    printf("\n");

    //--- Encoded message ---//
    printf("[*] Encoded message: [%3u] ", msg_encoded_len);
    for(int x = 0; x < msg_encoded_len; x++)
        printf("%.2X ", msg_encoded[x]);
    printf("\n");

    //--- Decoded message ---//
    printf("[*] Decoded message: [%3u] ", msg_len);
    for(int x = 0; x < msg_len; x++)
        printf("%.2X ", msg_decoded[x]);
    printf("\n");

    //--- Number of bit errors ---//
    printf("[*] Number of bit errors encountered: %3u / %3u\n", bit_errs, msg_len * 8);

    return 0;
}
