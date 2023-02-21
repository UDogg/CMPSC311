#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "mdadm.h"
#include "jbod.h"

uint32_t encode_op(int cmd, int disk_num, int block_num)
{
  uint32_t op = 0;
  op |= (cmd<<26);
  op |= (disk_num<<22);
  op |= block_num;
  return op;
}
int mdadm_mount(void) {
  uint32_t op = encode_op(JBOD_MOUNT,0,0);
  printf("operation : %d\n", op);
  int c = jbod_operation(op, NULL);
  printf("Value of C: %d\n",c);
  int ret = -1;
  if(c==0)
  {
    ret = 1;
  }
  return ret;
}

int mdadm_unmount(void) {
  uint32_t op = encode_op(JBOD_UNMOUNT,0,0);
  int a = jbod_operation(op,NULL);
  printf("operation : %d\n", op);
  printf("Value of a: %d\n",a);
  int d = -1;
  if(a==0)
  {
    d = 1;
  }
  if(a!=0)
  {
    d = -1;
  }
  return d;
}

int mdadm_read(uint32_t addr, uint32_t len, uint8_t *buf) 
{
  /*int disk_num;
  int block_num;
  int offset;
  //logic for disk_num ,offset and block_num
  disk_num = addr/(256*256*16);
  offset = addr%(256*256*16);
  block_num = disk_num/(256);
  int offset_block = disk_num%(256);
  uint32_t op = JBOD_READ_BLOCK;
  //translate_address(addr, &disk_num, &block_num &offset);
  //seek() function write seek to disk and seek to block
  uint8_t mybuf[256];
  int b = jbod_operation(op, mybuf);
  
  //char buf[256];//use seek to disk takes in disk number
  //uint32_t op = 0;//then seek to block takes in block number
  //jbod_operation(op, buf);
  return len;
*/
 return -1;
}
