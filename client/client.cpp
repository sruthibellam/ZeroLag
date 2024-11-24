// C++ program to illustrate the client application in the
// socket programming
#include <cstring>
#include <iostream>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
using namespace std;

int main()
{
    // creating socket
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    // specifying address
    sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = INADDR_ANY;

    cout << "Connecting to server on port 8080"
         << endl;

    // sending connection request
    while(connect(clientSocket, (struct sockaddr*)&serverAddress,
           sizeof(serverAddress)) == -1);
    cout << "Connected to server" << endl;

    // sending data
    const char* message = "Hello, server!";
    send(clientSocket, message, strlen(message), 0);
    cout << "Message sent to server: " << message
         << endl;

    // closing socket
    close(clientSocket);

    return 0;
}