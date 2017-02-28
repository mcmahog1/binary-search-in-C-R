
#include <fstream>
using std::ifstream;
#include <vector>
using std::vector;
#include <iterator>
using std::istream_iterator;
#include <algorithm>
using std::copy;
#include <R.h>
#include <Rinternals.h>

extern "C" {

void findSNP(double *x,double *y,int *n)
{

// variable declaration
int first ;
int last ;
int middle ;
int dataArraySize ;


double search1 ;
int n1 ;
vector<int> DataArray ;

//input
//1
n1 = *n ;


//2
ifstream myfile("1000Genomes_2015_10_30.sorted.snps");
copy(istream_iterator<int>(myfile),istream_iterator<int>(),back_inserter(DataArray)) ;
dataArraySize = DataArray.size() ;

//3
int i ;

//output

//loop


for(i = 0 ; i < n1 ; i++) {

//binary search
search1 = x[i] ; 
first = 0;
last = dataArraySize - 1;
middle = (first+last)/2;
 
   while (first <= last) {
      if (DataArray.at(middle) < search1)
         first = middle + 1;    
      else if (DataArray.at(middle) == search1) {
         break;
      }
      else
        last = middle - 1;
	middle = (first + last)/2;
   }

y[i] = middle + 1 ;

}


}

}
