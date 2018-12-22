#include <string.h>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>

using namespace std;

string END = "";
size_t SIZE = 3;
char MIN = 33;
char MAX = 126;
int CAP = 30;
string ans;

void Ripple(string &line, char hchar, char lchar);

int main(int argc, char * argv[])
{
        string line ("");
        int resp;
        //Lowest allowed character
        char lchar = MIN;
        //Highest allowed character
        char hchar = MAX;
        char charMax = MIN;
        char charMin = MAX;
        int n = 1;
        //Array to hold process IDs
        pid_t myp[50];
        ofstream ofile;

        //Set a default salt
        string salt("DBK.RShu1G54Y");

        ofile.open("Passwd.ans");

        for(int i = 1; i < argc; i++)
        {
                //Set custom size, default is 3
                if(!strcmp(argv[i], "-l"))
                {
                        i++;
                        SIZE = atoi(argv[i]) - 1;
                }

                //Set custom Salt
                if(!strcmp(argv[i], "-s"))
                {
                        i++;
                        salt = argv[i];
                }
                
                //Set custom number of processes to use
                if(!(strcmp(argv[i], "-n")))
                {
                        i++;
                        n = atoi(argv[i]);
                }
        }

        if(n > CAP)
        {
                n = 4;
        }
       for(int i = 0; i < 50; i++)
        {
                myp[i] = 0;
        }

        cout << "Set the minimum ascii value(33 - 126): ";
        cin >> resp;
        if(resp >= MIN && resp <= MAX)
        {
                lchar = resp;
                charMin = resp;
        }

        cout << "Set the maximum ascii value(33 - 126): ";
        cin >> resp;
        if((resp >= MIN && resp <= MAX) && resp > lchar)
        {
                hchar = resp;
                charMax = resp;
        }

        //Set up the range, and split it up to divide search space between processes
        int range = hchar - lchar;
        int piece = range/n;
        int i = 0;
        int count = 0;
        int status;
        hchar = lchar;
        hchar += piece;

        myp[0] = fork();
        
        //fork out all the processes and give them their search space
        while((i < n) && myp[i])
        {
                i++;
                myp[i] = fork();
                if(i % 2 == 0)
                {
                        lchar += piece;
                }
                else
                {
                        lchar += piece + 1;
                }
                hchar = lchar;
                hchar += piece;
                if(hchar <= 33)
                {
                        hchar = 126;
                }

        }
        
        //Master kill loop
        if(myp[n])
        {
                while(count < n)
                {
                        wait(&status);
                        if(WIFEXITED(status))
                        {
                                if(status != 0)
                                {
                                        for(int i = 0; i < n; i++)
                                        {
                                                kill(myp[i], 1);
                                       }
                                        break;
                                }
                                count++;
                        }
                }

        }
        
        //child process decoding loop
        else
        {
                //Create the line
                line = line + lchar;
                for(int i = 0; i <= SIZE; i++)
                {
                        line = line + charMin;
                }

                //Create the end for loop control
                END = END + hchar;
                for(int i = 0; i <= SIZE; i++)
                {
                        END = END + charMax;
                }

                char a;
                int pos = SIZE;
                string temp;
                bool found = false;

                //Until we reach a line of hchar hchar.....hchar
                while(line <= END)
                {
                        //Check if we have the password with each substring of the string we have
                        for(int i = SIZE; i >= 0; i--)
                        {
                                temp = line.substr(1, i);
                                //cout << temp << endl;
                                ans = crypt(temp.c_str(),salt.c_str());
                                if(ans == salt)
                                {
                                        ofile << "found: " << ans << " with key " << temp << endl;
                                        found = true;
                                        break;
                                }
                        }
                        if(found)
                        {
                                break;
                        }

                        if(line[pos] > hchar)
                        {
                                Ripple(line, charMax, charMin);
                        }
                        line[pos] += 1;
                }
                if(found)
                {
                        //Tell master process to kill children
                        return 1;
                }
                else
                {
                        return 0;
                }
       }

        return 0;
}

void Ripple(string &line, char hchar, char lchar)
{
        int tempos = SIZE;
        //The ripple carry adder
        while(tempos >= 0 && line[tempos] > hchar)
        {
                line[tempos] = lchar;
                line[tempos-1] += 1;
                tempos--;
        }
        return;
}



