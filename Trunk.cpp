//
// Created by alexey on 12.02.17.
//

#include "Trunk.h"

Trunk::Trunk(unsigned char height, bool isFull)
{
  this->disks = new unsigned char[height];
  this->height = height;

  for(unsigned char i = 0; i < height; i++)
  {
    if(isFull)
      this->disks[i] = height - i;
    else
      this->disks[i] = 0;
  }

  if(isFull)
    this->top = height;
  else
    this->top = 0;
}

Trunk::~Trunk()
{
  delete [] this->disks;
}

void Trunk::push(unsigned char disk)
{
  if(this->top < this->height)
    this->disks[this->top++] = disk;
  else
  {
    throw "cannot push. trunk is full\n";
  }
}

unsigned char Trunk::pop()
{
  unsigned char disk;
  if(this->top > 0)
  {
    disk = this->disks[this->top - 1];
    this->top--;
  }
  else
    disk = 255; // max size (base)

  return disk;
}

unsigned char Trunk::watch()
{
  unsigned char disk;
  if(this->top > 0)
    disk = this->disks[this->top - 1];
  else
    disk = 255; // max size (base)

  return disk;
}

bool Trunk::isItFull()
{
  return this->top == this->height;
}