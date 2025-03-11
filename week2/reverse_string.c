#include <stdio.h>
int main() {
	char str[255];
	scanf("%s", str);
	char rev_str[255];
	int j = 0;
	for(int i = strlen(str)-1; i >=0; i--) {
		rev_str[j++] = str[i]
	}
	rev_str[j] = '\0';
	return 0;
}
