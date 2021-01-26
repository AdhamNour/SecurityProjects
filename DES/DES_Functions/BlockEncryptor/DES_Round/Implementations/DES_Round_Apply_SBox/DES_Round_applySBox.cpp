#include <iostream>

#include "../../DES_Round.h"
#include "../../../../../../DataConverter/DataConverter.h"

#include "SBoxes.h"

void DES_Round::applySBox(string& target){
    if(target.length() != 48){
        cerr << "There's error occured in \"apply SBox\" the target length isnot 48"<<endl;
        return;
    }
    DataConverter dataConverter;
    string result ;
    for (int i = 0; i < target.length(); i+=6)
    {
        int SBox_index = i/6;
        string rowIndex({target[i],target[i+5]});
        string columnIndex = target.substr(i+1,4);
        int resultInt = SBoxes[SBox_index][dataConverter.convertFromBinary2Decimal(rowIndex)][dataConverter.convertFromBinary2Decimal(columnIndex)];
        result+=dataConverter.convertFromDecimal2Binary(resultInt).substr(4);
    }
    if(result.length() != 32){
        cerr << "There's error occured in \"apply SBox\" the result length isnot 48"<<endl<<"\tit is\t"<<result.length()<<endl;
        return;
    }
    target = result;    
}