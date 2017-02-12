/*
 * ht_main.cpp
 *
 *  Created on: 3 февр. 2017 г.
 *      Author: navis
 */

#include "HTower.h"
#include <stdio.h>

static void printRetCode(int retCode);
static void moveTop(HTower *ht, unsigned char srcTrunk,
					unsigned char destTrunk, unsigned char trunkHeight);

int main()
{
	int srcTrunk, destTrunk, towerHeight, playType;
	int retCode = 0;

	do
	{
	  printf("Please, enter tower height (max 10)\r\n");
		scanf("%d", &towerHeight);
		if(towerHeight == 0 || towerHeight > 10)
	    printf("wrong stick size\r\n");
	}while(towerHeight == 0 || towerHeight > 10);

    HTower *h_tow = new HTower((unsigned char)towerHeight);
    h_tow->printImage();

	do
	{
		puts("Press:\r\n");
		puts("1 - human play\r\n");
		puts("2 - computer play\r\n");
		scanf("%d", &playType);
		if(playType < 1 || playType > 2)
			puts("wrong play type\r\n");
	}while(playType < 1 || playType > 2);

	if(playType == 1) {
		while (retCode <= 0) {

			printf("Please, enter your move: source trunk number (1,2,3)..\r\n");
			scanf("%d", &srcTrunk);
			printf("Please, enter your move: destination trunk number (1,2,3)\r\n");
			scanf("%d", &destTrunk);

			retCode = h_tow->move((unsigned char) (srcTrunk - 1), (unsigned char) (destTrunk - 1));

			printRetCode(retCode);

			h_tow->printImage();
		}
	}
	else if(playType == 2)
	{
		moveTop(h_tow, 1, 3, towerHeight);
	}

	delete h_tow;
}

/*print return code string
 *
 */

static void printRetCode(int retCode)
{
	switch(retCode)
	{
	case HT_WRONG_SRC_NUM :
		printf("Wrong source trunk number\r\n");
		break;
	case HT_WRONG_DEST_NUM :
		printf("Wrong destination trunk number\r\n");
		break;
	case HT_FORBDN_MOVE :
		printf("Forbidden move\r\n");
		break;
	case HT_RIGHT_MOVE :
		printf("OK/Moving..\r\n");
		break;
	default :
		printf("You are WIN in %d moves\r\n", retCode);
		break;
	}

}

static void moveTop(HTower *ht, unsigned char srcTrunk,
					unsigned char destTrunk, unsigned char trunkHeight)
{
	int retCode;
	unsigned char intermediateTrunk = srcTrunk^destTrunk;

	if(trunkHeight > 1)
	{
		moveTop(ht, srcTrunk, intermediateTrunk, trunkHeight - 1);
	}

	retCode = ht->move(srcTrunk - 1, destTrunk - 1);

	printRetCode(retCode);

	ht->printImage();

	if(trunkHeight > 1)
	{
		moveTop(ht, intermediateTrunk, destTrunk, trunkHeight - 1);
	}
}

