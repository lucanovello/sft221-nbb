#ifndef WORKSHOP3_H
#define WORKSHOP3_H

typedef struct {
	char firstName[30];
	char lastName[30];
	char streetAddress[100];
	char city[30];
	char province[30];
	char postalCode[10];
} Customer;

// Prototypes
void getCustomerInfo(Customer* customer);
bool isValidPostalCode(char* postalCode, char* formattedPostalCode);
void toUpperCase(char* str);
void trimSpaces(char* str);

#endif // WORKSHOP3_H