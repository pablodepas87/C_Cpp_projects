#include <stdio.h>
 
extern void test_extern_errno(); 
extern void test_define_errno();
extern void test_range_errno();
extern void test_limits();
extern void test_float();

int main()
{
    printf("\t\t\n\nTEST errno.h limits.h float.h\n\n\n");

	printf("Test errno\n\n");
	
	test_extern_errno();
	test_define_errno();
	test_range_errno();

	printf("\n\nTest limits\n\n"); 
	test_limits(); 

	printf("\n\nTest float\n\n");
	test_float();
    
	return (0);
}