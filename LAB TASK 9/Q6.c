#include <stdio.h>
#include <string.h>
int main() {
    char inputText[100];
    int i ;
    printf("Enter the text to encrypt: ");
    gets(inputText);

    char cipherKey[100];
    printf("Enter the cipher key: ");
    gets(cipherKey);

    char encryptedText[strlen(inputText) + 1];
    char extendedCipherKey[strlen(inputText) + 1];

    int keyIndex = 0;
    for ( i = 0; i < strlen(inputText); i++) {
        extendedCipherKey[i] = cipherKey[keyIndex];
        keyIndex++;
        if (keyIndex == strlen(cipherKey)) {
            keyIndex = 0;
        }
    }

    for ( i = 0; i < strlen(inputText); i++) {
        if (inputText[i] != 32) {
            inputText[i] = inputText[i] - 64;
        }
        extendedCipherKey[i] = extendedCipherKey[i] - 64;
        int encryptedChar = extendedCipherKey[i] + inputText[i];
        encryptedChar = encryptedChar % 26;
        encryptedChar = encryptedChar + 64;

        if (inputText[i] == 32) {
            printf(" ");
        } else {
            printf("%c", encryptedChar);
        }
    }

    return 0;
}
