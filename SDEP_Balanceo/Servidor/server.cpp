#include "Respuesta.h"
#include "SocketDatagrama.h"
#include "celulares.h"
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

const int ALPHABET_SIZE = 26; 
  
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
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
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
        int index = key[i] - 'a'; 
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
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
}

int main(int argc, char* argv[]){
    if(argc != 3){
        cout<<"Forma de usa: nombre_programa nombre_archivo puerto"<<endl;
        exit(0);
    }

    struct TrieNode *root = getNode();
    int destino;
    //Abre un archivo para escritura, si no existe lo crea, si existe lo trunca, con permisos rw-
    if((destino = open(argv[1], O_WRONLY|O_TRUNC|O_CREAT, 0666)) == -1){
        perror(argv[1]);
        exit(-1);
    }
    
    Respuesta resp(atoi(argv[2]));
    cout << "Servidor iniciado....\n";

    while (true) {
        struct mensaje *msj = resp.getRequest();
        //struct registro reg;
        struct celulares re;
        if(msj != NULL){
            //char msjRecib[1024];
            //memcpy(msjRecib,&msj->arguments,34);
            //memcpy(&reg,&msj->arguments,sizeof(registro));
	        memcpy(&re,&msj->arguments,sizeof(struct celulares));
            timeval actual;
            
            actual.tv_sec = 0;
            actual.tv_usec = 0;

            //Ejercicio 2
	        /*if(!binary_search(celulares.begin(), 		celulares.end(),atoi(re.celular))){
	        celulares.push_back(atoi(re.celular));
            sort(celulares.begin(), celulares.end());
    	    gettimeofday(&actual,NULL); //Ejericio1
            //cout <<"Server.cpp:"<< actual.tv_sec <<" : "<< actual.tv_usec<< endl;
            string regs = re.toString();
            regs +="^@"+to_string(actual.tv_sec)+"^@"+ to_string(actual.tv_usec);
            //write(destino,msjRecib, 34);
	        write(destino,regs.c_str(), regs.length());
            write(destino,"\n", 1);
	        resp.sendReply((char *)&actual);*/
            if(!search(root, string(re.celular)))
            {
                gettimeofday(&actual,NULL);
                //cout <<"Server.cpp:"<< actual.tv_sec <<" : "<< actual.tv_usec<< endl;
                string regs = re.toString();
                //regs = string(re.celular) + string(re.CURP) + string(re.partido);
                regs += to_string(actual.tv_sec)+"@"+ to_string(actual.tv_usec);
                //write(destino,reg., 34);
	            write(destino,regs.c_str(), regs.length());
                write(destino,"\n", 1);
	            resp.sendReply((char *)&actual);
            }
        }else{//si es duplicado
            timeval actual;
            actual.tv_sec = 0;
            actual.tv_usec = 0;
		    cout << "Telefono ya registrado" << endl;
            resp.sendReply((char *)&actual);
        }
    }
    close(destino);
}