
#include "RNA.h"
#include <bits/stdc++.h>
using namespace std;

    // constructors and destructor
    RNA::RNA()
    {
        type = mRNA;
    }
    RNA::RNA(char * _seq, RNA_Type atype) : Sequence(_seq)
    {
        type = atype;
    }
    RNA::RNA(const RNA& rhs)
    {
        seq = new char [rhs.len];
        len = rhs.len;
        strcpy(seq, rhs.seq);
        type = rhs.type;
    }
    RNA::~RNA()
    {
		seq = NULL;
        delete [] seq;
    }
    // function to be overridden to print all the RNA information
    void RNA::Print()
    {
        cout << "Sequence: ";
        for (int i = 0; i < len; i++)
        {
            cout << seq[i];
        }
        cout << endl;
        cout << "Type: " << type << endl;
    }
    // function to convert the RNA sequence into protein sequence
    // using the codonsTable object
    /**Protein RNA::ConvertToProtein(CodonsTable & table)
	{
///        if (len%3 != 0)
///            cout<< "NotMod3";   /// we have problem with the return value here
		char * AA;
		AA = new char[len/3 + 1];
		int newLen = 0;
		for (int i = 0; i < len; i+=3)
		{
		    char value[3];
            for (int j = 0; j < 3; ++j)
            {
                value[j] = seq[i + j];
            }
            AA[newLen++] = table.getAminoAcid(value);
//			for (int j = 0; j < 64; j++)
//			{
//				if(seq[i] == table.getCodon(j).value[0] && seq[i + 1] == table.getCodon(j).value[1] && seq[i + 2] == table.getCodon(j).value[2]);
//				{
//					if (table.getCodon(j).AminoAcid == 'Z')
//					{
//						Protein res(AA,newLen);
//						return res;
//					}
//					AA[newLen++] = table.getCodon(j).AminoAcid;
//				}
//			}
		}
		Protein retProtein(AA); /// Implement constructor i commented this - hanafy
                                /// undefined referenve to protein
		delete [] AA;
		return retProtein;
	}
	*/
    // function to convert the RNA sequence back to DNA
    DNA RNA::ConvertToDNA()            /// changed from char to DNA by hanafy
    {
        char *dnaS = new char[len];
        for (int i = 0; i < len; i++)
        {
            ///dnaS[i] = seq[i];
            if (seq[i] == 'u' || seq[i] == 'U'){
                dnaS[i] = 'T';
            }
        }
        DNA retDNA(dnaS ,promoter);          /// we have a problem here with the dna constructor

                                            /// i passed a type because each dna has a type
        ///DNA res(dnaS,promoter,0,len);
        ///return res.getComplementaryStrand();
        delete [] dnaS;
        ///return res.getComplementaryStrand();
       /// return retDNA.BuildComplementaryStrand(); /// why returning here the complementry strand ???
        return retDNA;
    }
