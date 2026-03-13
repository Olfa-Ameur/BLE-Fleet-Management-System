#ifndef INC_GPS_FUNCTIONS_H_
#define INC_GPS_FUNCTIONS_H_

#include "main.h"
#include <string.h>




#define PWR_KEY_PIN     GPIO_PIN_1
#define PWR_KEY_PORT    GPIOB
#define STATUS_PIN      GPIO_PIN_0
#define STATUS_PORT     GPIOB

#define GNSS_EN_PIN GPIO_PIN_2
#define GNSS_EN_PORT GPIOB
#define POWER_ON_TIMEOUT_MS  5000
#define UART_TIMEOUT_MS      1000

#define PMTK_SET_NMEA_OUTPUT  "$PMTK314,0,1,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0*2C\r\n"
#define PMTK_SET_FIX_CTL      "$PMTK300,1000,0,0,0,0*1C\r\n"
#define PMTK_SET_POS_FIX      "$PMTK220,1000*1F\r\n"

void Check_Status_Pin(void);
void SIM868_PowerOn(void);
void SIM868_SendCommand(const char *cmd, uint32_t timeout);
void extractGNGGAFrame(const char *rx_buffer) ;
void GPS_init(void);
float convert_ch_to_float(const char* ch);
void ParsePosition(void);
void GET_GPS(void);




#endif
