#ifndef DES_ROUND
#define DES_ROUND
#include <string>
using namespace std;
class DES_Round
{

public:
    void xor_lists(string& target1, const string&target2);
    string expandRight(const string& target);
    void applySBox(string& target);
    void permuteRight(string& target);
    void executeRound(string& block,const string& key);
};
#endif /* DES_ROUND */