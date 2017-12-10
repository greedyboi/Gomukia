#include "stdafx.h"
#include "Handler.h"

// Send the brain answer 
int Handler::response(char *fmt, ...)
{
	int i;
	va_list va;

	va_start(va, fmt);
	i = vprintf(fmt, va);
	putchar('\n');
	fflush(stdout);
	va_end(va);
	return i;
}

// Get command
std::string Handler::get_cmd()
{
	std::string cmd;

	std::getline(std::cin, cmd);
	return (cmd);
}

std::string Handler::get_params(std::string& command, std::string& cmd)
{
	if (command.size() < cmd.size() || command.compare(0, cmd.size(), cmd))
		return std::string("bad");
	
	command.erase(0, 0 + cmd.size());
	if (command[0] == ' ')
		command.erase(0, 1);
	return command;
}

// Handler main functions
void Handler::handle()
{
	std::string cmd;

	DWORD mode;

	if (GetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), &mode))
		puts("MESSAGE Gomoku AI should not be started directly. Please install gomoku manager (http://sourceforge.net/projects/piskvork). Then enter path to this exe file in players settings.");

	while (1)
	{
		cmd = get_cmd();

		if (get_params(cmd, std::string("BEGIN")).compare("bad") != 0)
			begin(cmd);
		else if (get_params(cmd, std::string("END")).compare("bad") != 0)
			end(cmd);
		else if (get_params(cmd, std::string("ABOUT")).compare("bad") != 0)
			about(cmd);
		else if (get_params(cmd, std::string("START")).compare("bad") != 0)
			start(cmd);
		else if (get_params(cmd, std::string("TURN")).compare("bad") != 0)
			turn(cmd);
		else if (get_params(cmd, std::string("INFO")).compare("bad") != 0)
			info(cmd);
		else if (get_params(cmd, std::string("BOARD")).compare("bad") != 0)
			board(cmd);
		else
			response("UNKNOWN command");
	}


}

// Set the board map
void Handler::board(std::string params)
{
	std::string cmd;
	int x, y, who;

	while (1)
	{
		getline(std::cin, cmd);
		if (cmd.compare("DONE") == 0)
		{
			//turn(std::string);
		}
		if (sscanf_s(params.c_str(), "%d,%d,%d", &x, &y, &who) 
			|| x < 0 || y < 0 || x >= size || y >= size)
		{
			response("ERROR x,y,who or DONE expected");
			break;
		}
		bd[x][y] = who;
	}
}

// Initialize the board
void Handler::start(std::string params)
{
	size = std::atoi(params.c_str());
	bd.resize(std::atoi(params.c_str()));
	for (auto i : bd)
		i.resize(std::atoi(params.c_str()));
}


// AI's move
void Handler::begin(std::string params)
{
	bd.clear();
	start(std::string("20"));
	turn(std::string("10,10"));
}


// AI opponent's move
void Handler::turn(std::string params)
{
	int x, y;

	if (sscanf_s(params.c_str(), "%d,%d", &x, &y) != 2 || x > 100 || y > 100
		|| x < 0 || y < 0)
		response("ERROR Bad coordinates");
}


// Get info
void Handler::info(std::string params)
{
	if (get_params(params, std::string("max_memory")).compare("bad") != 0) 
		max_memory = std::atoi(params.c_str());
	if (get_params(params, std::string("timeout_turn")).compare("bad") != 0)
		timeout_turn = std::atoi(params.c_str());
	if (get_params(params, std::string("timeout_match")).compare("bad") != 0)
		timeout_match = std::atoi(params.c_str());
	if (get_params(params, std::string("time_left")).compare("bad") != 0)
		time_left = std::atoi(params.c_str());
	if (get_params(params, std::string("game_type")).compare("bad") != 0)
		game_type = std::atoi(params.c_str());
	if (get_params(params, std::string("rule")).compare("bad") != 0)
	{
		rule = std::atoi(params.c_str()); 
		exact5 = rule & 1; 
		continuous = (rule >> 1) & 1; 
		renju = (rule >> 2) & 1;
	}
}


// Terminate AI
void Handler::end(std::string params)
{
	exit(0);
}


// Get AI info
void Handler::about(std::string params)
{
	response("name=\"Gomukia\", version=\"1.0\", author=\"Ambroise Damier, \
Karim Dalaize\", country=\"FRANCE\"");
}
