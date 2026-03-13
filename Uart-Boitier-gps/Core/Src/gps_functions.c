#include "main.h"
#include"gps_functions.h"
#include <string.h>
#include "stdio.h"
#include"usart.h"
#include"stdlib.h"


char cord_buf[50];
char buf[60];
char rx_buffer[300]= {0};
char parsing_buffer [50];
char status_buffer[50];
char identifiant[20] = {0};
char temps[20] = {0};
char lat[20];
char longi[20];
char long_direct[1];
char lat_direct[1];
char vitesse[10];
char lat_direction[2] = {'N', 'S'};
char longi_direction[2] = {'E', 'W'};
float val_lat;
float val_longi;


/*char buf[50];
char rx_buffer[300]= {0};
char parsing_buffer [30];
char status_buffer[50];
char identifiant[20] = {0};
char temps[20] = {0};*/

extern volatile uint8_t rx_complete;

void Check_Status_Pin(void) {
    GPIO_PinState status = HAL_GPIO_ReadPin(STATUS_PORT, STATUS_PIN);

    if(status == GPIO_PIN_SET) {
        snprintf(status_buffer, sizeof(status_buffer), " Module ACTIF (HIGH)\r\n");
    } else {
        snprintf(status_buffer, sizeof(status_buffer), " Module INACTIF (LOW)\r\n");
    }


}



void SIM868_PowerOn(void) {

    HAL_GPIO_WritePin(PWR_KEY_PORT, PWR_KEY_PIN, GPIO_PIN_RESET);
    HAL_Delay(1500);
    HAL_GPIO_WritePin(PWR_KEY_PORT, PWR_KEY_PIN, GPIO_PIN_SET);


    HAL_Delay(3000);

    HAL_GPIO_WritePin(STATUS_PORT, STATUS_PIN, GPIO_PIN_SET);
        Check_Status_Pin();
    }



  void SIM868_SendCommand(const char *cmd, uint32_t timeout) {

      HAL_UART_Transmit(&huart2, (uint8_t*)cmd, strlen(cmd), timeout);



}


  void GPS_init(void){

   	        HAL_GPIO_WritePin(GNSS_EN_PORT, GNSS_EN_PIN, GPIO_PIN_SET);
   	        SIM868_SendCommand(PMTK_SET_FIX_CTL , UART_TIMEOUT_MS);
   	        SIM868_SendCommand(PMTK_SET_POS_FIX , UART_TIMEOUT_MS);
   	        SIM868_SendCommand(PMTK_SET_NMEA_OUTPUT , UART_TIMEOUT_MS);


   	         }


  float convert_ch_to_float(const char* ch) {

       double value = strtod(ch, NULL);
       int degrees = (int)(value / 100);//On divise par 100 pour isoler les degrés (les 2 premiers chiffres)
       double minutes = value - (degrees * 100);// On soustrait la partie degrés pour obtenir les minutes
       float val = degrees + (minutes / 60.0f);//Les minutes sont converties en dégrés en divisant par 60
       if (lat_direction[0] == 'S') {
       val = -1.0*val;

       }
       if (longi_direction[0] == 'W') {
       val= -1.0*val;
       }

       return val;

   }



  void ParsePosition(void) {

        char* token = strtok(buf, ",");
        int champ = 0;
        while (token != NULL) {
               champ++;

               if  (champ == 1) {
                   strcpy(identifiant, token);

               } else if (champ == 2) {
                   strcpy(temps, token);
               }
               else if (champ == 3){
             	  strcpy(lat,token);
               }
               else if (champ == 4){
             	  strcpy(lat_direct,token);
               }
               else if (champ == 5){
             	  strcpy(longi,token);
               }
               else if (champ == 6){
             	  strcpy(long_direct,token);

               }

               token = strtok(NULL, ",");
           }


   }

  void extractGNGGAFrame(const char *rx_buffer) {
  	 char *start = strstr(rx_buffer, "$GNGGA");
  	    if (start) {
  	        strncpy(buf, start, 60);
  	        buf[49] = '\0';
  	    }
  	}


   void GET_GPS(void)
   {
  	  rx_complete = 0;
  		      HAL_UART_Receive_IT(&huart2, (uint8_t*)rx_buffer, sizeof(rx_buffer));


  		      HAL_Delay(5000);

  		      if (rx_complete) {
  		          extractGNGGAFrame(rx_buffer);
  		          ParsePosition();
  		          snprintf(cord_buf, sizeof(cord_buf), "%s,%s", lat, longi);
  		          val_lat = convert_ch_to_float(lat);
  		          val_longi = convert_ch_to_float(longi);
  		      }
   }








