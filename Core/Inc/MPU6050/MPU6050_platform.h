/*
 * readwrite.h
 *
 *  Created on: Oct 6, 2024
 *      Author: vicar
 */
#ifndef INC_READWRITE_H_
#define INC_READWRITE_H_

#include <stdint.h>
#include "MPU6050_errorcodes.h"
#include "i2c.h"

typedef struct device{
	I2C_HandleTypeDef* i2c_hanlde;
	uint16_t dev_address;
}MPU6050_t;


int RdByte(MPU6050_t* dev, uint16_t memAdd, uint8_t* buff);


#endif /* INC_READWRITE_H_ */


/*
 * Read/Write from addresses
 */

