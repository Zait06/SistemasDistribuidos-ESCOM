#include "Respuesta.h"
#include "Solicitud.h"
#include "registro.h"
#include <cstring>
#include <iostream>
#include <ctime>
#include <fstream>//archivo
#include <fcntl.h>//open
#include <unistd.h>
#include <sys/time.h>
#include <bits/stdc++.h> 

using namespace std;
//Para cada registro recibido, el servidor deberá irlos guardando en un archivo, el cual será nuestra base
//de datos.

const int ALPHABET_SIZE = 10;
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
    // isEndOfWord is true if the node represents 
    // end of a word 
    bool isEndOfWord; 
}; 
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < 9; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
}
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - '0';
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
}  
// Returns true if key presents in trie, else 
// false 
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - '0';
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
}

int main(int argc, char* argv[])
{
    if(argc != 5){
        cout<<"Forma de usa: nombre_programa nombre_archivo puerto ipTimestamp puertoTimestamp"<<endl;
        exit(0);
    }

    struct TrieNode *root = getNode();
    int destino;
    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
        perror(argv[1]);
        exit(-1);
    }
    //int puerto = atoi(argv[2]);
    Respuesta resp(atoi(argv[2]));
    Solicitud s;
    cout << "Servidor iniciado....\n";

    while(true){
        struct mensaje *msj = resp.getRequest();
        struct registro re;
        if(msj != NULL){
	        memcpy(&re,&msj->arguments,sizeof(struct registro));
            timeval actual;
            
            actual.tv_sec = 0;
            actual.tv_usec = 0;
            
            if(!search(root, string(re.celular)))
            {
                insert(root, string(re.celular));
                //Mandamos la solicitud al servidor timestamp
                cout << "Enviando petición timestamp:"<< endl;
                 memcpy(&actual, s.doOperation(argv[3], atoi(argv[4]), 1, (char *)&actual), sizeof(timeval));
                cout << "Timestamp recibido:"<< actual.tv_sec <<" : "<< actual.tv_usec<< endl;
                string regs = re.toString();
                regs += to_string(actual.tv_sec)+"@"+ to_string(actual.tv_usec);
	            write(destino,regs.c_str(), regs.length());
                write(destino,"\n", 1);
	            resp.sendReply((char *)&actual);
            }
            else{//si es duplicado
                timeval actual;
                actual.tv_sec = 0;
                actual.tv_usec = 0;
    		    cout << "Telefono ya registrado" << endl;
                resp.sendReply((char *)&actual);
            }
        }
    }
    close(destino);
}