#include <ctr/console.h>
#include <ctr/printf.h>
#include <ctr/draw.h>
#include "sdmmc/sdmmc.h"

#define PROD 1

void scribble_screen(void);

int main(void){
	uint8_t CID[16] = { 0x00 };
	uint8_t NCID[16] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF };
	
	draw_init((draw_s*) 0x23FFFE00);
	console_init(0xFFFFFF, 0);
	draw_clear_screen(SCREEN_TOP, 0x1111111);
	sdmmc_sdcard_init();
	
	printf("Getting CID..\n\n");
	sdmmc_get_cid(PROD, (uint32_t*) CID);
	for(int i = 0; i < sizeof(CID); i++){
		printf("%02X", CID[i]);
	}
	printf("\nNew CID..\n\n");
	for(int i = 0; i < sizeof(NCID); i++){
		printf("%02X", NCID[i]);
	}
	//printf("Writing CID..");
	//rewrite_cid(NCID);
}

/*
int rewrite_cid(uint8_t* CID){
	uint8_t iCID[16] = { 0x00 };
	
	for(int i = 0; i < sizeof(iCID); i++){
		iCID[i] = CID[i];
	}
	
}
*/