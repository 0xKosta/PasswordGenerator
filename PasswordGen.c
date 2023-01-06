#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

void generatePwd(int length) {
    srand(time(NULL));
    char alphabet[26] = {
    'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
    'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
    'w', 'x', 'y', 'z'
    };

    char numbers[10] = {
      '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'
    };

    char symbols[7] = {
      '!', '@', '#', '%', '&', '.', ','
    };

    char generatedPassword[length];

    for (int i = 0; i < length; i++) {
        int choice = rand()%3;
        switch (choice) {
            case 0 : {
                if ((rand()%2) == 1) {
                    generatedPassword[i] = toupper(alphabet[rand()%(26-0)]);
                }
                else {
                    generatedPassword[i] = alphabet[rand()%(26-0)];
                }
                break;
            }
            case 1 : {
                generatedPassword[i] = symbols[rand()%(7-0)];
                break;
            }
            case 2 : {
                generatedPassword[i] = numbers[rand()%10];
                break;
            }
            default : {
                fprintf(stderr, "Error generating password.");
                exit(98);
            }
        }
    }
    printf("Your password has been generated:\n%s\n", generatedPassword);
}

int main(int argc, char * argv[]) {


    if (argc != 2) {
        fprintf(stderr,
        "Incorrect arguments! Correct usage -> %s [length]",
        argv[0]);
        exit(99);
    }
    generatePwd(atoi(argv[1]));
    return 0;

}
