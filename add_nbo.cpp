#include <stddef.h> 
#include <stdint.h> 
#include <string.h>
#include <netinet/in.h>
#include <stdio.h> 

uint32_t file_open(char * file_name){

	FILE * pFile = fopen(file_name,"rb");	
	uint32_t temp;	
	uint8_t buffer[sizeof(uint32_t)];

	if (fread(buffer, sizeof(uint8_t), sizeof(uint32_t), pFile) != sizeof(uint32_t)) {
        printf("파일을 읽지 못했습니다.\n");}
        temp = *((uint32_t *)buffer); // buffer를 1바이트 정수의 주소에서 4바이트 정수의 주소로 변경
        fclose(pFile);
        
        temp = (uint32_t)ntohl(temp);
        printf("%d(0x%x)", temp, temp);
        return temp;

}

 

int main(int argc, char * argv[]) {

	uint32_t  accumulate = 0;
	for(int i=1; i < argc; i++){
		accumulate += file_open(argv[i]);
		if(i<argc-1){ printf(" + "); }	
	}
	
	printf(" = %d(0x%x)\n",accumulate,accumulate);
		
}
