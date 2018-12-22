#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <stdio.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char * argv[])
{

	int n = 3;
	ofstream ofile;
	ofile.open("answer");
	pid_t myp[30];
	int plen = 6;
	
	
	for(int i = 0; i < argc; i++)
	{
		if(!(strcmp(argv[i], "-n")))
		{
			n = atoi(argv[i + 1]);
		}
	}
	
	

	}
	
		for(int i = 0; i < 10; i++)
	{
		myp[i] = 0;
	}
	
	int piece = 26/n;
	char terminator = 'a';
	char starter = 'a';
	int i = 0;
	int count  = 0;
	int status;
	

	myp[0] = fork();
	
	while((i < n) && myp[i])
	{
		i++;
		myp[i] = fork();
		starter += piece;
	}
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
	else
	{
		string ans;
		string key = "aaaaa";
		char newk = 'b';
		string salt = "DBK.RShu1G54Y";
		size_t pos = 6;
		size_t pos2 = 5;
		size_t pos3 = 4;
		size_t pos4 = 3;
		size_t pos5 = 2;
		size_t pos6 = 1;
		size_t pos7 = 0;
		size_t len = 1;
		char insert = 'a';
		char insert2 = 'a';
		char insert3 = 'a';
		char insert4 = 'a';
		char insert5 = 'a';
		char insert6 = 'a';
		char insert7 = 'a';
		char newi = 'b';
		bool found = false;
		
		terminator = starter + piece;
		if(terminator > 'z')
		{
			terminator = 'z';
		}
		
		
		if(plen == 7)
		{
			insert = 'a';
			insert2 = 'a';
			insert3 = 'a';
			insert4 = 'a';
			insert5 = 'a';
			insert6 = 'a';
			insert7 = starter;
			while(insert7 <= terminator && !found)
			{
				key.replace(pos7, len, len, insert7);		
				while(insert6 <= 'z' && !found)
				{
					key.replace(pos6, len, len, insert6);		
					while(insert5 <= 'z' && !found)
					{
						key.replace(pos5, len, len, insert5);		
						while(insert4 <= 'z' && !found)
						{
							key.replace(pos4, len, len, insert4);
							while(insert3 <= 'z' && !found)
							{
								key.replace(pos3, len, len, insert3);
								while(insert2 <= 'z' && !found)
								{
									key.replace(pos2, len, len, insert2);
									ans = crypt(key.c_str(),salt.c_str()); 
									while(insert <= 'z' && !found)
									{
										key.replace(pos, len, len, insert);
										ans = crypt(key.c_str(),salt.c_str()); 
										if(ans == salt)
										{
											ofile << "found: " << ans << " with key " << key << endl;
											found = true;
										}
										insert += 1;
									}
									insert = 'a';
									insert2 = insert2 + 1;
								}
								insert = 'a';
								insert2  = 'a';
								insert3 = insert3 + 1;
							}
							insert = 'a';
							insert2  = 'a';
							insert3 = 'a';
							insert4 = insert4 + 1;
						}
						insert = 'a';
						insert2  = 'a';
						insert3 = 'a';
						insert4 = 'a';
						insert5 = insert5 + 1;
					}
					insert = 'a';
					insert2  = 'a';
					insert3 = 'a';
					insert4 = 'a';
					insert5 = 'a';
					insert6 = insert6 + 1;
				}
		}
		
		
		if(plen == 6)
		{
			pos = 5;
			pos2 = 4;
			pos3 = 3;
			pos4 = 2;
			pos5 = 1;
			pos6 = 0;
			
			insert = 'a';
			insert2 = 'a';
			insert3 = 'a';
			insert4 = 'a';
			insert5 = 'a';
			insert6 = starter;
			while(insert6 <= terminator && !found)
			{
				key.replace(pos6, len, len, insert6);		
				while(insert5 <= 'z' && !found)
				{
					key.replace(pos5, len, len, insert5);		
					while(insert4 <= 'z' && !found)
					{
						key.replace(pos4, len, len, insert4);
						while(insert3 <= 'z' && !found)
						{
							key.replace(pos3, len, len, insert3);
							while(insert2 <= 'z' && !found)
							{
								key.replace(pos2, len, len, insert2);
								ans = crypt(key.c_str(),salt.c_str()); 
								while(insert <= 'z' && !found)
								{
									key.replace(pos, len, len, insert);
									ans = crypt(key.c_str(),salt.c_str()); 
									if(ans == salt)
									{
										ofile << "found: " << ans << " with key " << key << endl;
										found = true;
									}
									insert += 1;
								}
								insert = 'a';
								insert2 = insert2 + 1;
							}
							insert = 'a';
							insert2  = 'a';
							insert3 = insert3 + 1;
						}
						insert = 'a';
						insert2  = 'a';
						insert3 = 'a';
						insert4 = insert4 + 1;
					}
					insert = 'a';
					insert2  = 'a';
					insert3 = 'a';
					insert4 = 'a';
					insert5 = insert5 + 1;
				}
				insert = 'a';
				insert2  = 'a';
				insert3 = 'a';
				insert4 = 'a';
				insert5 = 'a';
				insert6 = insert6 + 1;
			}
		}

		
		
		if(plen == 5)
		{		
	
		pos = 4;
		pos2 = 3;
		pos3 = 2;
		pos4 = 1;
		pos5 = 0;
	
	
			while(insert5 <= terminator && !found)
			{
				key.replace(pos5, len, len, insert5);		
				while(insert4 <= 'z' && !found)
				{
					key.replace(pos4, len, len, insert4);
					while(insert3 <= 'z' && !found)
					{
						key.replace(pos3, len, len, insert3);
						while(insert2 <= 'z' && !found)
						{
							key.replace(pos2, len, len, insert2);
							ans = crypt(key.c_str(),salt.c_str()); 
							while(insert <= 'z' && !found)
							{
								key.replace(pos, len, len, insert);
								ans = crypt(key.c_str(),salt.c_str()); 
								if(ans == salt)
								{
									ofile << "found: " << ans << " with key " << key << endl;
									found = true;
								}
								insert += 1;
							}
							insert = 'a';
							insert2 = insert2 + 1;
						}
						insert = 'a';
						insert2  = 'a';
						insert3 = insert3 + 1;
					}
					insert = 'a';
					insert2  = 'a';
					insert3 = 'a';
					insert4 = insert4 + 1;
				}
				insert = 'a';
				insert2  = 'a';
				insert3 = 'a';
				insert4 = 'a';
				insert5 = insert5 + 1;
			}
		}
		
		
		
		if(plen == 4)
		{	
			pos = 3;
			pos2 = 2;
			pos3 = 1;
			pos4 = 0;
			while(insert4 <= terminator && !found)
			{
				key.replace(pos4, len, len, insert4);
				while(insert3 <= 'z' && !found)
				{
					key.replace(pos3, len, len, insert3);
					while(insert2 <= 'z' && !found)
					{
						key.replace(pos2, len, len, insert2);
						ans = crypt(key.c_str(),salt.c_str()); 
						while(insert <= 'z' && !found)
						{
							key.replace(pos, len, len, insert);
							ans = crypt(key.c_str(),salt.c_str()); 
							if(ans == salt)
							{
								ofile << "found: " << ans << " with key " << key << endl;
								found = true;
							}
							insert += 1;
						}
						insert = 'a';
						insert2 = insert2 + 1;
					}
					insert = 'a';
					insert2  = 'a';
					insert3 = insert3 + 1;
				}
				insert = 'a';
				insert2  = 'a';
				insert3 = 'a';
				insert4 = insert4 + 1;
			}
		}
		
		
		
		
		
		if(found)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	
	
	
	


	
	return 0;
}
