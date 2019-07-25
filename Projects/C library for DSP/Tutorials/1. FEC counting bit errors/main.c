#include <stdio.h>
#include <liquid/liquid.h>

int main()
{
    /////////////////////
    //      Setup      //
    /////////////////////

    //--- Set input message length in bytes ---//
    unsigned int msg_len = 8;

    //--- Set encoded message length in bytes ---//
    unsigned int msg_encoded_len = msg_len; // (no encoding yet)

    //--- Create placeholders ---//

    unsigned char msg[msg_len];
    unsigned char msg_encoded[msg_encoded_len];
    unsigned char msg_decoded[msg_len];


    /////////////////////
    //       Run       //
    /////////////////////

    //--- Create message ---//
    for(int x = 0; x < msg_len; x++) msg[x] = x;

    //--- 'Encode' message ---//
    for(int x = 0; x < msg_encoded_len; x++) msg_encoded[x] = msg[x];

    //--- Corrupt encoded message ---//
    msg_encoded[0] ^= 0x01; // (flip bit)

    //--- 'Decode' message ---//
    for(int x = 0; x < msg_len; x++) msg_decoded[x] = msg_encoded[x];

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
