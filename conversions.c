/*
 * Jacob Reed
 * TCSS 371 Section A
 * Autumn 2017
*/
 
#include <stdio.h>
#include <string.h>

/* 
 * Converts decimal to hex */
void convert_decimal_to_hex(int decimal, char hex[]) {
	int r, i = 0;
	
    if(decimal < 10) {
        hex[1] = '\0';
    } else {
        hex[2] = '\0';
    }
    
    while(decimal != 0) {
		r = decimal % 16;
		if(r < 10) {
			hex[i] = 48 + r; 	
		} else {
			hex[i] = 55 + r;
		}
		decimal = decimal / 16;
		i++;	
	}
}

/*
 * Converts decimal to binary string then reverses it for correct output */
void convert_decimal_to_binary(int decimal, char binary[]) {
    int i = 8, k = 0;
    for(i; i >= 0; i--) {
        k = decimal >> i;
        if(k & 1) {
            binary[i] = '1';
        } else {
            binary[i] = '0';
        }
    }
    
    binary[8] = '\0'; //End string
    
    /* Reverse String */
    char t, *e = binary + strlen(binary);
    while ( --e > binary ) { t = *binary;*binary++=*e;*e=t; }
}

void main() {
	/* Decimal -> Hex Test */
    char hex[2];
    int dec = 255;
	convert_decimal_to_hex(dec, hex);
    if(dec < 10) {
        printf("%d to hex is %s\n", dec, hex);
    } else if(dec < 16){
        printf("%d to hex is %c\n", dec, hex[0]);
    } else {
        printf("%d to hex is %c%c\n", dec, hex[1], hex[0]);
    }
    /*End Test 1 */
    
    /* Decimal -> Binary Test */
    char byte[8];
    int dec2 = 25;
    convert_decimal_to_binary(dec2, byte);
    printf("%d to binary is %s\n", dec2, byte);
    /* End Test 2 */
	
}
