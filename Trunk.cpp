//
// Created by alexey on 12.02.17.
//

#include "Trunk.h"


void Trunk::push(unsigned char disk)
{
  this->disks.push_back(disk);
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
    disk = 255; // max size (base)

  return disk;
}

unsigned char Trunk::peek()
{
  unsigned char disk;

  if(this->disks.size() > 0)
  {
    disk = this->disks[this->disks.size() - 1];
  }
  else
    disk = 255; // max size (base)

  return disk;
}

unsigned char Trunk::size()
{
  return (unsigned char)this->disks.size();
}