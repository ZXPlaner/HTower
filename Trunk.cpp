//
// Created by alexey on 12.02.17.
//

#include "Trunk.h"


void Trunk::push(unsigned char disk)
{
  if(this->disks.size() == 0 ||
     disk < this->disks[this->disks.size() - 1])
    this->disks.push_back(disk);
  else
    throw "push err: forbidden move\n";
}

unsigned char Trunk::pop()
{
  unsigned char disk;
  if(this->disks.size() > 0)
  {
    disk = this->disks[this->disks.size() - 1];
    this->disks.pop_back();
  }
  else
    throw "pop error: trunk is empty\n";

  return disk;
}
