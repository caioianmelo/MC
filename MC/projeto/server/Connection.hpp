#ifndef __CONNECTION_HPP
#define __CONNECTION_HPP

#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <fstream>
#include <string>
#include <vector>
#include <chrono>

#define MAX_CONN 4
#define TIMEOUT 2
#define MSG_BUFFER_SIZE 1024

using namespace std;

class Connection {
	private:
		int s_socket, c_socket, cicle;
		uint16_t s_port;
		float limit;
		vector<float> batt_lvls;
		chrono::time_point<chrono::steady_clock> start_clock;
		chrono::time_point<chrono::steady_clock> stop_clock;
	public:
		Connection();
		~Connection();
		int getS_socket();
		void setS_socket(int socketid);
		int getCicle();
		void setCicle(int cicle);
		float getLimit();
		void setLimit(float limit);
		uint16_t getSPort();
		void setSPort(uint16_t s_port);
		int getCli_socket();
		void setCli_socket(int c_socket);
		void handleComm(int s_cli_id);
		void convertMsg(char *msg);
		void handleBattery();
		void openConnection();
};

#endif
