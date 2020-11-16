#include<fstream> 
#include<iostream>
#include<cstring>
#include<string>
#include<map> 
#include<vector>
using namespace std;
 void set(int**&floyd,string beginWord, string endWord, vector<string>& wordList)
    {
        int i,j,count=0;
        floyd[0][0]=0;
        for(i=0;i<wordList.size();i++)
        {
            count=0;
           for(j=0;j<wordList[i].size();j++)
           {
               if(beginWord[j]!=wordList[i][j])
                count++;
           }
           cout<<count<<endl;
           if(count==1)
                {
                floyd[0][i+1]=1;
                floyd[i+1][0]=1;
                }
            else 
                 {
                floyd[0][i+1]=100;
                floyd[i+1][0]=100;
                }
            floyd[i+1][i+1]=0;
            for(j=i+1;j<wordList.size();j++)
            {
                count=0;
                for(int z=0;z<wordList[j].size();z++)
                {
                    if(wordList[i][z]!=wordList[j][z])
                        count++;
                }
                if(count==1)
                    {
                        floyd[i+1][j+1]=1;
                        floyd[j+1][i+1]=1;
                    }
                    else
                    {
                        floyd[i+1][j+1]=100;
                        floyd[j+1][i+1]=100;  
                    }
            }
        }
        for(i=0;i<wordList.size()+1;i++)
        {
        	for(j=0;j<wordList.size()+1;j++)
        	{
        		cout<<floyd[i][j]<<" ";
			}
			cout<<endl;
		}
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int i,j,k,aim;
        for(i=0;i<wordList.size();i++)
        {
            if(i==wordList.size()-1&&endWord!=wordList[i])
                return 0;
            if(endWord==wordList[i])
                break;
        }
        aim=i;
        int **floyd=new int*[wordList.size()+1];
        for(i=0;i<wordList.size()+1;i++)
            floyd[i]=new int[wordList.size()+1];
        set(floyd,beginWord,endWord,wordList);
        for(k=0;k<wordList.size()+1;k++)  
         for(i=0;i<wordList.size()+1;i++) 
            for(j=0;j<wordList.size()+1;j++)   
                if(floyd[i][j]>floyd[i][k]+floyd[k][j] )   
                         floyd[i][j]=floyd[i][k]+floyd[k][j];  
        return floyd[0][aim+1];
    }
int main()
{
	string beginWord = "hit";
	string endWord = "cog";
	vector<string> wordList ;
	for(int i=0;i<6;i++)
	{
		cin>>endWord;
		wordList.push_back(endWord);
	}
	cout<<ladderLength(beginWord,endWord,wordList);
	return 0;
}  
