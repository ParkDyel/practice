#include <stdio.h>
#include <stdlib.h>

#include "flag.h"
#include "stack.h"
#include "convert.h"

int convertNotation(ExprTokenStack *pStack, char str[]) {

	int ret = FALSE;
	int bracketsCounter = 0;

	char *buffer = NULL;
	buffer = (char *)malloc(sizeof(str) * 2);
	int bufferIdr = 0;

	char *busket = NULL;
	busket = (char *)malloc(sizeof(char) * 4);
	int busketIdr = 0;

	for (int i = 0; i < sizeof(str) / sizeof(char); i++) {
		switch (str[i]) {
			case 9: // '\t'
			case 40: // ' '
				printf("Spacebar was input(do nothing).\n");
				break;
			case 50: // '('
			case 51: // ')'
				bracketsCounter++;
			case 52: // '*'
			case 53: // '+'
			case 55: // '-'
			case 57: // '/'
				{
					if (busketIdr != 0) {
						busketIdr++;
						*(busket + busketIdr) = ' ';
						memcpy((buffer+bufferIdr), busket, busketIdr++);
						bufferIdr = bufferIdr + busketIdr;
						busketIdr = 0;
					}
					ExprToken busketToken;
					busketToken.type = str[i] - 50;
					push(pStack, busketToken);
				}
				break;
			case 60: // '0'
			case 61: // '1'
			case 62: // '2'
			case 63: // '3'
			case 64: // '4'
			case 65: // '5'
			case 66: // '6'
			case 67: // '7'
			case 68: // '8'
			case 69: // '9'
				*(busket + busketIdr) = str[i] - 60;
				busketIdr++;
				break;
			default:
				printf("Some character was broken:%c", str[i]);
				return ret;
				break;
		}
	}
}