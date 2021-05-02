#include "Connection.hpp"

int Connection::getS_socket() { return s_socket; }

void Connection::setS_socket(int s_socket) { this->s_socket = s_socket; }

uint16_t Connection::getSPort() { return s_port; }

void Connection::setSPort(uint16_t s_port) { this->s_port = s_port; }

int Connection::getCicle() { return cicle; }

void Connection::setCicle(int cicle) { this->cicle = cicle; }

float Connection::getLimit() { return limit; }

void Connection::setLimit(float limit) { this->limit = limit; }

int Connection::getCli_socket() { return c_socket; }

void Connection::setCli_socket(int c_socket) { this->c_socket = c_socket; }

// Opens the connection and reads from the file
Connection::Connection() { 
	int i = 0;
	string line;
	ifstream server_file("server_info");

	while( getline( server_file, line ) ) {
		try {
			switch( i ) {
				case 0:
					setSPort( stoi( line.substr(5, line.size() - 5) ) );
				break;
				case 1:
					setCicle( stoi( line.substr(5, line.size() - 5) ) );
				break;
				case 2:
					 setLimit( stof( line.substr(5, line.size() - 5) ) );
				break;
			}
		} catch( const invalid_argument &ia ) {
			cerr << "Invalid Argument: " << ia.what() << "\n";
		}

		++i;
	}

	server_file.close();

	openConnection();
}

// Opens the connection and sets the communication socket
void Connection::openConnection() {
	int s_socket, s_cli_id;
	struct sockaddr_in s_add;		//sockets used for internet communication
	struct sockaddr_storage *s_client;
	unsigned int cli_addr_length;
	chrono::duration<double> timestamp;

 	s_socket = socket(PF_INET, SOCK_STREAM, 0); // IPv4 protocol
	if( s_socket < 0 ) {
		cout << "Could not create the socket!" << "\n";
		exit(1);
	}

	s_add.sin_family = AF_INET; // Internet family socket
	s_add.sin_port = htons( getSPort() ); // converts into TCP/IP network byte order
	s_add.sin_addr.s_addr = htonl(INADDR_ANY); // converts the ip into a long
	memset( s_add.sin_zero, '\0', sizeof s_add.sin_zero );		// Fills sin_zero with \0 for socket_addr convertion
	
	if( bind( s_socket, (struct sockaddr*) &s_add, sizeof s_add) < 0 ) {
		cout << "Could not bind the s_port: " << getSPort() << "\n";
		exit(1);
	}

	if( listen(s_socket, MAX_CONN) < 0) {
		cout << "Error upon listening!";
		exit(1);
	}
	else {
		cout << "Listening!\n";
		setS_socket(s_socket);
	}
	
	// Infinity loop to accept and send messages to connected clients
	while(1) {
		cli_addr_length = sizeof s_client;

		s_cli_id = accept(s_socket, (struct sockaddr*) &s_client, &cli_addr_length); // in and out socket
		if( s_cli_id < 0 ) {
			cout << "Could not establish the connection!\n";
			exit(1);
		}
		else {
			cout << "Connected!\n";
			sleep( getCicle() );
			handleComm(s_cli_id);
		}

		stop_clock = chrono::steady_clock::now();
		timestamp = stop_clock - start_clock;
		if( timestamp.count() > TIMEOUT )
			cout << "Warning! Client isn't responding!\n";


	}
}

// Handler for the Communication
void Connection::handleComm(int s_cli_id) {
	char msg_buffer[MSG_BUFFER_SIZE];
	int recvmsg_size, c = 0;	// Size of message recovered by recv from the client
	char *pend; // pointer to the end of string
	float lvl;

	recvmsg_size = recv( s_cli_id, msg_buffer, MSG_BUFFER_SIZE, 0 );
	if(recvmsg_size < 0) {
		cout << "Error recovering the message!1\n";
		sleep(2);
	}
	else {
		// Loop for message transmission, 0 means end of transmission
		while (recvmsg_size > 0) {
			// Verifying if there's message to be delivered
			if( send( s_cli_id, msg_buffer, recvmsg_size, 0 ) != recvmsg_size ) 
				cout << "Error during the transmission!\n";

			recvmsg_size = recv( s_cli_id, msg_buffer, MSG_BUFFER_SIZE, 0 ); // Verifying if there's still message to be delivered
			if( recvmsg_size < 0 ) {
				cout << "Error recovering the message!2\n";
			}	
			
			convertMsg(msg_buffer);
			if(c == 4) {
				handleBattery();
				c = 0;
			}
			else ++c;
		}


	}

	// Closing socket
	close(s_cli_id);
	cout << "Disconnected!\n";
	start_clock = chrono::steady_clock::now();
}

void Connection::convertMsg(char *msg) {
	string str = msg;
	float lvl;
	char *pend;

	lvl = strtof( str.substr(8, str.size()-8).c_str(), &pend );
	batt_lvls.push_back(lvl); 
	cout << str << "\n";
}

void Connection::handleBattery() {
	float sum = 0;
	int i = 0;

	for(; i < 5; ++i) {
		sum += batt_lvls.back();	
		batt_lvls.pop_back();
	}

	sum /= 5;
	if( sum < getLimit() ) 
		cout << "Warning! the battery level is " << sum << "!\n";
}

Connection::~Connection(){ 
	if( close(getS_socket()) < 0) {
		cout << "Error upon trying to close the socket!\n";
		exit(-1);
	}
}
