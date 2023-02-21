#ifndef MDADM_H_
#define MDADM_H_

#include <stdint.h>
#include "jbod.h"
//uint32_t encode_op(int cmd, int disk_num, int block_num);

/* Return 1 on success and -1 on failure */
int mdadm_mount(void);

/* Return 1 on success and -1 on failure */
int mdadm_unmount(void);

/* Return the number of bytes read on success, -1 on failure. */
int mdadm_read(uint32_t addr, uint32_t len, uint8_t *buf);

#endif
