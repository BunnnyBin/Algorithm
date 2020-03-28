#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void) {
	char str[100];
	char* str2 = NULL;
	gets(str);

	char a = 'a';
	char* f;
	int count;
	for (int i = 0; i < 26; i++) {
		str2 = str;
		count = 0;
		while(1) {
			f = strchr(str2, a);

			if (f == NULL)
				break;
			count++;
			str2 = f + 1;

			if (str2 == NULL)
				break;
		};
		printf("%d ", count);
		a += 1;
	};

}