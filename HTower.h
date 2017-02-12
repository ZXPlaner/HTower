/*
 * HTower.h
 *
 *  Created on: 3 февр. 2017 г.
 *      Author: navis
 */

#ifndef HTOWER_H_
#define HTOWER_H_

// defines return code
#define HT_WRONG_SRC_NUM  -1
#define HT_WRONG_DEST_NUM    -2
#define HT_FORBDN_MOVE     -3
#define HT_RIGHT_MOVE       0
// return code > 0 is number of moves to win

class HTower
{
public:
	HTower(unsigned char height);
	virtual ~HTower();
	int move(unsigned char srcTrunk, unsigned char destTrunk);
	void printImage();
private:
	unsigned char trunkHeight;
	unsigned char *p_trunk[256];
	int           moves;
	unsigned char getLastDiskPosOnStick(unsigned char trunk);
	unsigned char getLastDiskSizeOnStick(unsigned char trunk);
	void setDiskOnStick(unsigned char diskSize, unsigned char trunk);
	void deleteLastDiskOnStick(unsigned char trunk);
	bool checkWinCond();
};

#endif /* HTOWER_H_ */
