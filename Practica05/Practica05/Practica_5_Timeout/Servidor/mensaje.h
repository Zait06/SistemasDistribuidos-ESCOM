//#define TAM_MAX_DATA 4000
#define TAM_MAX_DATA 50 //Modificación del valor TAM_MAX_DATA
//Definicion de identificadores para operaciones permitidas
#define suma 1
// Definicion del formato de mensaje
struct mensaje{
    int messageType;                //0= Solicitud, 1 = Respuesta
    unsigned int requestId;         //Identificador del mensaje
    int operationId;                //Identificador de la operación
    char arguments[TAM_MAX_DATA];
};
