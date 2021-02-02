#include <iostream>

#include "../../DES_Round.h"
#include "../../../../../DataConverter/DataConverter.h"

#include "SBoxes.h"

void DES_Round::applySBox(string& target){
    //cout<<endl<<"[DES_Round::applySBox]:start"<<endl;
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
        int rowIndexInt = dataConverter.convertFromBinary2Decimal(rowIndex) ;
        int columnIndexInt = dataConverter.convertFromBinary2Decimal(columnIndex) ;

        //cout<<"Apply SBox on:\t"<<target.substr(i,6)<<endl;
        //cout<<"SBOX index is\t"<<SBox_index<<endl;

        //cout<<"rowIndex is\t"<<rowIndex<<"\tint:\t"<<rowIndexInt<<endl;
        //cout<<"columnIndex is\t"<<columnIndex<<"\tint:\t"<<columnIndexInt<<endl;
        int resultInt = SBoxes[SBox_index][rowIndexInt][columnIndexInt];
        //cout<< "The Result of the SBox\t" <<resultInt<<endl;
        result+=dataConverter.convertFromDecimal2Binary(resultInt).substr(4);
        //cout<<"The result after applying SBox#"<<i/6<<" is\t"<<result<<endl<<endl<<endl;
    }
    if(result.length() != 32){
        cerr << "There's error occured in \"apply SBox\" the result length isnot 48"<<endl<<"\tit is\t"<<result.length()<<endl;
        return;
    }
    //cout<<"[DES_Round::applySBox]:end"<<endl<<endl;
    target = result;    
}