#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "workshop3.h"

int main() {
	Customer customer;
	getCustomerInfo(&customer);

	printf("\nYou entered:\n");
	printf("%s %s\n", customer.firstName, customer.lastName);
	printf("%s\n", customer.streetAddress);
	printf("%s, %s\n", customer.city, customer.province);
	printf("%s\n", customer.postalCode);

	return 0;
}

void getCustomerInfo(Customer* customer) {
	char input[100];
	char formattedPostalCode[10];

	// Prompt and validate first name
	do {
		printf("Enter your first name: ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';
	} while (strlen(input) == 0);
	strcpy(customer->firstName, input);

	// Prompt and validate last name
	do {
		printf("Enter your last name: ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; 
	} while (strlen(input) == 0);
	strcpy(customer->lastName, input);

	// Prompt and validate street address
	do {
		printf("Enter your street address: ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; 
	} while (strlen(input) == 0);
	strcpy(customer->streetAddress, input);

	// Prompt and validate city
	do {
		printf("Enter your city: ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; 
	} while (strlen(input) == 0);
	strcpy(customer->city, input);

	// Prompt and validate province
	do {
		printf("Enter your province: ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; 
	} while (strlen(input) == 0);
	strcpy(customer->province, input);

	// Prompt and validate postal code
	do {
		printf("Enter your postal code: ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0'; 
	} while (!isValidPostalCode(input, formattedPostalCode));
	strcpy(customer->postalCode, formattedPostalCode);
}

bool isValidPostalCode(char* postalCode, char* formattedPostalCode) {
	char temp[10];
	int j = 0;

	// Remove spaces and convert to uppercase
	for (int i = 0; postalCode[i] != '\0'; i++) {
		if (!isspace(postalCode[i])) {
			if (j < sizeof(temp) - 1) {
				temp[j++] = toupper(postalCode[i]);
			}
			else {
				return false;
			}
		}
	}
	temp[j] = '\0';

	// Validate length
	if (strlen(temp) != 6) {
		printf("Invalid Entry: Enter your postal code: ");
		return false;
	}
	// Validate format 
	for (int i = 0; i < 6; i++) {
		if ((i % 2 == 0 && !isalpha(temp[i])) || (i % 2 == 1 && !isdigit(temp[i]))) {
			printf("Invalid Entry: Enter your postal code: ");
			return false;
		}
	}
	// Format the postal code as "A1A 1A1"
	snprintf(formattedPostalCode, 8, "%c%c%c %c%c%c", temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]);
	return true;
}

void toUpperCase(char* str) {
	while (*str) {
		*str = toupper(*str);
		str++;
	}
}

void trimSpaces(char* str) {
	char* i = str;
	char* j = str;
	while (*j != 0) {
		*i = *j++;
		if (*i != ' ') {
			i++;
		}
	}
	*i = 0;
}
