#include "Fls.h"
#include <stdio.h>
#include <string.h>

Std_ReturnType Fls_Write(uint32 TargetAddress, const uint8* SourceAddressPtr, uint32 Length) {
    if (SourceAddressPtr == NULL || Length == 0) {
        return E_NOT_OK;
    }

<<<<<<< HEAD
=======
    // /* Giả lập thao tác ghi vào bộ nhớ Flash */
    // hardware_flash_write(TargetAddress, SourceAddressPtr, Length);

>>>>>>> 35d9d72ea7bb2baa89328b7c3cbfc919465d6b2e
    return E_OK;
}

Std_ReturnType Fls_Read(uint32 TargetAddress, uint8* DestinationPtr, uint32 Length) {
    if (DestinationPtr == NULL || Length == 0) {
        return E_NOT_OK;
    }
<<<<<<< HEAD
    
    return E_OK;
}



// void writeErrorCodeToLog(int errorCode, const char *errorDescription) {
//     FILE *file = fopen("log.txt", "r");
//     if (file == NULL) {
//         printf("Unable to open log file for reading.\n");
//         return;
//     }

//     char buffer[256];
//     int exists = 0;
//     while (fgets(buffer, sizeof(buffer), file)) {
//         int code;
//         sscanf(buffer, "ErrorCode: %d", &code);
//         if (code == errorCode) {
//             exists = 1; 
//             break;
//         }
//     }
//     fclose(file); 

//     if (exists) {
//         printf("ErrorCode %d already exists in log. Skipping write.\n", errorCode);
//         return;
//     }

//     file = fopen("log.txt", "w"); 
//     if (file == NULL) {
//         printf("Unable to open log file for writing.\n");
//         return;
//     }

//     fprintf(file, "ErrorCode: %d %s\n", errorCode, errorDescription);
//     fclose(file); 
// }


// int readErrorCodesFromLog() {
//     FILE *file = fopen("log.txt", "r"); 
//     if (file == NULL) {
//         printf("Unable to open log file for reading.\n");
//         return 0; 
//     }

//     int errorCount = 0;
//     char buffer[256];
    
//     while (fgets(buffer, sizeof(buffer), file)) {
//         errorCount++;
//     }

//     fclose(file); 
//     return errorCount; 
// }
=======
    int errorCount = readErrorCodesFromLog();
    printf("Number of errors recorded: %d\n", errorCount);
    return E_OK;
}
void writeErrorCodeToLog(int errorCode, const char *errorDescription) {
    FILE *file = fopen("log.txt", "r");
    if (file == NULL) {
        printf("Unable to open log file for reading.\n");
        return;
    }

    char buffer[256];
    int exists = 0;
    while (fgets(buffer, sizeof(buffer), file)) {
        int code;
        sscanf(buffer, "ErrorCode: %d", &code);
        if (code == errorCode) {
            exists = 1; 
            break;
        }
    }
    fclose(file); 

    if (exists) {
        printf("ErrorCode %d already exists in log. Skipping write.\n", errorCode);
        return;
    }

    file = fopen("log.txt", "w"); 
    if (file == NULL) {
        printf("Unable to open log file for writing.\n");
        return;
    }

    fprintf(file, "ErrorCode: %d %s\n", errorCode, errorDescription);
    fclose(file); 
}


int readErrorCodesFromLog() {
    FILE *file = fopen("log.txt", "r"); 
    if (file == NULL) {
        printf("Unable to open log file for reading.\n");
        return 0; 
    }

    int errorCount = 0;
    char buffer[256];
    
    while (fgets(buffer, sizeof(buffer), file)) {
        errorCount++;
    }

    fclose(file); 
    return errorCount; 
}
>>>>>>> 35d9d72ea7bb2baa89328b7c3cbfc919465d6b2e
