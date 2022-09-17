#ifdef __BORLANDC__
  #pragma argsused
#endif
#include <iostream.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <fstream.h>
#include <string.h>
#include <math.h>

unsigned long int  p, q;  // additional
unsigned long int e;      // public key
unsigned long int d;      // private key
unsigned long int n;      // initial key;
unsigned long int maxkey; // max length of key
unsigned long int maxadd; // max length of additional
unsigned long int maxsymbol; // max length of additional
int savestat;             // save parameter
int success;              // success of generate
int newkey;               // new key generate
int massivdel[1024];      // array of deviders
char codeext[5];          // encoded file extension
char codebext[5];         // encoded binary extension
char textext[5];          // text file extension
int defmethod;            // default encode/decode method

//-----Prototypes------------------------
inline unsigned long long int RSA_stepen(unsigned long x, unsigned long y); // too big power;
int RSA_simple(unsigned long int x);                       // simple data specification
void RSA_Deliteli(unsigned long int x);                    // specification of deviders
void RSA_Initialize_Deliteli(void);                        // initialize of keytable of deviders
void RSA_Cout_Deliteli(void);                              // console output deviders
void RSA_simple_Deliteli(unsigned long int x);             // representation data of simples
bool RSA_NOD(unsigned long int a, unsigned long int b);    // returns pairwise relatively prime numbers
void RSA_public(void);                                     // generates public key
void RSA_private(void);                                    // generates private key
void RSA_additional(void);                                 // generates additional simple numbers
void RSA_initial(void);                                    // generates initial key
void RSA_newpseudo(void);                                  // new key complex generator
void RSA_initialize(void);                                 // initializing RSA machine
int RSA_encode(int x);                                     // encode block
int RSA_decode(int x);                                     // decode block
void RSA_savecfg(int param);                               // save config
void RSA_settozero(void);                                  // setting all to zero
void RSA_esimple(unsigned char infile[],unsigned char tofile[]);     // character complex encoding
void RSA_ebinary(unsigned char infile[],unsigned char tofile[]);     // binary complex encoding
void RSA_dsimple(unsigned char infile[],unsigned char tofile[]);     // character complex decoding
void RSA_dbinary(unsigned char infile[],unsigned char tofile[]);     // binary complex decoding
//---------------------------------------

inline unsigned long long int RSA_stepen(unsigned long x, unsigned long y) // too big power
{
  unsigned long long int t;
  int i=0;
  t=x;
  const x0=x;
  for (i=0;i<(y-1);i++)
  t*=x;
  return t;
}

void RSA_Deliteli(unsigned long int x)
{
int i=0;
unsigned long int swpnum;
swpnum=x;
for(;;)
 {
 swpnum--;
 if (swpnum==1)
 break;
 if ((x%swpnum)==0)
 {
 massivdel[i]=swpnum;
 i++;
 }
 }
}

void RSA_Initialize_Deliteli(void)
{
for (int i=0; i<1024; i++)
massivdel[i]=0;
}

void RSA_Cout_Deliteli(void)
{
int i=0;
while (massivdel[i]!=0)
{
cout << massivdel[i] << " ";
i++;
}
}

void RSA_simple_Deliteli(unsigned long int x)
{
int i=0;
unsigned long int swpnum;
swpnum=2;
for(swpnum=2;swpnum<x;swpnum++)
 {
 if ((x%swpnum)==0)
 {
 x/=swpnum;
 massivdel[i]=swpnum;
 swpnum=1;
 i++;
 }
 }
massivdel[i]=x;
}

bool RSA_NOD(unsigned long int a, unsigned long int b)
{
unsigned long int k, k1, k2, con0=0;
if (a<b)
k=a;
else k=b;
for(;;)
{
con0++;
if (k!=0)
{
k1=a%k;
k2=b%k;
con0+=3;
}
if (k1==0 && k2==0)
break;
if (k1>k2)
k=k1;
else k=k2;
}
if (k==1)
return 1;
else return 0;
}

