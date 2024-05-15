#include <stdio.h>
#include <string.h>
#define MAX_STRING_LEN 30
#define MAX_PRODUCTS 10
#define MAX_CART 10

struct Cart
{
	int items[MAX_CART];
	int nItems;
};
int findString(const char str[], const char list[][MAX_STRING_LEN + 1], const int nstrings)
{
	int i, result = -1, found = 0;
	for (i = 0; i < nstrings && !found; i++)
	{
		if (0 == strcmp(str, list[i]))
		{
			result = i;
		}
	}
	return result;
}
int add2Cart(struct Cart* cart, const int item)
{
	int result = 0;

	if (cart->nItems >= MAX_CART)  //  10
	{
		result = -1;
	}
	else
	{
		if (item >= 0 && item < MAX_PRODUCTS)  //  10
		{
			cart->items[cart->nItems] = item;
			cart->nItems++;
		}
		else
		{
			result = -2;
		}
	}
	return result;
}
int integrationTest(struct Cart cart, char productName[], const char productList[]) {
	int findStringResult;
	int add2CartResult;
	int finalResult;
	int numProducts = sizeof(productList) / sizeof(productList[0]);
	// Test execution
	findStringResult = findString(productName, productList, numProducts);
	add2CartResult = add2Cart(&cart, findStringResult);
	finalResult = findStringResult != -1 && add2CartResult == 0 ? 0 : -1;
	// Comparison
	printf("Test for %s\n", productName);
	printf("\n");
	printf("findStringResult() returned %d (%s)\n", findStringResult, productName);
	printf("add2Cart() returned %d\n", add2CartResult);
	printf("%s\n", cart.nItems == 1 ? "item Successfully added to the cart" : "item Failed to be added to the cart");   // show results that one item has been added to the cart
	printf("%s\n", cart.items[0] == findStringResult ? "item Successfully in correct index" : "item Failed to be in correct index"); // show results that the added item is at the correct index in the cart
	printf("%s\n", findStringResult != -1 ? "findString() test Successful" : "findString() test Failed");        // show results for findString
	printf("%s\n", add2CartResult == 0 ? "add2Cart() test Successful" : "add2Cart() test Failed");        // show results for add2Cart
	printf("%s\n", finalResult == 0 ? "Integration test Passed." : "Integration test Failed.");
	printf("----------------------------------------\n");
	return finalResult;
}
int main() {
	// Test setup
	struct Cart cart = { {0}, 0 }; // initialize a cart
	const char productList[][MAX_STRING_LEN + 1] = {	// initialize a list of products
		"flour",
		"sugar",
		"bananas",
		"potatoes",
		"milk",
		"tea" };
	char productName[MAX_STRING_LEN + 1]; // initialize Product Name to add to the cart
	strcpy_s(productName, MAX_STRING_LEN, "milk");  // set Product Name to "milk"
	int numProducts = sizeof(productList) / sizeof(productList[0]);	// get size of the productList array
	int i;
	// Tests through all products in the descriptions array
	for (i = 0; i < numProducts; i++) {
		integrationTest(cart, productName, productList);
		strcpy_s(productName, MAX_STRING_LEN, productList[i]);
	}
	return 0;
}