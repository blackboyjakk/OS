#include <stdio.h>
#include <glib.h>

static GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);

void looking_hash(char  *oneword,int i);


main()
{
	FILE *fp1,*fp2;
	char name[64],oneword[32],temp[32];
	char c;
	int i;
	
	fp2=fopen("output.txt","w");
	
	for(i=1;i<3200;i++)
	{
		sprintf(name,"data/file%d.txt",i);	
		if(!(fp1 = fopen(name,"r"))){
			break;
		}else;
		
		do {
			c = fscanf(fp1,"%100[A-Za-z]",oneword);	// got one word from the file	//
			
			

			//fprintf(fp2,"%s\n",oneword);			// display it on the monitor	//
			looking_hash(oneword,i);

			c = fscanf(fp1,"%100[^A-Za-z]",temp);	// move cursor in file		//
		} while (c != EOF);							// repeat until EOF		//
		fclose(fp1);
	}
	fclose(fp2);
}
bool looking_hash(char* word,int i){
	char* str;
	if(g_hash_table_lookup(hash,word)=str){
		if(strlen(str)!=i){
			strcat(str,",");
			strcat(str,i);
			g_hash_table_replace(hash,word,str);
		}
	}else{
		g_hash_table_insert(hash,word,i);
	}
}

