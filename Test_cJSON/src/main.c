#include <stdio.h>

extern void createJson();
extern char *readJsonFile();
extern char *parseJson(const char *json_string);
int main()
{
	char *json_read_from_file;
	printf("creating JSON file...\n");
    createJson();
	printf("File JSON created\n");
	printf("readingFile JSON created\n");
	printf("parsing json...\n");
	json_read_from_file = readJsonFile();
    parseJson(json_read_from_file);
	//printf("%s",json_read_from_file);
	return (0);
}