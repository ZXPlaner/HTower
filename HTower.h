/*
 * HTower.h
 *
 *  Created on: 3 февр. 2017 г.
 *      Author: navis
 */

#ifndef HTOWER_H_
#define HTOWER_H_

#include "Trunk.h"


enum T_trunkPos
{
  tpLeft,
	tpCentral,
	tpRight
};


class HTower
{
public:
	HTower(unsigned char height);
	virtual ~HTower();
	void move(T_trunkPos srcTrunk, T_trunkPos destTrunk);
private:
	Trunk *leftTrunk;
	Trunk *centralTrunk;
	Trunk *rightTrunk;
};

#endif /* HTOWER_H_ */
