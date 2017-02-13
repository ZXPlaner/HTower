/*
 * HTower.cpp
 *
 *  Created on: 3 февр. 2017 г.
 *      Author: navis
 */

#include "HTower.h"
#include <stdio.h>
//---------------------------------------------------------
HTower::HTower(unsigned char height)
{
	this->leftTrunk    = new Trunk(height, true);
	this->centralTrunk = new Trunk(height, false);
	this->rightTrunk   = new Trunk(height, false);
  this->moves        = 0;
}
//--------------------------------------------------------
HTower::~HTower()
{
	delete this->leftTrunk;
	delete this->centralTrunk;
	delete this->rightTrunk;
}
//--------------------------------------------------------
void HTower::move(T_trunkPos srcTrunk, T_trunkPos destTrunk)
{
	Trunk *pSrcTrunk;
	Trunk *pDestTrunk;

	switch(srcTrunk)
	{
	case tpLeft:
		pSrcTrunk = this->leftTrunk;
		break;
	case tpCentral:
		pSrcTrunk = this->centralTrunk;
		break;
	case tpRight:
		pSrcTrunk = this->rightTrunk;
		break;
  default:
    return;
	}

	switch(destTrunk)
	{
	case tpLeft:
		pDestTrunk = this->leftTrunk;
		break;
	case tpCentral:
		pDestTrunk = this->centralTrunk;
		break;
	case tpRight:
		pDestTrunk = this->rightTrunk;
		break;
  default:
    return;
	}

	if(pSrcTrunk->watch() < pDestTrunk->watch())
	{
		pDestTrunk->push(pSrcTrunk->pop());
	}
	else
	{
    printf("Forbidden Move\n");
		// exeption "forbidden move"
	}

	moves++;

	if(pDestTrunk->isItFull())
  {
    printf("You re WIN in %d moves\n", this->moves);
    // exeption Win!
  }
  else
  {
    printf("Moving...\n");
    // exeption move
  }

}
//--------------------------------------------------------

