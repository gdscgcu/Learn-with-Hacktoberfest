
#include <iostream>
using namespace std;
int * S2ndorder(int  a[] , int len);
int * T3rdorder(int  a[] , int len);
int * F4thorder(int  a[] , int len);
int  * input_array(int * sz ){
      int size=0;
    int * func;
    int i=0;
    cout<<"Enter Size of funtions array :";
cin>>size;
func = new int[size];

    
  



    
    while(i<size){
       cin>>func[i];
       i++;
    }
    *sz=size;
   return func; 
}
int * F1storder(int  a[] , int len){
    
    int * FstCal;
    FstCal = new int[len-1];

      cout<<"\n*** -1st Order***<<\n";
    for(int i=0;i<len-1;i++){
        FstCal[i]=a[i+1]-a[i];
        cout<<a[i+1]<<"break"<<a[i]<<"\n";
        cout<<"Performed oper :"<<a[i+1]-a[i]<<endl;
    }
    S2ndorder(FstCal, len-1);
    
    return 0;
}

int * S2ndorder(int  a[] , int len){
    
    int * FstCal;
    FstCal = new int[len-1];
   
    cout<<"\n***-2nd Order***<<\n";
    for(int i=0;i<len-1;i++){
        FstCal[i]=a[i+1]-a[i];
        cout<<a[i+1]<<"break"<<a[i]<<"\n";
        cout<<"Performed oper :"<<a[i+1]-a[i]<<endl;
    }
    
        T3rdorder(FstCal, len-1);
    
    return 0;
}

int * T3rdorder(int  a[] , int len){
    
    int * FstCal;
    FstCal = new int[len-1];
   
    cout<<"\n***-3rd Order***<<\n";
    for(int i=0;i<len-1;i++){
        FstCal[i]=a[i+1]-a[i];
        cout<<a[i+1]<<"break"<<a[i]<<"\n";
        cout<<"Performed oper :"<<a[i+1]-a[i]<<endl;
    }
            F4thorder(FstCal, len-1);
    
    return 0;
}



int * F4thorder(int  a[] , int len){
    
    int * FstCal;
    FstCal = new int[len-1];
   
    cout<<"\n***-4th Order***<<\n";
    for(int i=0;i<len-1;i++){
        FstCal[i]=a[i+1]-a[i];
        cout<<a[i+1]<<"break"<<a[i]<<"\n";
        cout<<"Performed oper :"<<a[i+1]-a[i]<<endl;
    }
    
    
    return 0;
}


void DiffTable(){

    int   * func;
    int sz;
    func = input_array(&sz );
    //   cout<<"\ntestst"<<sz;
    F1storder(func , sz);
 
    
}



int main() {

DiffTable();

    
    
    
}
