/*
 * HTower.cpp
 *
 *  Created on: 3 февр. 2017 г.
 *      Author: navis
 */

#include "HTower.h"
#include <string.h>
#include <stdio.h>
//---------------------------------------------------------
HTower::HTower(unsigned char height)
{
  this->trunkHeight = height;
  this->moves     = 0;

	for(int i = 0; i < 3; i++)
	{
		this->p_trunk[i] = new unsigned char[height];

		// set on first stick all disks
		if(i == 0)
		{
			for(int j = 0; j < height; j++)
			{
				p_trunk[i][j] = height - j;
			}
		}
		// other sticks are empty
		else
		{
		  memset(p_trunk[i], 0, height);
		}
	}

}
//--------------------------------------------------------
HTower::~HTower()
{
	for(int i = 0; i < 3; i++)
	{
		delete [] p_trunk[i];
	}
}
//--------------------------------------------------------
int HTower::move(unsigned char srcTrunk, unsigned char destTrunk)
{
	// check stick number
	if(srcTrunk >= 3)
		return HT_WRONG_SRC_NUM;

	if(destTrunk >= 3)
			return HT_WRONG_DEST_NUM;

	// check move possibility
	if(getLastDiskSizeOnStick(srcTrunk) >= getLastDiskSizeOnStick(destTrunk))
	{
		return HT_FORBDN_MOVE;
	}
	setDiskOnStick(getLastDiskSizeOnStick(srcTrunk), destTrunk);
	deleteLastDiskOnStick(srcTrunk);
	moves++;

	if(checkWinCond())
	{
		return moves;
	}
	else
	{
		return HT_RIGHT_MOVE;
	}
}
//--------------------------------------------------------
void HTower::printImage()
{
	for(int stick = 0; stick < 3; stick++)
	{
	  printf("******* ");
	}
	printf("\r\n");
  for(int disk = (trunkHeight - 1); disk >= 0; disk--)
  {
  	for(int stick = 0; stick < 3; stick++)
  	{
  		printf("--%03d-- ", p_trunk[stick][disk]);
  	}
  	printf("\r\n");
  }
  for(int stick = 0; stick < 3; stick++)
  {
  	printf("trunk_%d ", stick + 1);
  }
  printf("\r\n");
}
//--------------------------------------------------------
unsigned char HTower::getLastDiskPosOnStick(unsigned char stick)
{
	unsigned char i = 0;

	while(p_trunk[stick][i] != 0 && i < trunkHeight)
	{
		i++;
	}
	return i;
}
//--------------------------------------------------------
unsigned char HTower::getLastDiskSizeOnStick(unsigned char stick)
{
	unsigned char pos = getLastDiskPosOnStick(stick);

	if(pos == 0)
		return 255;
	else
		return p_trunk[stick][pos - 1];

}
//--------------------------------------------------------
void HTower::setDiskOnStick(unsigned char diskSize, unsigned char stick)
{
	p_trunk[stick][getLastDiskPosOnStick(stick)] = diskSize;
}
//--------------------------------------------------------
void HTower::deleteLastDiskOnStick(unsigned char stick)
{
	unsigned char pos = getLastDiskPosOnStick(stick);

	if(pos != 0)
	  p_trunk[stick][pos - 1] = 0;
}
//--------------------------------------------------------
bool HTower::checkWinCond()
{
  return (getLastDiskPosOnStick(2) == trunkHeight);

}
//--------------------------------------------------------
