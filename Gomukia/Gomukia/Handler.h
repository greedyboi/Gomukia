#pragma once

#include <string>
#include <iostream>
#include <cstdarg>
#include <vector>
#include <Windows.h>

class Handler
{
public:
	Handler() {
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				bd[i][j] = 0;
		}
	};
	virtual ~Handler() {};
	
	// Initialize the board
	void start(std::string);
	
	// AI First move
	void begin(std::string);
	
	// AI opponent's move
	void turn(std::string);
	
	// Get info
	void info(std::string);
	
	// Terminate AI
	void end(std::string);
	
	// Get AI info
	void about(std::string);

	// Set the board map
	void board(std::string);

	// Send the brain answer
	int response(char *, ...);

	// Handler main function
	void handle();

	// Get command
	std::string get_cmd();
	static std::string get_params(std::string&, std::string&);

	void play();
	// Getters and setters
	void time_left_set(int time) { time_left = time; };
	int	get_time_left() const { return time_left; };
	void timeout_turn_set(int time) { timeout_turn = time; };
	int get_timeout_turn() const { return timeout_turn; };
	void timeout_match_set(int time) { timeout_match = time; };
	int get_timeout_match() const { return timeout_match; };
	void max_memory_set(int mem) { max_memory = mem; };
	int get_max_memory() const { return max_memory; };
	void game_type_set(int type) { game_type = type; };
	int get_game_type() const { return game_type; };
	void rule_set(int ru) { rule = ru; };
	int get_rule() const { return rule; };
	void folder_set(std::string fol) { folder = fol; };
	std::string get_folder() const { return folder; };

private:
	int size = 100;
	int bd[100][100];
	int timeout_turn = 0;
	int timeout_match = 0;
	int max_memory = 1;
	int time_left;
	int game_type = 1;
	int rule;
	int exact5;
	int continuous;
	int renju;
	std::string folder;
};

