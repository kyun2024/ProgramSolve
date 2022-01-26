#include <iostream>
#include <bitset>
#include <iomanip>

using namespace std;

int mem[32];
int pc;
int a;
int power;

void STA(int x){ mem[x]=a; }
void LDA(int x){ a=mem[x]; }
void BEQ(int x){ if(!a)pc = x-1; }
void NOP(int x){ return; }
void DEC(int x){ a=(a+255)%256; }
void INC(int x){ a=(a+1)%256; }
void JMP(int x){ pc = x; }
void HLT(int x){ power = 0; }

void (*JMP_TABLE[])(int x) = {STA, LDA, BEQ, NOP, DEC, INC, JMP, HLT};

int main()
{
    int i,j,t;
    //init
    while (1)
    {
        pc = a = 0;
        power = 1;
        fill_n(mem,32,0);
        for(i=0;i<32;i++)
        {
            j=8; 
            while(j--){
                if(scanf("%1d",&t) == EOF)exit(0);
                mem[i] = (mem[i]<<1)+t;
            }
            
        }
        while(power){
            int inst = mem[pc];
            int param = inst&31;
            inst = inst>>5;
            JMP_TABLE[inst](param);
            if(inst!=6)pc=(pc+1)%32;
        }
        printf("%s\n",bitset<8>(a).to_string().c_str());
    }
    return 0;
}