int RSA_encode(int x)
{
  unsigned long long int crypto; //64 bit
  unsigned long long int t;
  t = RSA_stepen(x,e);
  crypto=t%n;
return crypto;
}

int RSA_decode(int x)
{
  unsigned long long int decr; // 64 bit
  unsigned long long int t;
  t = RSA_stepen(x,d);
  decr=t%n;
return decr;
}

void RSA_initialize(void)
{
  char parametr[1024];
  ifstream r;
  r.open("RSA.cfg");
  if (!r)
  cout << "\n\n\tFail to initialize parameters. Program terminated.\n";
  r.getline(parametr,1024);
  r.getline(parametr,1024);
  r.getline(parametr,1024);
  r.getline(parametr,1024);
  r.getline(parametr,1024);
  r.getline(parametr,1024);
  r.getline(parametr,1024);
  r >> parametr;
  while (!r.eof())
  {
  if (strcmp(parametr,"PUBLIC_KEY")==0)
  r >> e;
  else if (strcmp(parametr,"INITIAL_KEY")==0)
  r >> n;
  else if (strcmp(parametr,"PRIVATE_KEY")==0)
  r >> d;
  else if (strcmp(parametr,"ADDITIONAL_1")==0)
  r >> p;
  else if (strcmp(parametr,"ADDITIONAL_2")==0)
  r >> q;
  else if (strcmp(parametr,"MAX_KEY")==0)
  r >> maxkey;
  else if (strcmp(parametr,"MAX_ADD")==0)
  r >> maxadd;
  else if (strcmp(parametr,"MAX_SYMB")==0)
  r >> maxsymbol;
  else if (strcmp(parametr,"NEW_KEY")==0)
  r >> newkey;
  else if (strcmp(parametr,"SAVE_STAT")==0)
  r >> savestat;
  else if (strcmp(parametr,"DEF_METHOD")==0)
  r >> defmethod;
  else if (strcmp(parametr,"TXT_EXT")==0)
  r >> textext;
  else if (strcmp(parametr,"EN_EXT")==0)
  r >> codeext;
  else if (strcmp(parametr,"ENB_EXT")==0)
  r >> codebext;
  if (!r.eof())
  r >> parametr;
  }
  r.close();
}

inline int RSA_simple(unsigned long int nums)
{
  int delitel=0;
  unsigned long int swpnum;
  swpnum=nums;
  while (swpnum!=2)
  {
    swpnum--;
    if (nums%swpnum==0)
    delitel++;
  }
  if (delitel>0)
  return 1;
  else return 0;
}

void RSA_additional(void)
{
    int t=0,t1=0,t2=0,kstat=0;
    randomize();
    p=random(maxadd)+3;
    q=random(maxadd)+3;
    for(;;)
    {
    p=random(maxadd)+3;
    q=random(maxadd)+3;
    t=(RSA_simple((q-1)*(p-1)));
    t1=(RSA_simple(q));
    t2=(RSA_simple(p));
    if (t1==0 && t2==0 && t==1)
    break;
    }
}

void RSA_initial(void)
{
  n=q*p;
}

void RSA_private(void)
{
  randomize();
  d=maxkey;
  unsigned long int n0;
  n0=(n-1)*(q-1);
  d=maxkey;
  while (success!=0)
  {
  bool kstat=0;
  d--;
  kstat=RSA_NOD(d,n0);
  if (d==2)
  break;
  while (kstat!=1)
  {
  if (d==2)
  break;
  d--;
  kstat=RSA_NOD(d,n0);
  }
  RSA_public();
  if (d==2)
  break;
  }
}

void RSA_public(void)
{
  e=maxkey;
  unsigned long int n0;
  n0=(p-1)*(q-1);
  randomize();
  for(;;)
  {
  e--;
  if (((e*d)%(n0))==1)
  {
  success=0;
  break;
  }
  if (e==2)
  break;
  }
}

