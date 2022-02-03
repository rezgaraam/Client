//
//  Client.cpp
//  Client
//
//  Created by Rezgar Valizadeh on 01/02/2022.
//
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "Error.h"
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>
#include <chrono>
#include <errno.h>
#include "Client.h"
Client::Client(const char  * adresseServeur, const short portserveur){
    int familleAdresses = AF_INET;// IPv4
    int typeSocket = SOCK_STREAM;// mode connecté TCP
    int protocole = IPPROTO_TCP;//
    sock = socket(familleAdresses, typeSocket, protocole);
    if (sock == INVALID_SOCKET) {
        ostringstream oss;
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        //oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;    // pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
        throw Error(oss.str().c_str());
    }
    cout<<"socket cree\n";
    sockaddr_in sockaddress;
    //sockaddress.
    sockaddress.sin_family = AF_INET;
    sockaddress.sin_addr.s_addr= inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
    sockaddress.sin_port= htons(portserveur);

    int test= connect(sock, (sockaddr *) &sockaddress, sizeof(sockaddress));
    //connect(int socket, const struct sockaddr *address, socklen_t address_len);
    if (test < 0){
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        throw Error("La connexion a échoué");
    }
    cout<<"dans constructeur"<<"r =>"<<test<<" socket =>"<< sock<<endl;

}
/*Client::Client(string addresse ,short portserveur) {
    int familleAdresses = AF_INET;// IPv4
    int typeSocket = SOCK_STREAM;// mode connecté TCP
    int protocole = IPPROTO_TCP;//
    sock = socket(familleAdresses, typeSocket, protocole);
    if (sock == INVALID_SOCKET) {
        ostringstream oss;
        fprintf(stderr, "socket() failed: %s\n", strerror(errno));
        //oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;    // pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
        throw Error(oss.str().c_str());
    }
    cout<<"socket cree\n";
    //string addrese à char [L] =>adresseServeur
    for (int i = 0; i < addresse.length(); i++) {
        adresseServeur[i] = addresse[i];
        i++;
    }

    portServeur = portserveur;
    sockaddress.sin_family = AF_INET;
    sockaddress.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
    sockaddress.sin_port = htons(portServeur);
    int test= connect(sock, (sockaddr *) &sockaddress, sizeof(sockaddress));
    if (test < 0){
        throw Error("La connexion a échoué");
    }
}*/
void Client::sendmsg(string buffer, int *t)
{

    buffer +="\r\n";
    int l=buffer.length();
    *t=l;
    int x=send(sock, buffer.c_str(),l , 0);
    if (x < 0) {
        throw Error("Send failed (send())");
    }
    cout<<"message est envoyer\n";
    //shutdown(sock,SHUT_WR);
}


void Client::recvmsg(int *bufferLen)
{
    char tab[*bufferLen];
    cout<<"debut methode rrecive\n";
    int x=recv(sock, tab, *bufferLen, 0);
    if (x < 0) {
        throw Error("Received failed (recv())");
    }
    cout<<" message recu =>"<<tab<<endl;
}

Client::~Client()
{
    int r = close(sock);  // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
    if (r)
        throw Error("La fermeture du socket a échoué");
    cout << "arrêt normal du client" << endl;
}
/*


        int familleAdresses = AF_INET;// IPv4
        int typeSocket = SOCK_STREAM;// mode connecté TCP
        int protocole = IPPROTO_TCP;// protocole. On peut aussi mettre 0 et la fct choisit le protocole en fct des 2 1ers paramètres
        /// pour les valeurs des paramètres : cf. fct socket dans la doc sur winsock
        SOCKET sock = socket(familleAdresses, typeSocket, protocole);
        ///error si la création du socket a échoué
        if (sock == INVALID_SOCKET) {
            ostringstream oss;
            fprintf(stderr, "socket() failed: %s\n", strerror(errno));
            //oss << "la création du socket a échoué : code d'erreur = " << WSAGetLastError() << endl;    // pour les valeurs renvoyées par WSAGetLastError() : cf. doc réf winsock
            throw Error(oss.str().c_str());
        }
        cout << "socket créé" << endl;

        char adresseServeur[L];
        short portServeur;

        cout << "tapez l'adresse IP du serveur de majuscule : " << endl;
        cin >> adresseServeur;
        cout << "tapez le port du serveur du serveur de majuscule : " << endl;
        cin >> portServeur;

        sockaddr_in sockaddress; // informations concernant le serveur avec lequel on va communiquer

        sockaddress.sin_family = AF_INET;
        sockaddress.sin_addr.s_addr = inet_addr(adresseServeur);   // inet_addr() convertit de l'ASCII en entier
        sockaddress.sin_port = htons(portServeur);                 //htons() assure que le port est bien inscrit dans le format du réseau (little-endian ou big-endian)

        //-------------- connexion du client au serveur ---------------------------------------

        r = connect(sock, (sockaddr *) &sockaddress, sizeof(sockaddress));
        if (r < 0)
            throw Error("La connexion a échoué");

        cout << "connexion au serveur de majuscule réussie" << endl;

        bool continuer;
        do {
            char requete[L];
            cout << "Tapez la chaîne à mettre en majuscule ou tapez \"quitter\" : ";
            cin >> requete;
            continuer = strcmp(requete, "quitter") != 0;
            if (continuer) {
                strcat(requete, "\r\n");     // pour que le serveur réceptionne bien le message
                int l = strlen(requete);

                r = send(sock, requete, l,0);             //------------------ envoi de la requête au serveur -------------------------------
                if (r < 0)
                    throw Error("échec de l'envoi de la requête");

                char reponse[L];
                r = recv(sock, reponse, l,0);             //----------- réception de la réponse du serveur -----------------------------
                // reçoit au plus l octets
                // en cas de succès, r contient le nombre d'octets reçus
                if (r < 0)
                    throw Error("La réception de la réponse a échoué");

                char *p = strchr(reponse, '\n');
                *p = '\0';
                cout << reponse << endl;
            }
        } while (continuer);

        r = close(sock);                          // renvoie une valeur non nulle en cas d'échec. Le code d'erreur peut être obtenu par un appel à WSAGetLastError()
        if (r) throw Error("La fermeture du socket a échoué");
        cout << "arrêt normal du client" << endl;
    }
    catch(Error erreur)
    {
        cerr << erreur << endl;
    }
    */