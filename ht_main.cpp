/*
 * ht_main.cpp
 *
 *  Created on: 3 февр. 2017 г.
 *      Author: navis
 */

#include "HTower.h"
#include <stdio.h>


static void moveTop(HTower *ht, T_trunkPos srcTrunk,
                    T_trunkPos destTrunk, unsigned char trunkHeight);

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
  }
  while(towerHeight == 0 || towerHeight > 10);

  HTower *h_tow = new HTower((unsigned char) towerHeight);
  //h_tow->printImage();
  moveTop(h_tow, tpLeft, tpRight, (unsigned char)towerHeight);

  delete h_tow;
}

/*print return code string
 *
 */


static void moveTop(HTower *ht, T_trunkPos srcTrunk,
                    T_trunkPos destTrunk, unsigned char trunkHeight)
{
  T_trunkPos intermediateTrunk = tpLeft;

  if(destTrunk == tpLeft || srcTrunk == tpLeft)
  {
    intermediateTrunk = tpRight;

    if(destTrunk == tpRight || srcTrunk == tpRight)
      intermediateTrunk = tpCentral;
  }

  if(trunkHeight > 1)
  {
    moveTop(ht, srcTrunk, intermediateTrunk, (unsigned char)(trunkHeight - 1));
  }

  ht->move(srcTrunk, destTrunk);


  if(trunkHeight > 1)
  {
    moveTop(ht, intermediateTrunk, destTrunk, (unsigned char)(trunkHeight - 1));
  }
}

