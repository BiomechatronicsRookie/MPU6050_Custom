/*
 * 	MPU6050_api.h
 *
 *  Created on: Nov 14, 2024
 *      Author: Victor
 *     API functions for the MPU6050
 */

#ifndef INC_API_H_
#define INC_API_H_

#include <stdint.h>
#include <MPU6050_platform.h>

void IMU_Init(MPU6050_t* dev);

int ReadAccX(MPU6050_t* dev, int16_t* buff);

int ReadAccY(MPU6050_t* dev, int16_t* buff);

int ReadAccZ(MPU6050_t* dev, int16_t* buff);

int ReadGyrX(MPU6050_t* dev, int16_t* buff);

int ReadGyrY(MPU6050_t* dev, int16_t* buff);

int ReadGyrZ(MPU6050_t* dev, int16_t* buff);

int ReadAll(MPU6050_t* dev, int16_t *buff, size_t buffSize);

int ClearInterrupt(MPU6050_t* dev);

#endif
