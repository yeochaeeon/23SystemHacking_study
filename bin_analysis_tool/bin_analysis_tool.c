#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "LoadBinaryFile.h"
#include "ELFanalysis.h"

void PrintMenu( void ){

  printf("0:Quit \n");
  printf("1:Print Hex dump\n");
  printf("2:Print ELF header\n");

}

int main(int argc, char *argv[]){

  int option;
  char * bin_file_path = NULL;
  
  while( (option = getopt(argc, argc, "f:")) != -1 ) { 
  //올바른 옵션을 제공할때까지 무한루프 !
  //더이상 옵션이 없으면 -1 리턴.
    switch( option ) {
      
      case 'f' : {
        bin_file_path = (char * ) malloc(strlen(optarg) + 1 );
        strcpy(bin_file_path, optarg );
        continue;
      }
      default : {
        break;
      }
    }
    break;
  }
  BinaryInfo* bin_info = (BinaryInfo*) malloc( sizeof ( BinaryInfo ) );
  LoadBinaryFile( bin_info, bin_file_path );

  while(1){
    int menu = -1;

    PrintMenu();
    printf("choice menu : ");
    scanf("%d", &menu);

    if ( menu == 0 ) break ;

    switch ( menu ){
      case 1:{
        PrintBinary(bin_info);
        break;
      }
      case 2:{
        printf("Check ELF Sign : %d\n", CheckELFSignature( bin_info ));
        printf("ISA : %s\n", GetISA(bin_info));
        break;
      }
      default:
        while( getchar() != '\n' );
        //개행이 아닌경우 계속 버퍼를 비워줌. 
        //엔터를 누를 때까지 입력 버퍼를 비운다. 
        printf(" Wrong menu\n " );
        break;
      
    }
  }
  
  free(bin_info -> _binary_data);
  free(bin_info);
  free(bin_file_path);

  return 0;
}
