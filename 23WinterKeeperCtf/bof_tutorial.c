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
	char buf[16];

	init();

	gets( buf );
	printf( "Your input is %s\n", buf );

	return 0;
}

