/*
 * testSocketClient.c
 *
 *  Created on: 2012-8-16
 *      Author: �q���c�P
 */
#include <WINSOCK.H> 
#include <stdio.h>   
#include <iostream>

 //�w�q�{�����ϥΪ��`�q    
#define SERVER_ADDRESS "140.116.177.150" //���A����IP�a�}    
#define PORT           10087         //���A������    
#define MSGSIZE        1024         //���o�w�İϪ��j�p    
#pragma comment(lib, "ws2_32.lib")    

using namespace std;
int main()
{
	WSADATA wsaData;
	//�s�u�ҥήM�`�r    
	SOCKET sClient;
	//�x�s���ݦ��A�����a�}��T    
	SOCKADDR_IN server;
	//���o�w�İ�    
	char szMessage[MSGSIZE];
	//���\�����줸�ժ��Ӽ�    
	int ret;
	// Initialize Windows socket library    
	WSAStartup(0x0202, &wsaData);
	// �إ߫Ȥ�ݮM�`�r    
	sClient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //AF_INET�����ϥ�TCP/IP��ĳ�ڡF    
														 //SOCK_STREAM, IPPROTO_TCP��������ϥ�TCP��ĳ    
	// �������ݦ��A�����a�}��T(�𸹡BIP�a�}��)    
	memset(&server, 0, sizeof(SOCKADDR_IN)); //���N�x�s�a�}��server�m����0    
	server.sin_family = PF_INET; //�ŧi�a�}�榡�OTCP/IP�a�}�榡    
	server.sin_port = htons(PORT); //�����s�u���A�����𸹡Ahtons()�Ω� converts values between the host and network byte order    
	server.sin_addr.s_addr = inet_addr(SERVER_ADDRESS); //�����s�u���A����IP�a�}    
														//���cSOCKADDR_IN��sin_addr���Ω��x�sIP�a�}�Asin_addr���]�O�@�ӵ��c��Asin_addr.s_addr�Ω�̲��x�sIP�a�}    
														//inet_addr()�Ω�N �Φp��"127.0.0.1"�r���ഫ��IP�a�}�榡    
	//�s���~���������A���W    
	connect(sClient, (struct sockaddr *) &server, sizeof(SOCKADDR_IN)); //�s�u��i�H��sClient�Өϥγo�ӳs�u    
																		//server�x�s�F���ݦ��A�����a�}��T    
	while (TRUE) {
		printf("Send:");
		//�q��L��J    
		//gets(szMessage); //The gets() functionreads characters from stdin and loads them into szMessage  
		cin >> szMessage;
		// �ǰe���    
		send(sClient, szMessage, strlen(szMessage), 0); //sClient�����έ��ӳs�u�ǰe�F szMessage�����ݵo�e��ƪ��x�s�a�} �Fstrlen(szMessage)������ƪ���    
	}
	// ����s�u�M�i�浲���u�@    
	closesocket(sClient);
	WSACleanup();
	return 0;
}