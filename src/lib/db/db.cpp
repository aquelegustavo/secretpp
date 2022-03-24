#include "db.h"
#include <iostream>
#include <string>
#include <fstream>

#include "../json/json.hpp"

using namespace std;
using json = nlohmann::json;

string getRandomId(int len)
{
    /*
    Obeter Id aleatório
    Params:
        (int) len: Tamanho do id requerido
    Returns:
        (string): Id gerado aleatóriamente
    */
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    string id;
    id.reserve(len);

    for (int i = 0; i < len; ++i)
    {
        id += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return id;
}

DB ::DB(string databaseFileName, string collectionId)
{
    _databaseFileName = databaseFileName;
    _collectionId = collectionId;
}

json DB::getDocument(string documentId)
{

    ifstream fileDataInput(_databaseFileName);

    json jsonInput;

    if (fileDataInput.is_open())
    {
        fileDataInput >> jsonInput;
    }

    json document = jsonInput[_collectionId][documentId];

    if (document == nullptr)
    {
        throw string("Documento não encontrado");
    }

    fileDataInput.close();

    return document;
};

json DB::findDocument(string key, string value)
{

    ifstream fileDataInput(_databaseFileName);

    json jsonInput;

    if (fileDataInput.is_open())
    {
        fileDataInput >> jsonInput;
    }

    json collection = jsonInput[_collectionId];

    json search = json::array();

    for (auto doc = collection.begin(); doc != collection.end(); ++doc)
    {
        string docId = doc.key();
        json docData = doc.value();

        json field = doc.value()[key];

        if (field == nullptr)
        {
            throw string("Campo não encontrado");
        }

        string fieldValue = doc.value()[key]["value"];

        size_t found = fieldValue.find(value);
        if (found != string::npos)
        {
            search.push_back(docData);
        }
    }

    return search;
};

string DB::setDocument(json documentData, string documentId)
{

    ifstream fileDataInput(_databaseFileName);

    json jsonInput;

    if (fileDataInput.is_open())
    {
        fileDataInput >> jsonInput;
    }

    jsonInput[_collectionId][documentId] = documentData;

    ofstream fileDataOutput(_databaseFileName, ios::trunc);

    fileDataOutput << setw(4) << jsonInput;

    fileDataInput.close();
    fileDataOutput.close();

    return documentId;
};

void DB::removeDocument(string documentId)
{
    ifstream fileDataInput(_databaseFileName);

    json jsonInput;

    if (fileDataInput.is_open())
    {
        fileDataInput >> jsonInput;
    }

    jsonInput[_collectionId].erase(documentId);

    json document = jsonInput[_collectionId][documentId];

    if (document == nullptr)
    {
        throw string("Documento não encontrado");
    }

    ofstream fileDataOutput(_databaseFileName, ios::trunc);

    fileDataOutput << setw(4) << jsonInput;

    fileDataInput.close();
    fileDataOutput.close();
};