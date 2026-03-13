#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include "main.h"
#include <string.h>

typedef enum {
    CMD_UNKNOWN = 0,
    CMD_POSITION,
    CMD_FUEL,
	CMD_ID
} CommandType;

CommandType Get_Command_Type(const char *cmd);
void Command_Parse(const char *cmd);
int is_valid_id(const char *id);

#endif
