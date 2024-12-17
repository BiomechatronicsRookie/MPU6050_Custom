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

void IMU_Init(MPU6050_t* dev, MPU6050_t_cfg config);

uint8_t ReadAccX(MPU6050_t* dev, int16_t* buff);

uint8_t ReadAccY(MPU6050_t* dev, int16_t* buff);

uint8_t ReadAccZ(MPU6050_t* dev, int16_t* buff);

uint8_t ReadGyrX(MPU6050_t* dev, int16_t* buff);

uint8_t ReadGyrY(MPU6050_t* dev, int16_t* buff);

uint8_t ReadGyrZ(MPU6050_t* dev, int16_t* buff);

uint8_t ReadAllSimple(MPU6050_t* dev, int16_t* buff, size_t buffSize);

uint8_t ReadAll(MPU6050_t* dev, int16_t buff[], size_t buffLen);

int ClearInterrupt(MPU6050_t* dev);

#endif
