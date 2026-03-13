#include "command_parser.h"
#include "main.h"
#include <string.h>
#include "gps_functions.h"

extern UART_HandleTypeDef huart1;
char response_buf[50];
extern char buf[60];
extern char cord_buf[50];
extern char rx_buffer[300];

const char *valid_ids[] = { "1234", "5678", "9999" };
#define NUM_IDS (sizeof(valid_ids) / sizeof(valid_ids[0]))

int is_valid_id(const char *id) {
    for (int i = 0; i < NUM_IDS; i++) {
        if (strcmp(id, valid_ids[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

CommandType Get_Command_Type(const char *cmd) {
    if (strstr(cmd, "cmd_position") != NULL)
        return CMD_POSITION;
    else if (strstr(cmd, "cmd_fuel") != NULL)
        return CMD_FUEL;
    else if (strstr(cmd, "cmd_ID:") != NULL)
           return CMD_ID;
    else
        return CMD_UNKNOWN;
}

void Command_Parse(const char *cmd) {
    switch (Get_Command_Type(cmd)) {
        case CMD_POSITION:
        	strcpy(response_buf, "Position:OK");
           //strcpy(response_buf, buf);
        	//strncpy(response_buf, buf, sizeof(response_buf) - 1);
        	//response_buf[sizeof(response_buf) - 1] = '\0';
            break;

        case CMD_FUEL:
            strcpy(response_buf, "fuel:OK");
            break;
        case CMD_ID: {
                    const char *id = strstr(cmd, "cmd_ID:") + strlen("cmd_ID:");
                    if (is_valid_id(id)) {
                        strcpy(response_buf, "ID_correct");
                        HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_SET);
                        HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_RESET);
                    } else {
                        strcpy(response_buf, "ID_incorrect");
                        HAL_GPIO_WritePin(RED_LED_GPIO_Port, RED_LED_Pin, GPIO_PIN_SET);
                        HAL_GPIO_WritePin(GREEN_LED_GPIO_Port, GREEN_LED_Pin, GPIO_PIN_RESET);
                    }
                    break;
                }
        default:
            strcpy(response_buf, "unknown");
            break;
    }

    HAL_UART_Transmit(&huart1, (uint8_t*)response_buf, strlen(response_buf), HAL_MAX_DELAY);
}



