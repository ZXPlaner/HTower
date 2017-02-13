//
// Created by alexey on 12.02.17.
//

#ifndef HTOWER_TRUNK_H
#define HTOWER_TRUNK_H


class Trunk
{
public:
  Trunk(unsigned char height, bool isFull);
  virtual ~Trunk();
  void push(unsigned char disk);
  unsigned char pop();
  unsigned char watch();
  bool isItFull();

private:
  unsigned char *disks;
  unsigned char height;
  unsigned char top;
};


#endif //HTOWER_TRUNK_H
