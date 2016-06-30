#include <ctr/console.h>
#include <ctr/printf.h>
#include <ctr/draw.h>
#include "sdmmc/sdmmc.h"

#define PROD 0

void scribble_screen(void);

int main(void){
	uint8_t CID[16];
	
	draw_init((draw_s*) 0x23FFFE00);
	console_init(0xFFFFFF, 0);
	draw_clear_screen(SCREEN_TOP, 0x1111111);
	
	printf("Getting CID..\n\n");
	sdmmc_get_cid(PROD, (uint32_t*) CID);
	for(int i = 0; i < sizeof(CID); i++){
		printf("%02X", (unsigned int) CID[i]);
	}
}