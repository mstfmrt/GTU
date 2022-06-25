/*Mustafa Mert - 200104004006*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void find_best_correction(char* word, FILE** dict){
	char matches[3][100];
	char temp[100];
	int letter_error,i,j=0;
	while(!feof(*dict)){/*looking for all words until the end of file to find a match*/
		temp[0] = '\0';
		fscanf(*dict,"%s",temp);
		if(strlen(temp)==strlen(word)){/*first checking the lenghts if equal continue to is this word best correction*/
			if(strcmp(temp,word)==0)/*if it is exact match with the word then dont need to correct it*/
				break;
			letter_error=0;
			for(i=0;i<strlen(word);i++){
				if(temp[i]!=word[i]){
					letter_error++;
					if(letter_error>1)/*if letter error more than 1 break the loop then continue with next word*/
						break;
				}	
			}
			if(letter_error==1 && j<3){/*if letter error is 1 and this correction is one of the first three match save it*/
				strcpy(matches[j],temp);
				j++;
			}
		}

	}
	rewind(*dict);/*setting cursor to the start*/
	if(strcmp(temp,word)!=0){/*if there is exact match loop will break then temp will stay as it. In this line checking for that*/
		switch(j){/*according to number of matches I returned the one which comes fitst in a regular dictionary*/
			case 1:
				strcpy(word,matches[0]);
				break;
			case 2:
				if(strcmp(matches[0],matches[1])>0)
					strcpy(word,matches[1]);
				else 
					strcpy(word,matches[0]);
				break;
			case 3:
				if(strcmp(matches[0],matches[1])>0)
					if(strcmp(matches[1],matches[2])>0)
						strcpy(word,matches[2]);
					else
						strcpy(word,matches[1]);
				else
					if(strcmp(matches[0],matches[2])>0)
						strcpy(word,matches[2]);
					else
						strcpy(word,matches[0]);
				break;	
		}
	}
}



void fix_spelling_errors(char* textfile, char* dictfile){
	char word[100], ch, free[100];
	bool is_Capital[100];/*bool variable array for detecting letters of word sent is capital or not*/
	int i;
	long int end_of_file;

	FILE* text = fopen(textfile, "r+");/*openning text and dictionary file with strings given in function parameter*/
	FILE* dict = fopen(dictfile, "r");
	fseek(text,0, SEEK_END);/*setting files cursor to the end*/
	end_of_file =ftell(text);/*detecting end of file position*/
	rewind(text);/*setting file cursor to the start*/
	while(end_of_file >ftell(text)){/*checking cursor position and reading until the end of file*/
		i=0;
		word[0] = '\0';/*making empty word*/
		do{
			ch = (char)fgetc(text);
			if(ch>64 && ch<91 || ch>96 && ch<123){/*only reading letters*/
				if (ch<96){/*checking if letter capital or not*/
					is_Capital[i]=true;
					ch+=32;	/*making lower case*/	
				}
				else
					is_Capital[i]=false;		
				word[i] = ch;/*saving character to the word*/
				i++;
			}
		}while(ch>64 && ch<91 || ch>96 && ch<123);/*reading until a non letter character*/
		word[i] = '\0';/*indicating end of word*/
		find_best_correction(word, &dict);/*sending readed word to find best correction*/
		/*find_best_correction function is changing word string with true match*/
		for(i=0;i<strlen(word);i++){
			if(is_Capital[i])
				word[i]-=32;
		}
		fseek(text, (-1*strlen(word))-1, SEEK_CUR);/*setting cursor start of the word*/
		fprintf(text, "%s", word);/*printing over the misspelled word*/
		fseek(text, 1, SEEK_CUR);/*setting cursor to the right position*/
	}
	fclose(text);/*closing text and dictionry files*/
	fclose(dict);
}

int main(int argc, char const *argv[])
{
	
	fix_spelling_errors("text.txt", "dictionary.txt");/*calling the function with file names*/
	

	
	return 0;
}