void RSA_newpseudo(void)
{
  int t;
  unsigned long int try0=0;
  cout << "Please wait while generating code table...\\";
  randomize();
  while (success!=0)
  {
  try0++;
  int rnd0=0;
  rnd0=random(3);
  if (rnd0==0)
  cout << "\b\\";// << try0;
  else if (rnd0==1)
  cout << "\b\|";// << try0;
  else cout << "\b\/";// << try0;
  RSA_additional();
  RSA_initial();
  RSA_private();
    if (maxsymbol>n)
    success=2;
    if (e==d)
    success=2;
//    if ((q==3 && p==11) || (q==11 && p==3))
//    success=2;
  }
  cout << "\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b";
  cout << "\np=" << p << " q=" << q << " n=" << n << " d=" << d << " e=" << e << endl;
}
void RSA_savecfg(int param)
{
  ofstream w;
  w.open("RSA.cfg");
  w << "---------------------------------------------------------------------------" << endl;
  w << "//---	Do not modify this file manually!	---//" << endl;
  w << "//---	These parameters need to invoke	---//" << endl;
  w << "//---	RSA encode/decode machine.		---//" << endl;
  w << "//---	Hold this file very safe. Do not publish!	---//" << endl;
  w << "//---	TDSV RSA code machine, 2005		---//" << endl;
  w << "--------------------------------------------------------------------------" << endl;
  if (param==0)
  {
    w << "MAX_KEY\t" << maxkey << endl;
    w << "MAX_ADD\t" << maxadd << endl;
    w << "MAX_SYMB\t" << maxsymbol << endl;
    w << "PUBLIC_KEY\t" << e << endl;
    w << "INITIAL_KEY\t" << n << endl;
    w << "PRIVATE_KEY\t" << d << endl;
    w << "ADDITIONAL_1\t" << p << endl;
    w << "ADDITIONAL_2\t" << q << endl;
    w << "NEW_KEY\t" << newkey << endl;
    w << "SAVE_STAT\t" << savestat << endl;
    w << "TXT_EXT\t" << textext << endl;
    w << "EN_EXT\t\t" << codeext << endl;
    w << "ENB_EXT\t\t" << codebext << endl;
  }
  else if (param==1)
  {
    w << "MAX_KEY\t" << maxkey << endl;
    w << "MAX_ADD\t" << maxadd << endl;
    w << "MAX_SYMB\t" << maxsymbol << endl;
    w << "PUBLIC_KEY\t" << e << endl;
    w << "INITIAL_KEY\t" << n << endl;
    w << "ADDITIONAL_1\t" << p << endl;
    w << "ADDITIONAL_2\t" << q << endl;
    w << "NEW_KEY\t" << newkey << endl;
    w << "SAVE_STAT\t" << savestat << endl;
    w << "TXT_EXT\t" << textext << endl;
    w << "EN_EXT\t\t" << codeext << endl;
    w << "ENB_EXT\t\t" << codebext << endl;
  }
  else if (param==2)
  {
    w << "MAX_KEY\t" << maxkey << endl;
    w << "MAX_ADD\t" << maxadd << endl;
    w << "MAX_SYMB\t" << maxsymbol << endl;
    w << "PUBLIC_KEY\t" << e << endl;
    w << "INITIAL_KEY\t" << n << endl;
    w << "NEW_KEY\t" << newkey << endl;
    w << "SAVE_STAT\t" << savestat << endl;
    w << "TXT_EXT\t" << textext << endl;
    w << "EN_EXT\t\t" << codeext << endl;
    w << "ENB_EXT\t\t" << codebext << endl;
  }
  else if (param==3)
  {
    w << "MAX_KEY\t" << maxkey << endl;
    w << "MAX_ADD\t" << maxadd << endl;
    w << "MAX_SYMB\t" << maxsymbol << endl;
    w << "PUBLIC_KEY\t" << e << endl;
    w << "NEW_KEY\t" << newkey << endl;
    w << "SAVE_STAT\t" << savestat << endl;
    w << "TXT_EXT\t" << textext << endl;
    w << "EN_EXT\t\t" << codeext << endl;
    w << "ENB_EXT\t\t" << codebext << endl;
  }
  else if (param==4)
  {
  w << "MAX_KEY\t" << maxkey << endl;
  w << "MAX_ADD\t" << maxadd << endl;
  w << "MAX_SYMB\t" << maxsymbol << endl;
  w << "NEW_KEY\t" << newkey << endl;
  w << "SAVE_STAT\t" << savestat << endl;
  w << "DEF_METHOD\t" << defmethod << endl;
  w << "TXT_EXT\t" << textext << endl;
  w << "EN_EXT\t\t" << codeext << endl;
  w << "ENB_EXT\t\t" << codebext << endl;
  }
  w.close();
}

