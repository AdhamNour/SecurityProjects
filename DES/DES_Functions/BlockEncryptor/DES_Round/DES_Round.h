#ifndef DES_ROUND
#define DES_ROUND
#include <string>
using namespace std;
class DES_Round
{
private:
    string expandRight(const string& target);
    void xor_lists(string& target1, const string&target2);
    void applySBox(string& target);
    void permuteRight(string& target);
public:
    void executeRound(string& block,const string& key);
};
#endif /* DES_ROUND */