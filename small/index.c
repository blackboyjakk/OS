#include <stdio.h>
#include <glib.h>

//GHashTable* hash="";


//void looking_hash(char  *oneword,int i);


main()
{	//hash = g_hash_table_new(g_str_hash, g_str_equal);
	GSList* list = g_slist_append(NULL, "START\n");

	FILE *fp1,*fp2;
	char name[64],*oneword,*temp;
	char c;
	int i;
	
	fp2=fopen("output.txt","w");
	
	for(i=1;i<20;i++)
	{
		sprintf(name,"data/file%d.txt",i);//แทน 1 ด้วย i	
		if(!(fp1 = fopen(name,"r"))){
			break;
		}else;
		
		do {
			oneword= g_malloc(sizeof(char)*20);
			c = fscanf(fp1,"%32[A-Za-z]",oneword);	// got one word from the file	//
			

			fprintf(fp2,"%s\n",oneword);
			list = g_slist_append(list, oneword);
						// display it on the monitor	//
//			looking_hash(oneword,i);

			c = fscanf(fp1,"%32[^A-Za-z]",temp);	// move cursor in file		//
		} while (c != EOF);							// repeat until EOF		//
		
		fclose(fp1);
	}
	list = g_slist_append(list, "\nEND\n");
	g_slist_foreach (list,(GFunc)printf,NULL);

	fclose(fp2);
}
/*void looking_hash(char word[],int i){
	char *index;
	sprintf(index,",%c",i);
	char *str=g_hash_table_lookup(hash,word);
	if(str){
		int len = (int)strlen(str);
		if(str[len-1]!=index[1]){
			strcat(str,index);
			g_hash_table_replace(hash,word,str);
		}
	}else{
		strcat(str,index);
		g_hash_table_insert(hash,word,str);
	}
}*/

