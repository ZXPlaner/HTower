/*
 * HTower.cpp
 *
 *  Created on: 3 февр. 2017 г.
 *      Author: navis
 */

#include "HTower.h"
//---------------------------------------------------------
HTower::HTower(unsigned char height)
{
	this->leftTrunk    = new Trunk();
	this->centralTrunk = new Trunk();
	this->rightTrunk   = new Trunk();

  for(unsigned char i = height; i >0; i--)
  {
    this->leftTrunk->push(i);
  }

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

	if(pSrcTrunk->peek() < pDestTrunk->peek())
	{
		pDestTrunk->push(pSrcTrunk->pop());
	}
	else
	{
    throw "Forbidden Move\n";
	}

	moves++;

	if(!this->leftTrunk->size() &&
     !this->centralTrunk->size() &&
     this->rightTrunk->size())
  {
    throw this->moves;
  }

}
//--------------------------------------------------------

