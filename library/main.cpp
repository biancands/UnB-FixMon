
#include <iostream>

#include "domains.h"
#include "entities.h"
#include "tests.h"

using namespace std;

int main(){

    TUData testeA;
    TUPercentual testeB;

    switch(testeA.run()){
        case TUData::SUCESSO: cout << "\nSUCESSO - DATA" << endl ;
                                break;

        case TUData::FALHA  : cout << "\nFALHA   - DATA" << endl << endl;
                               break;
    }

    switch(testeB.run()){
        case TUPercentual::SUCESSO: cout << "\nSUCESSO - PERCENTUAL" << endl ;
                                break;

        case TUPercentual::FALHA  : cout << "\nFALHA   - PERCENTUAL" << endl << endl;
                               break;
    }



    return 0;


}
