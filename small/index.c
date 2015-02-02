#include <stdio.h>
#include <glib.h>

static GHashTable* hash;


//void looking_hash(char  *oneword,int i);
void readhash(char* key);

main()
{	
	hash = g_hash_table_new(g_str_hash, g_str_equal);
	GSList* list = g_slist_append(NULL, "START\n");

	FILE *fp1,*fp2;
	char name[20],*word,tmp[10];
	char c;
	int i;
	
	fp2=fopen("output.txt","w");
	
	for(i=3;i<=5;i++)
	{
		sprintf(name,"data/file%d.txt",i);//แทน 1 ด้วย i	
		if(!(fp1 = fopen(name,"r"))){
			break;
		}else;
//		g_hash_table_insert(hash,"text","black");
		g_hash_table_insert(hash,"str","boy");
		do {
			//read from file
			c = fscanf(fp1,"%32[^A-Za-z]",tmp);		//read not alphabet to move cursor
			word= g_malloc(sizeof(char)*32);		//allocate memory
			c = fscanf(fp1,"%32[A-Za-z]",word);	// got one word from the file	//
			if(c == EOF)break;
			
			//to Lower
			int j;
			for( j= 0; word[j]; j++){
  				word[j] = tolower(word[j]);
			}

			char index[4];
			if(!g_slist_find_custom (list,word,(GCompareFunc)g_strcmp0)){
				printf("not found %s \n",word);
								fprintf(fp2,"%s\n",word);
				list = g_slist_insert_sorted(list,word,(GCompareFunc)g_strcmp0);	//if word isn't found in list
				sprintf(index,":%d",i);
				g_hash_table_insert(hash,word,index);
			}else{
				


				
				char *str;
				str=g_hash_table_lookup(hash,word);

				sprintf(index,",%d",i);
				printf("found %s  %s    %c  %c\n",word,str,str[strlen(str)-1],index[strlen(index)-1]);
				if(str[strlen(str)-1]==index[strlen(index)-1])continue;
			//	strcat(str,index);
			//	printf("not in file ---------------------------------------------------%s\n",str);
			//	g_hash_table_replace(hash,word,str);
 //else word is found in list
								continue;
			}
			
			
//			looking_hash(oneword,i);
			

		} while (1);
		
		fclose(fp1);
	}
	list = g_slist_append(list, "\nEND\n");
	g_slist_foreach (list,(GFunc)readhash,NULL);
//	g_hash_table_foreach (hash,(GHFunc)readhash,NULL);
//	printf(g_hash_table_lookup (hash,"from"));
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
	void readhash(char* word){
		printf("%s",g_hash_table_lookup(hash,word));
		//printf("%s >>> %s\n",key,value );
	}

