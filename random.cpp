    #include <iostream>     
    #include <ctime>  
    #include <cstdio>  
      
    using namespace std;  
      
    int main()  
    {  
		srand(unsigned(time(0)));
        for(int i=0;i<10;i++)  
        {  
              
            int t = rand();  
            cout<<t<<endl;  
        }  
        return 0;  
    }  