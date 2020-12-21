#include <stdio.h>

extern void createJson();
extern char *readJsonFile();
int main()
{
	char *json_read_from_file;
	printf("creating JSON file...\n");
    createJson();
	printf("File JSON created\n");
	json_read_from_file = readJsonFile();
    printf("%s",json_read_from_file);
	return (0);
}