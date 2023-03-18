#include <iostream>
#include <cstdlib>
using namespace std;
int ReadPositiveNuber (string messages)
{
    int Number = 0;
    do {
        cout << messages << endl;
        cin >> Number;
    } while(Number <= 0);
    return Number;
}
int RandomFromTo(int From, int To){
    int RandNum = rand() % (To - From + 1) + From;
    return RandNum;
}
enum enCharType{SamallLetter = 1, CapitalLetter = 2, SpecialCharacter = 3, Digit = 4};
char CheckTypye(enCharType CharType)
{
    switch (CharType) {
        case enCharType :: SamallLetter:
            return char(RandomFromTo(97, 122));
                break;
        case enCharType :: CapitalLetter:
            return char(RandomFromTo(65, 90));
                break;
        case enCharType :: SpecialCharacter:
            return char(RandomFromTo(33, 47));
                break;
        case enCharType :: Digit:
            return char(RandomFromTo(48, 57));
                break;
    }
            return CharType;

}

string GenratWord (enCharType Chartype , short Length)
{
    string word = "";
    for (int i = 1 ; i <= Length ; i++)
    {
        word = word + CheckTypye(Chartype);
    }
    return word;
}

string GenrateKey(){
    string Key = "";
    Key = GenratWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenratWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenratWord(enCharType::CapitalLetter, 4) + "-";
    Key = Key + GenratWord(enCharType::CapitalLetter, 4) ;
    return Key;
}

void GenrateKeys(short NumberKeys) 
{
    for (int i = 1 ; i <= NumberKeys; i++) 
    {
        cout << "Key ["<< i<<"] : " << GenrateKey() << endl;
    }
}
int main()
{
    srand((unsigned)time(NULL));
    GenrateKeys(ReadPositiveNuber("Plesae Enter Positive Number"));
    return 0;
}
