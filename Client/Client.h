//
//  Client.h
//  Client
//
//  Created by Rezgar Valizadeh on 01/02/2022.
//

#ifndef Client_h
#define Client_h

#define  L 200
using namespace std;
class Client
{
private:
    ///creation de socket
    SOCKET sock;
    //int familleAdresses = AF_INET;// IPv4
    //int typeSocket = SOCK_STREAM;// mode connecté TCP
    //int protocole = IPPROTO_TCP;// protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
    char adresseServeur[L];
    short portServeur;
    sockaddr_in sockaddress; // informations concernant le serveur avec lequel on va communiquer
public:

    //Client(string addresse ,short portserveur);
    Client(const char  * addresse, const short portserveur);
    void sendmsg(string buffer, int *bufferLen);
    void recvmsg(int *bufferLen);
    ~Client();

};
void client();

#endif /* Client_h */
