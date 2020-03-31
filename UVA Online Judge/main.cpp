 #include <iostream>
2
3 #define endl "\n"
4
5 using namespace std;
6
7 int  main(){
8     int c,l,r,i=0;
9     cin>>c;
10     while(i<c){
11         cin>>l>>r;
12         if(l<r){
13             cout<<'<'<<endl;
14         }else if(l>r){
15             cout<<'>'<<endl;
16         }else{
17             cout<<'='<<endl;
18         }
19         i++;
20     }
21     return 0;
22 }