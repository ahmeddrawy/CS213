#include "DNA.h"

using namespace std;
DNA :: DNA () {
    this->type = promoter ;
}
DNA :: DNA (char * seq , DNA_Type atype ) : Sequence(seq) {
    this->type = atype;
    startIndex = 0;
    endIndex = len - 1;
}
DNA :: DNA(const DNA & rhs ){
    this->seq = rhs.seq;
   /// this->complementary_strand = new DNA(rhs.complementary_strand)    ;/// want to check this again
    this->endIndex =rhs.endIndex ;
    this->startIndex = rhs.startIndex;
    this->type = rhs.type;
   /// this->BuildComplementaryStrand();
}
void DNA:: Print(){
    cout<<"TYPE : "<<this->type <<'\n';
    cout<<"strand  : "<<this->seq <<'\n';
    cout<<"start index : " <<this->startIndex <<" - end index : "<<this->endIndex<<'\n';
}
void DNA::setStartIndex(int idx)
{
    startIndex = idx;
}
void DNA::setEndIndex(int idx)
{
    endIndex = idx;
}
int DNA::getStartIndex() const
{
    return startIndex;
}
int DNA::getEndIndex() const
{
    return endIndex;
}

DNA :: ~DNA(){
    delete [] complementary_strand;
}
