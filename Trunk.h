//
// Created by alexey on 12.02.17.
//

#ifndef HTOWER_TRUNK_H
#define HTOWER_TRUNK_H

#include <vector>

class Trunk
{
public:
  //Trunk();
  //virtual ~Trunk();
  void push(unsigned char disk);
  unsigned char pop();
  unsigned char peek();
  unsigned char size();

private:
  std::vector<unsigned char> disks;

};


#endif //HTOWER_TRUNK_H
