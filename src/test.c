#include "../include/string.h"

int main() {
	char *test = malloc(6 * sizeof(char));
	strcpy(test, "Hello");
	String.print(test, "stdout");
	char *ret = String.begin(test);
	printf("begin: %c\n", *ret);
	ret = String.end(test);
	printf("end: %c\n", *ret);
	char ret2;
	if((ret2 = String.at(test, 3)) != -1) {
		printf("at 3: %c\n", ret2);
	}
	String.append(test, ", friend!");
	String.print(test, "stdout");
	String.push_back(test, '!');
	String.print(test, "stdout");
	ret2 = String.pop_back(test);
	printf("pop_back: %c\n", ret2);
	String.print(test, "stdout");
	String.insert_string(test, "dear ", 7);
	String.print(test, "stdout");
	String.insert_char(test, '?', 6);
	String.print(test, "stdout");
	String.erase_char(test, 6);
	String.print(test, "stdout");
	String.replace_string(test, "Wasup", 0, 4);
	String.print(test, "stdout");
	String.replace_char(test, '?', 18);
	String.print(test, "stdout");
	ret = String.substr(test, 3, 10);
	printf("%s\n", ret);
	String.print(test, "stdout");
	String.copy(test, "We're gonna throw it in reverse");
	String.print(test, "stdout");
	String.erase_string(test, 0, 6);
	String.print(test, "stdout");
	String.erase(test);
	String.delete_string(test);

	return 0;
}