void RSA_settozero(void)
{
    success=2;
    p=0;
    q=0;
    d=0;
    e=0;
    n=0;
    RSA_Initialize_Deliteli();
}

void RSA_esimple(unsigned char infile[],unsigned char tofile[])
{
  char temp;
  int zt=0,x=0;
  ifstream r;
  ofstream w;
  r.open(infile);
  if (!r)
  {
    cout << "\nFile not exist\nProgram terminated\n";
    exit(0);
  }
  w.open(tofile);
  if (!w)
  {
    cout << "\nError creation file\nProgram terminated\n";
    exit(0);
  }
  r.get(temp);
  while(!r.eof())
  {
    zt=temp;
    if (zt<0)
    zt=abs(zt)+127;
    x=RSA_encode(zt);
    w << x << " ";
    r.get(temp);
  }
  r.close();
  w.close();
}

void RSA_ebinary(unsigned char infile[],unsigned char tofile[])
{
  char temp;
  int zt=0,x=0;
  ifstream r;
  ofstream w;
  r.open(infile);
  if (!r)
  {
    cout << "\nFile not exist\nProgram terminated\n";
    exit(0);
  }
  w.open(tofile,ios::binary);
  if (!w)
  {
    cout << "\nError creation file\nProgram terminated\n";
    exit(0);
  }
  r.get(temp);
  while(!r.eof())
  {
    zt=temp;
    if (zt<0)
    zt=abs(zt)+127;
    x=RSA_encode(zt);
    w.write((char*)&x,sizeof(x));
  }
  r.close();
  w.close();
}

void RSA_dsimple(unsigned char infile[],unsigned char tofile[])
{
  char temp;
  int zt=0,x=0;
  ifstream r;
  ofstream w;
  r.open(infile);
  if (!r)
  {
    cout << "\nFile not exist\nProgram terminated\n";
    exit(0);
  }
  w.open(tofile);
  if (!w)
  {
    cout << "\nError creation file\nProgram terminated\n";
    exit(0);
  }
  r >> zt;
  while(!r.eof())
  {
    x=RSA_decode(zt);
    w << x << " ";
    r >> zt;
  }
  r.close();
  w.close();
}

void RSA_dbinary(unsigned char infile[],unsigned char tofile[])
{
  char temp;
  int zt=0,x=0;
  ifstream r;
  ofstream w;
  r.open(infile);
  if (!r)
  {
    cout << "\nFile not exist\nProgram terminated\n";
    exit(0);
  }
  w.open(tofile);
  if (!w)
  {
    cout << "\nError creation file\nProgram terminated\n";
    exit(0);
  }
  r.read((char*)&zt,sizeof(zt));
  while(!r.eof())
  {
  x=RSA_decode(zt);
  w << x << " ";
  r.read((char*)&zt,sizeof(zt));
  }
  r.close();
  w.close();
}

void RSA_changestat(int x)
{
  if (x<5 && x>=0)
  savestat=x;
}

void RSA_newkey(void)
{
  if (newkey==1)
  newkey=0;
  else newkey=1;
}

