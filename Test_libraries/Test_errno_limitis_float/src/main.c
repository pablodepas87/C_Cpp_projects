#include <stdio.h>
 
extern void test_extern_errno(); 
extern void test_define_errno();
extern void test_range_errno();

int main()
{
    printf("\t\t\n\nTEST errno.h limits.h float.h\n\n\n");

	printf("Test errno");
	
	test_extern_errno();
	test_define_errno();
	test_range_errno();
	 
    
	return (0);
}