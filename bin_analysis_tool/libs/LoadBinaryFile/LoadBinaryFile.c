#include "LoadBinaryFile.h"
#include <stdio.h>
#include <stdlib.h>

void LoadBinaryFile( BinaryInfo* bin_info, char* bin_file_path ){
  
  FILE *bin_file = fopen( bin_file_path, "rb"); //rb : 바이너리모드로 읽기
  fseek(bin_file, 0, SEEK_END );
  //fseek(파일포인터, offset, 기준이 되는 위치 ) 기주이 되는 위치로부터 offset 만큼 떨어진 곳으로 이동하는 코드이다. 
  //즉 , 위의 줄은 파일의 마지막 위치로 이동하게되는 코드임 ..
  // SEEK_END ==  마지막, SEEK_SET == 처음 , SEEK_CUR == 현재 .
  bin_info ->_size = ftell( bin_file );

  if (bin_info -> _size == 0) {
    printf("bin file size if 0\n");
    return ;
  }

  fseek(bin_info , 0, SEEK_SET);
  bin_info -> _binary_data = (uint8_t)malloc(bin_info -> _size);
  if ( bin_info -> _binary_data  == NULL){
    printf( "malloc error !\n");
    return ;
  } 
  uint64_t read_result = fread( bin_info->_binary_data, 1, bin_info->_size, bin_file );
    if ( read_result != bin_info->_size )
    {
        perror( "File read error\n" );
        free( bin_info->_binary_data );
        return;
    }

    fclose( bin_file ); 
}

void PrintBinary( BinaryInfo *bin_info )
{
    uint64_t offset = 0;
    for ( int i = 0; i < bin_info->_size; i += 16 )
    {
        // print offset
        if ( i == 0 || i % 16 == 0 )
        {
            printf( "%08lx: ", offset );
            offset += 0x10;
        }

        // print hex
        for ( int j = 0; j < 16; ++ j )
        {
            if ( i + j >= bin_info->_size )
            {
                printf( "  " );
            }
            else
            {
                printf( "%02x", bin_info->_binary_data[i + j] );
            }
            if ( j % 2 != 0 )
            {
                printf( " " );
            }
        }
        printf( " " );

        // print character
        for ( int j = 0; j < 16; ++ j )
        {
            if ( i + j >= bin_info->_size )
            {
                break;
            }
            if ( bin_info->_binary_data[i + j] >= 0x20
                && bin_info->_binary_data[i + j] <= 0x7e )
            {
                printf( "%c", bin_info->_binary_data[i + j] );
            }
            else
            {
                printf( "." );
            }
        }
        printf( "\n" );
    }

}
