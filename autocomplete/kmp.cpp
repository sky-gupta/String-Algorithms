#include <iostream>
#include <cstring>

// Fills lps[] for given pattern pat[0..M-1]
void computeLPSArray(char* pat, int M, int* h)
{
	int i=1,j=0;
  h[0]=-1;
  while(i<M){
    if(pat[j]!=pat[i]){
      h[i]=j;
      while(j>=0 && pat[i]!=pat[j]) j=h[j];
    }
    else h[i]=h[j];
    i++;
    j++;
  }
  h[M]=j;
}

// Prints occurrences of txt[] in pat[]
void KMPSearch(char* pat, char* txt)
{
	int i=0,j=0;
  int M=strlen(pat);
  int N=strlen(txt);
  int h[M+1];
  computeLPSArray(pat,M,h);
  while(i<N){
    if(pat[j]==txt[i]){
      i++;
      j++;
      if(j==M){
        printf("Found pattern at index %d \n", i-j);
        j=h[j];
      }
    }
    else{
      j=h[j];
      if(j<0){
        i++;
        j++;
      }
    }
  }
	// printf("Found pattern at index %d \n", index_where_found);
}
