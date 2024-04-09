#include <stdio.h>

int main(void) {
	int n;
	printf("Digite quantos caracteres tera seu texto: ");
	scanf(" %d%*c", &n);
	
	char letras[n];
	
	if (n < 100) {
		fgets(letras,n+1,stdin);
		
		
		for (int i = 0; i < n ; ++i ){
			printf("%c",letras[i]);
		
		}
		printf("\n");	
	} else {
		printf("Limite de caracteres atingido! ");
		
	}
	return 0;
}

// There are a few reasons why fgets() may not be working in C:
// It is important to check the return value of fgets() and handle the errors accordingly. You should also check if the file is open, the buffer size is appropriate and the file pointer is valid.

// 1. The file being read from may not be open: Make sure that the file has been opened correctly and that the file pointer is not NULL.
// 2. Incorrect buffer size: fgets() reads a maximum of n-1 characters from the file and adds a null terminator. If the buffer size passed to fgets() is too small, the function may not be able to read the entire line.
// 3. The file may have reached the end: If the end of the file has been reached, fgets() will return NULL. Make sure to check the return value of fgets() and handle it accordingly.
// 4. File may be empty or not exist: Make sure the file you are trying to read from exist and have some data.
// 5. Incorrect file mode: Make sure you are opening the file in the correct mode (e.g. "r" for reading, "w" for writing, etc.)
// 6. File pointer is invalid: The file pointer passed to fgets() may be invalid, for example, it is not initialized or it is freed before fgets() is called.