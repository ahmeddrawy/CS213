#ifndef RNA_H
#define RNA_H



#include "Sequence.h"
//#include "DNA.h"
#include "CodonsTable.h"
#include "Protein.h"
#include "AminoAcid.h"
#include <bits/stdc++.h>
class DNA;
using namespace std;

enum RNA_Type {mRNA, pre_mRNA, mRNA_exon, mRNA_intron};

class RNA : public Sequence
{
  	private:
        RNA_Type type;
  	public:
 	 	// constructors and destructor
        RNA();
        RNA(char *_seq, RNA_Type atype);
        RNA(const RNA& rhs);
        ~RNA();
 	 	// function to be overridden to print all the RNA information
        void Print();
 	 	// function to convert the RNA sequence into protein sequence
        // using the codonsTable object
        Protein ConvertToProtein( CodonsTable & table);
 	 	// function to convert the RNA sequence back to DNA
        DNA ConvertToDNA();
};
#endif // RNA_H
