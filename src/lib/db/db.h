#ifndef DB_H
#define DB_H

#include <string>

#include "../json/json.hpp"

using namespace std;
using json = nlohmann::json;

string getRandomId(int len);

class DB
{
private:
    string _databaseFileName;
    string _collectionId;

public:
    DB(string databaseFileName, string collectionId);

    json getDocument(string documentId);

    json findDocument(string key, string value);

    string setDocument(json documentData, string documentId = getRandomId(16));

    void removeDocument(string documentId);
};

#endif // DB_H