void RSA_admin(void)
{
  int z; char buf;
  cout << "\tDO NOT CHANGE ANYTHING IF YOU DON'T FEEL SURE THAT YOU DOING IS RIGHT\n\tRead before using admin tools -man. If you want to continue, press Y ";
  buf=getch();
  if (buf=='y' || buf=='Y')
  {
    cout << "\n\nMax length of key (number). Current: " << maxkey; cin >> maxkey;
    cout << "\nMax length of additional (number). Current: " << maxadd; cin >> maxadd;
    cout << "\nMax symbols in alphabeet (number). Current: " << maxsymbol; cin >> maxsymbol;
    cout << "\nGenerate new key on startup? Current: " << newkey; cin >> newkey;
    cout << "\nSave parameters. Current: " << savestat; cin >> savestat;
    cout << "\nDefault text extension. Current: " << textext; cin >> textext;
    cout << "\nDefault code extension. Current: " << codeext; cin >> codeext;
    cout << "\nDefault code binary extension. Current: " << codebext; cin >> codebext;
    cout << "\nDefault mathod. Current: " << defmethod; cin >> defmethod;
    cout << "\n\nAll parameters set\n";
    RSA_savecfg(savestat);
    getch();
  }
  else exit(0);
}

void RSA_man(void)
{
  cout << "\nRead this very closely...";
  cout << "\n\nRSA algorythm: p, q - additional prime numbers, in cfg - ADDITIONAL_1 and ADDITIONAL_2";
  cout << "\nn - initial key (n=q*p), in cfg - INITAIL_KEY";
  cout << "\nd - private key for decode, d and (q-1)*(p-1) are pairwise relatively prime numbers, in cfg - PRIVATE_KEY";
  cout << "\ne - public key for encode, (e*d) mod (q-1)*(p-1)=1, in cfg - PUBLIC_KEY";
  cout << "\nc=x^e mod n - encoded symbol, and x=c^d mod n - decoded symbol";
  cout << "\n\nConfiguration file:";
  cout << "\nMAX_KEY: maximum key length (number), using for time-calculating control";
  cout << "\nMAX_ADD: maximum additional length (number), using for time-calculating control";
  cout << "\nMAX_SYMBOL: maximum length of alphabeet (number), using for time-calculating control";
  cout << "\nMAX_KEY: maximum key length (number), using for time-calculating control";
  cout << "\nNEW_KEY: tells to machine generate new keys (1 == TRUE, 0 == FALSE)";
  cout << "\nSAVE_STAT: save parameters - 0 - full, 1 - without private, 2 - without additional, 3 - without initial, 4 - only cfg";
  cout << "\nTXT_EXT: default textfile extension";
  cout << "\nEN_EXT: default encode/decode extension";
  cout << "\nENB_EXT: default encode/decode binary extension";
  cout << "\nDEF_METHOD: default encode/decode method - 0 - user select, 1 - text, 2 - binary";
  getch();
}

void RSA_help(void)
{
  cout << "-help\t\t\tcurrent screen";
  cout << "-n\t\t\tnew key generate (on/off)";
  cout << "-s [status]\t\t\tchange sve mode";
  cout << "-man\t\t\tadmin manual";
  cout << "-v\t\t\tcurrent version and authors";
  cout << "-admin\tadmin preferances";
  cout << "-e [input file] [outputfile]\t\tencode:";
  cout << "-eb [input file] [outputfile]\t\tninary encode:";
  cout << "-d [input file] [outputfile]\t\tdecode:";
  cout << "-db [input file] [outputfile]\t\tninary decode:";
  getch();
}

void RSA_version(void)
{
  cout << "\t\t\tTDSV RSA encode/decode machine\n\nVersion 0.3 alpha\tBuilt 8\n\nProgramm written in Borland BuilderX by Vereshchagin Iliya, TDSV, 2005";
}

int main( int argc, char argv[1024])
{
  RSA_settozero();
  RSA_initialize();
  cout << argv;
  if (argv[0]!='\-');
  exit(0);
  if (newkey==1)
  RSA_newpseudo();
  RSA_savecfg(savestat);
  getch();
  return 0;
}
