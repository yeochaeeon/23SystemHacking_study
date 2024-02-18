#include <stdio.h>
#include <stdlib.h>

void init( void )
{
	setvbuf(stdin, 0, 2, 0);
	setvbuf(stdout, 0, 2, 0);
	setvbuf(stderr, 0, 2, 0);
}

void get_shell( void )
{
	system( "/bin/sh" );
}

int main( void )
{
	char buf[8];
	
	init();

	printf( "Do you want some pie??\n" );
	printf( "Delicious pie is here : %p\n", main );
	printf( "Can you find where it is?\n" );
	
	fgets( buf, 0x80, stdin );
	return 0;
}
