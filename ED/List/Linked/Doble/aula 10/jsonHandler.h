//
// Created by gusta on 23/11/2025.
//

#ifndef ED_JSONHANDLER_H
#define ED_JSONHANDLER_H

#include "dobleLinkedList.h"

#define FILE_ERROR -1

int writeArrayToJSON(const char* filename, const List_DL* list);

int readArrayFromJSON(const char* filename, List_DL* list);

#endif //ED_JSONHANDLER_H