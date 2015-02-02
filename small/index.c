#include <stdio.h>
#include <glib.h>

//GHashTable* hash="";


//void looking_hash(char  *oneword,int i);


main()
{	
//	hash = g_hash_table_new(g_str_hash, g_str_equal);
	GSList* list = g_slist_append(NULL, "START\n");

	FILE *fp1,*fp2;
	char name[20],*oneword,tmp[10];
	char c;
	int i;
	
	fp2=fopen("output.txt","w");
	
	for(i=3;i<=5;i++)
	{
		sprintf(name,"data/file%d.txt",i);//แทน 1 ด้วย i	
		if(!(fp1 = fopen(name,"r"))){
			break;
		}else;
		
		do {
			oneword= g_malloc(sizeof(char)*32);
			c = fscanf(fp1,"%32[A-Za-z]",oneword);	// got one word from the file	//
			if(c == EOF)break;
			
			int i;
			for( i= 0; oneword[i]; i++){
  				oneword[i] = tolower(oneword[i]);
			}
			if(g_slist_find_custom (list,oneword,(GCompareFunc)g_strcmp0)!=NULL)continue;
			fprintf(fp2,"%s\n",oneword);
			list = g_slist_insert_sorted(list,oneword,(GCompareFunc)g_strcmp0);
			
//			looking_hash(oneword,i);

			c = fscanf(fp1,"%32[^A-Za-z]",tmp);	// move cursor in file		//
		} while (1);							// repeat until EOF		//
		
		fclose(fp1);
	}
	list = g_slist_append(list, "\nEND\n");
	g_slist_foreach (list,(GFunc)printf,"\n");

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

