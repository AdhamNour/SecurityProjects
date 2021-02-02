#ifndef GALOIS_MULTIP_HPP
#define GALOIS_MULTIP_HPP
#include <map>
#include<vector> 
using namespace std;
class GALOIS_MULTIP
{
private:
    inline static map<unsigned char,vector<unsigned char> > _galois_multip;
public:
    GALOIS_MULTIP(/* args */);
    unsigned char get(const unsigned char& i, const unsigned char&j);
};
#endif // !GALOIS_MULTIP
