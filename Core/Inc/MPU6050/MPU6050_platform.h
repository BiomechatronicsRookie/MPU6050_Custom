/*
 * Author: 		Victo Carmona Ortiz / @BiomechatronicsRookie (github)
 * Date: 		12/10/2024 (DD-MM-YYYY)
 *
 * Description: low level i2c data read functions to work with MPU6050
 */

#ifndef PLTFRM_H_
#define PLTFRM_H_

#include <stdint.h>
#include "MPU6050_errorcodes.h"
#include "i2c.h"

typedef struct device{
	I2C_HandleTypeDef* i2c_hanlde;
	uint16_t dev_address;
}MPU6050_t;

typedef struct device_cfg{
	uint8_t fifo_en;
}MPU6050_t_cfg;



uint8_t RdByte(MPU6050_t* dev, uint8_t memAdd, uint8_t* buff);

uint8_t WrtByte(MPU6050_t* dev, uint8_t memAdd, uint8_t* buff);

uint8_t RdWord(MPU6050_t* dev, uint8_t memAdd_L, int16_t* buff);

uint8_t BurstRead(MPU6050_t* dev, uint8_t memAdd_L, int16_t* buff, uint8_t buffLen, uint8_t Delay);

uint8_t FifoRead(MPU6050_t* dev, int16_t* buff, uint8_t fifoBuffLen);


#endif /* INC_READWRITE_H_ */


/*
 * Read/Write from addresses
 */

