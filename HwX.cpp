#include<iostream>          //standard library
#include<fstream>           //library for file manipulation
#include <algorithm>        //library to use sort()
#define N 999
using namespace std;


ofstream fout("output.txt");        //globally opening our file so it can be used inside our functions


void calculateMedian(int arr[], int size)       //function to calculate median 
{

int a=(size-1)/2;
    cout<<endl<<a<<endl;
    if(size%2==0){                              //check for even
        fout<<"Median: "<<(arr[a]+arr[a+1])/2.0<<endl;
    }else{
        fout<<"Median: "<<arr[a]<<endl;         //check for odd
    }

}

void calculateMode(int arr[], int size)         // function to calculate Mode
{

int Max=arr[0];                                 //Initialize Values
int tempMax=1;
int MaxOccurencces=1;
int modeValue=arr[0];

    for(int i=1; i<size; i++){                  // Cycle through all the Array and check if we have a frequency bigger than 1.
        if(arr[i]==Max){

            tempMax++;
            
        }
        else{

            if(tempMax>MaxOccurencces){          //save Bigger value if found and check for the rest.
            MaxOccurencces=tempMax;
            modeValue=Max;
            }

            tempMax=1;
            Max=arr[i];

        }
    }

    if(tempMax>MaxOccurencces){                 //Save final value and frequency

        MaxOccurencces=tempMax;
        modeValue=Max;

    }
    
    if(MaxOccurencces==1){                      // Output Message
        fout<<"Mode: None (no repeated value)"<<endl;
    }else{
        fout<<"Mode: "<<modeValue<<endl;
    }
}

int main(){

    ifstream fin;                               // Initialize file
    
    int even=0,odd=0;                           //Initialize variables
    int sum=0,sumcounter=0;
    float mean;
    int x;
    int Array[N];

    fin.open("input.txt");                      //open file "input.txt"

    if (fin.fail()){                            //just in case file was not created.
        cout<<"Error opening file."<<endl;
        return -1;
    }
    

    while(true!=fin.eof()){                     //Cycle through file and find mean odd,even and store variables in Array.
                                                
        fin>>x;
        sum=sum+x;
        Array[sumcounter]=x;

        if(x%2==0){
            even++;
        }
        else{
            odd++;
        }

        sumcounter++;

    }

    mean=sum/(float)sumcounter;   


      fout<<"Mean: "<<mean<<endl;               //Print messages and function calls for Median and Mode
      sort(Array, Array+sumcounter);
      calculateMedian(Array, sumcounter);
      calculateMode(Array, sumcounter);
      fout<<"Even count: "<<even<<endl<<"Odd count: "<<odd<<endl;


    fin.close();                                // closing our files.
    fout.close();
    return 0;

}