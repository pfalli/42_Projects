#pragma once
#include <iostream>
#include <cstring>
#include "Server.hpp"

typedef enum	s_format
{
	NICKNAME,
	USERNAME,
	PASSWORD,
	REALNAME,
	PORT

}				t_format;

bool			validFormat(int format, std::string str);
// bool			userNameTaken(std::vector<Client> clients, std::string username);
// bool			nickNameTaken(std::vector<Client> clients, std::string nickname);
std::string		removeNewline(char *buff);
bool			verfifyPassword(std::string password, int clientSocket);
std::string		requestName(int format, int clientSocket, std::vector<Client> &clients);
std::string		timeToString(time_t t);
size_t			stringToSizeT(std::string &str);
std::string		convertSizeTtoString(size_t number);

/* mode */
void	mode(Server *server, const Command &cmd, Client *client);

/* join */
void	join(Server *server, Client *joiningClient, const Command &cmd);
//Channel*		isChannelExist(std::vector<Channel>&	channels, std::string channelTojoin);


/* privmsg */
void	privmsg(Server *server, Client *sender, const Command &cmd);
void	signal_handler(int signal);
void	parseChannelName2(std::string &targetChannel);
// void	sendToChannel(Channel &channel, const std::string &message); older version
void sendToChannel(Channel &channel, const std::string &message, int senderSocket);


/* topic */
void topic(Server *server, const Command &cmd, Client *client);

template <typename T> typename std::vector<T>::iterator		findObject(int toFind, std::vector<T> &array);

bool isOperator(Channel &channel, Client *client);

std::string userNameCommandFormat(std::string params, int mode);
std::string removeSpace(std::string input);

void sendMsg(Client *client, const std::string &message);