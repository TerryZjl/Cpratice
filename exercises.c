#include<stdio.h>
#include<string.h>

#pragma pack(4)
int main()
{
	unsigned char puc[4];
	struct tagPIM              
	{
		unsigned char ucPiml;      //1
		unsigned char ucData0 : 1; //1
		unsigned char ucData1 : 2; //
		unsigned char ucData2 : 3; // 
	}*pstPimData;
	pstPimData = (struct tagPIM*)puc;
	memset(puc, 0, 4);
	pstPimData->ucPiml = 2;        //0000 0010  
	pstPimData->ucData0 = 3;       //0000 0011   
	pstPimData->ucData1 = 4;       //0000 0100  
	pstPimData->ucData2 = 5;       //0000 0101   
	                              
	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);  
	system("pause");
	return 0;
}
