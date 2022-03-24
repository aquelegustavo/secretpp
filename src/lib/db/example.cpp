#include "db.h"
#include <iostream>
#include <string>

#include "../json/json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
    srand((unsigned)time(NULL));

    DB db("data.json", "users");

    json docData = {
        {"name", "Gustavo"},
        {"course", "Engenharia de Computação"},
        {"university", "UFSC"}};

    // Adicionar documento
    string docId = db.setDocument(docData);

    // json doc = db.getDocument("4iaD60teczwoa2p0");

    cout << "Documento " << docId;

    return 0;
}
